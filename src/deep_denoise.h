#ifndef DEEP_DENOISE_H
#define DEEP_DENOISE_H

#include <opencv2/opencv.hpp>
#include <string>

std::string buscarModeloDnCNN();
bool cargarModeloDnCNN(const std::string &onnxPath);
bool modeloDnCNNCargado();
cv::Mat aplicarDnCNN(const cv::Mat &img);
cv::Mat aplicarFGS(const cv::Mat &img);

#endif
