#include "Solution.h"
#include "RedEyeRemover.h"
#include "pixelCanvas.h"

void Solution::compute([[maybe_unused]]std::vector<PackedImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");

    /*######### SOLUTION STARTS HERE #################*/
    u_int64_t totalImages = images.size();

    for (int32_t image = 0; image < totalImages; image++){
        pixelCanvas ImagePixelCanvas(images[image].resolution.width, images[image].resolution.height);
        ImagePixelCanvas.clearCanvas();

        RedEyeRemover RER(images, ImagePixelCanvas);
        RER.SetEyePatterns();
        RER.OutlineRedAreas(image);
        RER.DetectRedEyes(image);
    }
}

void Solution::compute([[maybe_unused]]std::vector<StrideImage> &images) {
    FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
}