cmake_minimum_required(VERSION 3.10)
project(gui_interciclo)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets Gui Core REQUIRED)
find_package(OpenCV REQUIRED)
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

# ===========================
#   INCLUDES
# ===========================
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_BINARY_DIR}   # para ui_mainwindow.h
)

# ===========================
#   ARCHIVOS DE LA GUI
# ===========================
set(GUI_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/opencv_bridge.cpp
)

set(GUI_HEADERS
    src/mainwindow.h
    src/opencv_bridge.h
)

set(GUI_UI
    src/mainwindow.ui
)

qt5_wrap_ui(UI_HEADERS ${GUI_UI})
qt5_wrap_cpp(MOC_SOURCES ${GUI_HEADERS})

# ===========================
#   ARCHIVOS DEL PIPELINE
# ===========================
set(PIPELINE_SOURCES
    ../src/itk_loader.cpp
    ../src/preprocessing.cpp
    ../src/segmentation.cpp
    ../src/morphology.cpp
    ../src/contours.cpp
    ../src/utils.cpp
    ../src/deep_denoise.cpp
    ../src/metrics.cpp
)

# ===========================
#   EJECUTABLE FINAL
# ===========================
add_executable(gui_interciclo
    ${GUI_SOURCES}
    ${PIPELINE_SOURCES}
    ${MOC_SOURCES}
    ${UI_HEADERS}
)

target_link_libraries(gui_interciclo
    Qt5::Widgets
    Qt5::Gui
    Qt5::Core
    ${OpenCV_LIBS}
    opencv_ximgproc       
    ${ITK_LIBRARIES}
)
