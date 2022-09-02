cmake_minimum_required(VERSION 3.22)
project(Ocado_test_RER VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

#Comment out before final build or before using Valgrind (CLion specific sanitizer options) or if not using Clion IDE
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize-address-use-after-scope  -fno-omit-frame-pointer -g")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g")

#Uncomment below line in order to run the Clion profiler:
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

#Uncomment below for Apple Silicon setups
#set(CMAKE_OSX_ARCHITECTURES "arm64")

#Set directories below
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cpp)
set(HEADERS_DIR ${BASE_DIR}/RedEyeRemover/includes)
set(SOURCES_DIR ${BASE_DIR}/RedEyeRemover/src)
set(UTILS_PATH ${BASE_DIR}/RedEyeRemover/utils)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
        ${PROJECT_NAME}

        ${BASE_DIR}/main.cpp
        ${BASE_DIR}/Solution.cpp
        ${BASE_DIR}/Solution.h

        ${UTILS_PATH}/CommonDefines.h
        ${UTILS_PATH}/EyePatterns.h
        ${UTILS_PATH}/FileParser.h
        ${UTILS_PATH}/FunctionTracer.h
        ${UTILS_PATH}/Image.cpp
        ${UTILS_PATH}/Image.h
        ${UTILS_PATH}/SolutionEvaluator.h

        ${SOURCES_DIR}/pixelCanvas.cpp
        ${SOURCES_DIR}/RedEyeRemover.cpp
        ${SOURCES_DIR}/PatternManipulations.cpp

        ${HEADERS_DIR}/pixelCanvas.h
        ${HEADERS_DIR}/PatternManipulations.h
        ${HEADERS_DIR}/RedEyeRemover.h
        )

target_include_directories (
        ${PROJECT_NAME}

        PUBLIC
        ${BASE_DIR}
        ${UTILS_PATH}
        ${SOURCES_DIR}
        ${HEADERS_DIR}
)