cmake_minimum_required(VERSION 3.10)
project(ProyectoIntercicloVA)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(ProyectoIntercicloVA
    src/main.cpp
    src/itk_loader.cpp
    src/preprocessing.cpp
    src/segmentation.cpp
    src/morphology.cpp
    src/contours.cpp
    src/utils.cpp
    src/deep_denoise.cpp
    src/metrics.cpp
)

target_include_directories(ProyectoIntercicloVA PUBLIC src)

target_link_libraries(ProyectoIntercicloVA
    ${OpenCV_LIBS}
    opencv_dnn        
    ${ITK_LIBRARIES}
)
