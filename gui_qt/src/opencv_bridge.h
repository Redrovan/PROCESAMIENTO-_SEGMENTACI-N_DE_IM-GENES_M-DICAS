#ifndef OPENCV_BRIDGE_H
#define OPENCV_BRIDGE_H

#include <opencv2/opencv.hpp>
#include <QImage>

cv::Mat qimageToMat(const QImage &qImg);
QImage matToQImage(const cv::Mat &mat);

#endif
