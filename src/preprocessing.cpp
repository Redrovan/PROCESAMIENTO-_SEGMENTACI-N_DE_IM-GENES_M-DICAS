#include "preprocessing.h"
#include <opencv2/opencv.hpp>

using namespace cv;

// Gaussian Blur
Mat filtroGaussian(const Mat &img)
{
    Mat out;
    GaussianBlur(img, out, Size(5,5), 1.2);
    return out;
}

// CLAHE
Mat filtroCLAHE(const Mat &img)
{
    Ptr<CLAHE> clahe = createCLAHE(3.0, Size(8,8));
    Mat out;
    clahe->apply(img, out);
    return out;
}

// Equalize Hist
Mat filtroEqualize(const Mat &img)
{
    Mat out;
    equalizeHist(img, out);
    return out;
}

// Sobel (bordes)
Mat filtroSobel(const Mat &img)
{
    Mat gradX, gradY, absX, absY;

    Sobel(img, gradX, CV_16S, 1, 0, 3);
    Sobel(img, gradY, CV_16S, 0, 1, 3);

    convertScaleAbs(gradX, absX);
    convertScaleAbs(gradY, absY);

    Mat grad;
    addWeighted(absX, 0.5, absY, 0.5, 0, grad);
    return grad;
}

// Canny
Mat filtroCanny(const Mat &img)
{
    Mat out;
    Canny(img, out, 80, 160);
    return out;
}
