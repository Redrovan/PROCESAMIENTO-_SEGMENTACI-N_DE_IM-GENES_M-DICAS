#include "metrics.h"
#include <fstream>
#include <numeric>

// =============================
// RAM USAGE
// =============================
size_t obtenerUsoMemoriaRAM()
{
    std::ifstream file("/proc/self/status");
    std::string line;

    while (std::getline(file, line))
    {
        if (line.find("VmRSS:") != std::string::npos)
        {
            std::istringstream iss(line);
            std::string label, size, unit;
            iss >> label >> size >> unit;
            return std::stol(size); // KB
        }
    }
    return 0;
}

// =============================
// PSNR
// =============================
double calcularPSNR(const cv::Mat &I1, const cv::Mat &I2)
{
    cv::Mat s1;
    absdiff(I1, I2, s1);
    s1.convertTo(s1, CV_32F);
    s1 = s1.mul(s1);

    double mse = cv::sum(s1)[0] / (double)(I1.total());

    if (mse <= 1e-10) return 100;

    return 10.0 * log10((255 * 255) / mse);
}

// =============================
// SSIM
// =============================
double calcularSSIM(const cv::Mat &i1, const cv::Mat &i2)
{
    cv::Mat I1, I2;
    i1.convertTo(I1, CV_32F);
    i2.convertTo(I2, CV_32F);

    cv::Mat mu1, mu2;
    GaussianBlur(I1, mu1, cv::Size(11, 11), 1.5);
    GaussianBlur(I2, mu2, cv::Size(11, 11), 1.5);

    cv::Mat mu1_2 = mu1.mul(mu1);
    cv::Mat mu2_2 = mu2.mul(mu2);
    cv::Mat mu1_mu2 = mu1.mul(mu2);

    cv::Mat sigma1_2, sigma2_2, sigma12;
    GaussianBlur(I1.mul(I1), sigma1_2, cv::Size(11, 11), 1.5);
    GaussianBlur(I2.mul(I2), sigma2_2, cv::Size(11, 11), 1.5);
    GaussianBlur(I1.mul(I2), sigma12, cv::Size(11, 11), 1.5);

    sigma1_2 -= mu1_2;
    sigma2_2 -= mu2_2;
    sigma12 -= mu1_mu2;

    float C1 = 6.5025, C2 = 58.5225;

    cv::Mat t1 = 2 * mu1_mu2 + C1;
    cv::Mat t2 = 2 * sigma12 + C2;
    cv::Mat t3 = (mu1_2 + mu2_2 + C1);
    cv::Mat t4 = (sigma1_2 + sigma2_2 + C2);

    cv::Mat ssim_map;
    cv::divide(t1.mul(t2), t3.mul(t4), ssim_map);

    return cv::mean(ssim_map)[0];
}

// =============================
// HISTOGRAMA CSV
// =============================
void guardarHistogramaCSV(const cv::Mat &mask, const std::string &filename)
{
    std::vector<int> hist(256, 0);

    for (int r = 0; r < mask.rows; r++)
        for (int c = 0; c < mask.cols; c++)
            hist[mask.at<uchar>(r, c)]++;

    std::ofstream file(filename);
    file << "Valor,Frecuencia\n";

    for (int i = 0; i < 256; i++)
        file << i << "," << hist[i] << "\n";

    file.close();
}
