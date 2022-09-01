//
// Created by Issashu Greybeard on 31.08.22.
//
#include "Solution.h"
#include "RedEyeRemover.h"
#include "pixelCanvas.h"

void Solution::compute([[maybe_unused]]std::vector<PackedImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");

    //TODO Move the imgNum in a loop over images after manual control testing is done
    //TODO Make sure only one pixelCanvas is used and cleaned, reused - no time for Singletons...
    int imgNum = 0;

    pixelCanvas ImagePixelCanvas(images[imgNum].resolution.width, images[imgNum].resolution.height);
    ImagePixelCanvas.clearCanvas();

    RedEyeRemover RER(images, ImagePixelCanvas);
    RER.OutlineRedAreas(imgNum);
    RER.SetEyePatterns();
    RER.DetectRedEyes();
    //RER.CleanupRedEyes();

    /*############# DEBUG PRINTS HERE ######################*/
    //TODO Remove debug prints
    ImagePixelCanvas.printCanvas();
    RER.PrintEyePatterns();
    /*#####################################################*/
}

void Solution::compute([[maybe_unused]]std::vector<StrideImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
    //TODO: fill solution
}