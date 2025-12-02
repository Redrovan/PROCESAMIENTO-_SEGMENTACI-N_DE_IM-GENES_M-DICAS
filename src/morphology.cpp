#include "morphology.h"
using namespace cv;

Mat refinarPulmones(const Mat& img)
{
    Mat k = getStructuringElement(MORPH_ELLIPSE, Size(7,7));
    Mat out;
    morphologyEx(img, out, MORPH_OPEN, k);
    return out;
}

Mat refinarCorazon(const Mat& img)
{
    Mat k = getStructuringElement(MORPH_RECT, Size(9,9));
    Mat out;
    morphologyEx(img, out, MORPH_CLOSE, k);
    return out;
}

Mat refinarHuesos(const Mat& img)
{
    Mat k = getStructuringElement(MORPH_CROSS, Size(5,5));
    Mat out;
    dilate(img, out, k);
    return out;
}
