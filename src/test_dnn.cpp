#include <opencv2/dnn.hpp>
#include <iostream>

int main() {
    try {
        cv::dnn::Net net = cv::dnn::readNetFromONNX("/home/robinson/proyecto_interciclo_cpp/models/dncnn_final.onnx");

        if (net.empty()) {
            std::cout << " Net está vacío (no cargado)\n";
            return 0;
        }

        std::cout << " Modelo cargado correctamente en C++\n";
    }
    catch (const cv::Exception &e) {
        std::cout << " Excepción OpenCV:\n" << e.msg << "\n";
    }
    catch (...) {
        std::cout << " Error desconocido\n";
    }

    return 0;
}
