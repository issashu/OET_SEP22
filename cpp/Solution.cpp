//
// Created by Issashu Greybeard on 31.08.22.
//
#include "Solution.h"
#include "RedEyeRemover/includes/PatternManipulations.h"
#include "RedEyeRemover/includes/RedEyeRemover.h"
#include "RedEyeRemover/includes/pixelCanvas.h"

void Solution::compute([[maybe_unused]]std::vector<PackedImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");

    //TODO Move the imgNum in a loop over images after manual control testing is done
    int imgNum = 0;

    pixelCanvas Canvas(images[imgNum].resolution.width, images[imgNum].resolution.height);
    Canvas.clearCanvas();

    RedEyeRemover RER(images, Canvas);
    RER.detectRedEyeAreas(imgNum);
    RER.setEyePatterns();

    /*############# DEBUG PRINTS HERE ######################*/
    RER.printEyePatterns();
    /*#####################################################*/
}

void Solution::compute([[maybe_unused]]std::vector<StrideImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
    //TODO: fill solution
}