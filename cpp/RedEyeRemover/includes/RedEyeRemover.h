//
// Created by Issashu Greybeard on 1.09.22.
//

#ifndef OCADO_TECH_REDEYEREMOVER_H
#define OCADO_TECH_REDEYEREMOVER_H

#include "Image.h"
#include "pixelCanvas.h"

class RedEyeRemover {
private:
    pixelCanvas* WorkingCanvas;
    pixelCanvas& ImagePatternCanvas;
    std::vector<PackedImage>& PixelData;
    std::vector<pixelCanvas>* EyePatternsCanvas;

public:
    RedEyeRemover() = delete;
    RedEyeRemover(std::vector<PackedImage>& ImagesPixelData, pixelCanvas& ImageWorkCanvas);
    ~RedEyeRemover();

    void SetEyePatterns();
    void PrintEyePatterns();

    void OutlineRedAreas(const int &imgID);
    void DetectRedEyes();
    void RemoveRedEye(int32_t row, int32_t col);

};


#endif //OCADO_TECH_REDEYEREMOVER_H
