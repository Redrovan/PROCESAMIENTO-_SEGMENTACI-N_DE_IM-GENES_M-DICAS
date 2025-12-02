#include "utils.h"
using namespace cv;

Mat gradienteMorfo(const Mat& img)
{
    Mat k = getStructuringElement(MORPH_ELLIPSE, Size(5,5));
    Mat out;
    morphologyEx(img, out, MORPH_GRADIENT, k);
    return out;
}
