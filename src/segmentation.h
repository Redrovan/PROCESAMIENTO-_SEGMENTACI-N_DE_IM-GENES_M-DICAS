#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <opencv2/opencv.hpp>

cv::Mat segmentarPulmones(const cv::Mat& img);
cv::Mat segmentarCorazon(const cv::Mat& img);
cv::Mat segmentarHuesos(const cv::Mat& img);

#endif
