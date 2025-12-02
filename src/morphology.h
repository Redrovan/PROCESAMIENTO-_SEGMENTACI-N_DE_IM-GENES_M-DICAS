#ifndef MORPHOLOGY_H
#define MORPHOLOGY_H

#include <opencv2/opencv.hpp>

cv::Mat refinarPulmones(const cv::Mat& img);
cv::Mat refinarCorazon(const cv::Mat& img);
cv::Mat refinarHuesos(const cv::Mat& img);

#endif
