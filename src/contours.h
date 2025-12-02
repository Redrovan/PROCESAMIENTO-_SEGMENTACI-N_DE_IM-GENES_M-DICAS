#ifndef CONTOURS_H
#define CONTOURS_H

#include <opencv2/opencv.hpp>

cv::Mat detectarContornos(const cv::Mat& img);
void dibujarContornosColor(cv::Mat& destino, const cv::Mat& bin, cv::Scalar color);

#endif
