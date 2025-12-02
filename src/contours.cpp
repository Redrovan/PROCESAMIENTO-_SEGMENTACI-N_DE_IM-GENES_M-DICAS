#include "contours.h"

using namespace cv;
using namespace std;

Mat detectarContornos(const Mat& img)
{
    vector<vector<Point>> contornos;
    findContours(img, contornos, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    Mat salida = Mat::zeros(img.size(), CV_8UC1);
    drawContours(salida, contornos, -1, Scalar(255), 2);
    return salida;
}

void dibujarContornosColor(Mat& destino, const Mat& bin, Scalar color)
{
    vector<vector<Point>> contornos;
    findContours(bin, contornos, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    drawContours(destino, contornos, -1, color, 2);
}
