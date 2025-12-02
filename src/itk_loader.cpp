#include "itk_loader.h"

// ITK
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkGDCMImageIO.h>
#include <itkRescaleIntensityImageFilter.h>
#include <itkImageRegionConstIterator.h>

using namespace cv;

cv::Mat cargarIMA_ITK(const std::string& ruta)
{
    using PixelType = float;
    using ImageType = itk::Image<PixelType, 2>;

    auto dicomIO = itk::GDCMImageIO::New();
    auto reader  = itk::ImageFileReader<ImageType>::New();

    reader->SetImageIO(dicomIO);
    reader->SetFileName(ruta);

    try {
        reader->Update();
    }
    catch (itk::ExceptionObject &ex) {
        std::cerr << " ERROR ITK al leer " << ruta << "\n" << ex << std::endl;
        return cv::Mat();
    }

    ImageType::Pointer img = reader->GetOutput();
    auto region = img->GetBufferedRegion();
    auto size   = region.GetSize();

    int width  = size[0];
    int height = size[1];

    // Escalar valores HU → 0–255
    using UCharImageType = itk::Image<unsigned char, 2>;
    using RescaleType = itk::RescaleIntensityImageFilter<ImageType, UCharImageType>;

    auto rescaler = RescaleType::New();
    rescaler->SetInput(img);
    rescaler->SetOutputMinimum(0);
    rescaler->SetOutputMaximum(255);

    try {
        rescaler->Update();
    }
    catch (itk::ExceptionObject &ex) {
        std::cerr << " ERROR al normalizar imagen: " << ex << std::endl;
        return cv::Mat();
    }

    UCharImageType::Pointer ucharImg = rescaler->GetOutput();

    // Convertir a Mat
    cv::Mat output(height, width, CV_8UC1);

    itk::ImageRegionConstIterator<UCharImageType> it(ucharImg, ucharImg->GetBufferedRegion());

    int y = 0, x = 0;
    for (it.GoToBegin(); !it.IsAtEnd(); ++it)
    {
        output.at<unsigned char>(y, x) = it.Get();
        x++;
        if (x >= width) { x = 0; y++; }
    }

    return output;
}
