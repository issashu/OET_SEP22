cmake_minimum_required(VERSION 3.24)
project(Ocado_tech)

set(CMAKE_CXX_STANDARD 17)

include_directories(cpp)
include_directories(cpp/utils)

add_executable(Ocado_tech
        cpp/utils/CommonDefines.h
        cpp/utils/EyePatterns.h
        cpp/utils/FileParser.h
        cpp/utils/FunctionTracer.h
        cpp/utils/Image.cpp
        cpp/utils/Image.h
        cpp/utils/SolutionEvaluator.h
        cpp/main.cpp
        cpp/Solution.h
        cpp/RedEyeRemover/src/pixelCanvas.cpp cpp/RedEyeRemover/includes/pixelCanvas.h cpp/Solution.cpp cpp/RedEyeRemover/src/PatternManipulations.cpp cpp/RedEyeRemover/includes/PatternManipulations.h)
