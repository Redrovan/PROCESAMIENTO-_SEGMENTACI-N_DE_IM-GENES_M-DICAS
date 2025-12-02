#include "segmentation.h"
using namespace cv;

// Pulmones: < 50 (inverso)
Mat segmentarPulmones(const Mat& img)
{
    Mat bin;
    threshold(img, bin, 50, 255, THRESH_BINARY_INV);
    return bin;
}

// Corazón: > 150
Mat segmentarCorazon(const Mat& img)
{
    Mat bin;
    threshold(img, bin, 150, 255, THRESH_BINARY);
    return bin;
}

// Huesos: > 200
Mat segmentarHuesos(const Mat& img)
{
    Mat bin;
    threshold(img, bin, 200, 255, THRESH_BINARY);
    return bin;
}
