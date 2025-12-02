#include "opencv_bridge.h"

cv::Mat qimageToMat(const QImage &qImg)
{
    QImage img = qImg.convertToFormat(QImage::Format_RGB888);
    return cv::Mat(img.height(), img.width(),
                   CV_8UC3, (uchar*)img.bits(),
                   img.bytesPerLine()).clone();
}

QImage matToQImage(const cv::Mat &mat)
{
    cv::Mat rgb;

    if (mat.channels() == 1)
        cv::cvtColor(mat, rgb, cv::COLOR_GRAY2RGB);
    else
        cv::cvtColor(mat, rgb, cv::COLOR_BGR2RGB);

    return QImage(rgb.data, rgb.cols, rgb.rows,
                  rgb.step, QImage::Format_RGB888).copy();
}
