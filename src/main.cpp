#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>

#include "itk_loader.h"
#include "preprocessing.h"
#include "segmentation.h"
#include "morphology.h"
#include "contours.h"
#include "utils.h"
#include "deep_denoise.h"

using namespace std;
namespace fs = std::filesystem;

void crearOutput()
{
    if (!fs::exists("../output"))
        fs::create_directory("../output");
}

int main()
{
    crearOutput();

    cout << "=== PROCESANDO UNA IMAGEN SELECCIONADA ===" << endl;

    string archivo = "../data/L192/L192_FD_1_SHARP_1.CT.0002.0003.2016.01.21.18.17.57.277560.404382064.IMA";

    cout << "\nProcesando: " << archivo << endl;

    cv::Mat slice = cargarIMA_ITK(archivo);

    if (slice.empty()) {
        cout << " ERROR: imagen no cargada" << endl;
        return 1;
    }

    cout << " Imagen cargada: " << slice.cols << "x" << slice.rows << endl;
    cv::imwrite("../output/1_original.png", slice);

    auto gauss = filtroGaussian(slice);
    auto clahe = filtroCLAHE(slice);
    auto equal = filtroEqualize(slice);
    auto sobel = filtroSobel(slice);
    auto canny = filtroCanny(slice);

    // FGS = técnica avanzada Profunda
    auto fgs = aplicarFGS(slice);

    cv::imwrite("../output/2_gauss.png", gauss);
    cv::imwrite("../output/2_clahe.png", clahe);
    cv::imwrite("../output/2_equalize.png", equal);
    cv::imwrite("../output/2_sobel.png", sobel);
    cv::imwrite("../output/2_canny.png", canny);
    cv::imwrite("../output/2_fgs.png", fgs);

    // Usar FGS como base para segmentación
    cv::Mat base = fgs;

    auto sp = segmentarPulmones(base);
    auto sc = segmentarCorazon(base);
    auto sh = segmentarHuesos(base);

    cv::imwrite("../output/3_pulmones.png", sp);
    cv::imwrite("../output/3_corazon.png", sc);
    cv::imwrite("../output/3_huesos.png", sh);


    auto mp = refinarPulmones(sp);
    auto mc = refinarCorazon(sc);
    auto mh = refinarHuesos(sh);

    cv::imwrite("../output/4_pulmones_morph.png", mp);
    cv::imwrite("../output/4_corazon_morph.png", mc);
    cv::imwrite("../output/4_huesos_morph.png", mh);

    auto cp = detectarContornos(mp);
    auto cc = detectarContornos(mc);
    auto ch = detectarContornos(mh);

    cv::imwrite("../output/5_contornos_pulmones.png", cp);
    cv::imwrite("../output/5_contornos_corazon.png", cc);
    cv::imwrite("../output/5_contornos_huesos.png", ch);

    cv::Mat final_rgb;
    cv::cvtColor(slice, final_rgb, cv::COLOR_GRAY2BGR);

    dibujarContornosColor(final_rgb, mp, cv::Scalar(0,255,0));   // pulmones
    dibujarContornosColor(final_rgb, mc, cv::Scalar(0,0,255));   // corazón
    dibujarContornosColor(final_rgb, mh, cv::Scalar(255,255,0)); // huesos

    cv::imwrite("../output/6_resaltado.png", final_rgb);


    auto grad = gradienteMorfo(slice);
    cv::imwrite("../output/7_gradiente_morfologico.png", grad);

    cout << "\nProcesamiento completado." << endl;
    return 0;
}
