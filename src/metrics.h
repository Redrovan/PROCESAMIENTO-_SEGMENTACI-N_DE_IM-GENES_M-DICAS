#ifndef METRICS_H
#define METRICS_H

#include <opencv2/opencv.hpp>
#include <string>

size_t obtenerUsoMemoriaRAM();
double calcularPSNR(const cv::Mat &I1, const cv::Mat &I2);
double calcularSSIM(const cv::Mat &img1, const cv::Mat &img2);
void guardarHistogramaCSV(const cv::Mat &mask, const std::string &filename);

#endif
