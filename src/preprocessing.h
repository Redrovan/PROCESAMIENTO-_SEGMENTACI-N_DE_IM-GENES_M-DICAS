#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <opencv2/opencv.hpp>

// Filtros obligatorios
cv::Mat filtroGaussian(const cv::Mat &img);
cv::Mat filtroCLAHE(const cv::Mat &img);
cv::Mat filtroEqualize(const cv::Mat &img);

// Filtros de bordes
cv::Mat filtroSobel(const cv::Mat &img);
cv::Mat filtroCanny(const cv::Mat &img);

#endif
