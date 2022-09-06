#include "Solution.h"
#include "RedEyeRemover.h"
#include "pixelCanvas.h"
#include <future>

static void RunRedEyeAsync(std::vector<PackedImage>* images, int32_t image){
    //No improvement on M1 pro -> still runs single threaded)
    pixelCanvas ImagePixelCanvas(images->at(image).resolution.width, images->at(image).resolution.height);
    ImagePixelCanvas.clearCanvas();

    RedEyeRemover RER(*images, ImagePixelCanvas);
    RER.SetEyePatterns();
    RER.OutlineRedAreas(image);
    RER.DetectRedEyes(image);
}

void Solution::compute([[maybe_unused]]std::vector<PackedImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");

    /*######### SOLUTION STARTS HERE #################*/
    u_int64_t totalImages = images.size();

    for (int32_t image = 0; image < totalImages; image++){
        std::async(std::launch::async, RunRedEyeAsync, &images, image);
    }
}

void Solution::compute([[maybe_unused]]std::vector<StrideImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
}