//
// Created by Issashu Greybeard on 31.08.22.
//
#include "Solution.h"
#include "RedEyeRemover/includes/PatternManipulations.h"
#include "utils/EyePatterns.h"
#include "RedEyeRemover/includes/pixelCanvas.h"

void Solution::compute([[maybe_unused]]std::vector<PackedImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");

    //TODO Move the imgNum in a loop over images after manual control testing is done
    int imgNum = 0;
    auto* EyePatternsCanvas = new std::vector<pixelCanvas>;
    pixelCanvas Canvas(images[imgNum].resolution.width, images[imgNum].resolution.height);

    Canvas.clearCanvas();
    PatternManipulations::FillRedPattern(images, imgNum, Canvas);

    //TODO Export to separate method and logic
    for (int i = 0; i < EYE_PATTERNS_COUNT; i++){
        int32_t cols = EYE_PATTERN_COL_SIZE;
        int32_t rows = EYE_PATTERNS[i].size();
        EyePatternsCanvas->emplace_back(cols,rows);
        EyePatternsCanvas->at(i) = PatternManipulations::StringToPattern(EYE_PATTERNS[i], cols);
    }

    /*############# DEBUG PRINTS HERE ######################*/
    for (int i = 0; i < EYE_PATTERNS_COUNT; i++){
        EyePatternsCanvas->at(i).printCanvas();
        std::cout<<std::endl;
    }
    /*#####################################################*/

    delete EyePatternsCanvas;
}

void Solution::compute([[maybe_unused]]std::vector<StrideImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
    //TODO: fill solution
}