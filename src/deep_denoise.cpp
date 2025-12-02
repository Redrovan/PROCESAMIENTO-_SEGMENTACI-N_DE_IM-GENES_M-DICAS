#include "deep_denoise.h"
#include <opencv2/dnn.hpp>
#include <opencv2/ximgproc.hpp>
#include <filesystem>

using namespace cv;
namespace fs = std::filesystem;

static dnn::Net g_dncnn;
static bool g_model_loaded = false;

std::string buscarModeloDnCNN()
{
    std::vector<std::string> rutas = {
        "/home/robinson/proyecto_interciclo_cpp/models/dncnn_final.onnx",
        "/home/robinson/proyecto_interciclo_cpp/gui_qt/models/dncnn_final.onnx",
        fs::current_path().string() + "/models/dncnn_final.onnx",
        fs::current_path().string() + "/dncnn_final.onnx"
    };

    for (auto &ruta : rutas)
        if (fs::exists(ruta)) return ruta;

    return "";
}

bool cargarModeloDnCNN(const std::string &onnxPath)
{
    try {
        g_dncnn = dnn::readNetFromONNX(onnxPath);
        g_dncnn.setPreferableBackend(dnn::DNN_BACKEND_OPENCV);
        g_dncnn.setPreferableTarget(dnn::DNN_TARGET_CPU);
        g_model_loaded = true;
        return true;
    } catch (...) {
        g_model_loaded = false;
        return false;
    }
}

bool modeloDnCNNCargado() { return g_model_loaded; }

cv::Mat aplicarFGS(const cv::Mat &img)
{
    Mat img8;
    img.convertTo(img8, CV_8U);

    Mat guide;
    cvtColor(img8, guide, COLOR_GRAY2BGR);

    Mat out;
    ximgproc::fastGlobalSmootherFilter(guide, img8, out, 500, 1.5);
    return out;
}

cv::Mat aplicarDnCNN(const cv::Mat &img)
{
    if (!g_model_loaded) return img.clone();

    Mat imgFloat;
    img.convertTo(imgFloat, CV_32F, 1.0 / 255.0);

    Mat gray;
    cvtColor(imgFloat, gray, COLOR_BGR2GRAY);

    Mat blob = dnn::blobFromImage(gray);
    g_dncnn.setInput(blob);
    Mat output = g_dncnn.forward();

    Mat result(output.size[2], output.size[3], CV_32F, output.ptr<float>());
    Mat final8;
    result.convertTo(final8, CV_8U, 255.0);

    return final8.clone();
}
