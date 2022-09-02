//
// Created by Issashu Greybeard on 1.09.22.
//

#ifndef OCADO_TECH_REDEYEREMOVER_H
#define OCADO_TECH_REDEYEREMOVER_H

#include "Image.h"
#include "pixelCanvas.h"
#include "PatternManipulations.h"

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
    void DetectRedEyes(const int &imgID);
    void RemoveRedEye(PatternLimits const& WL, const int &imgID);

};


#endif //OCADO_TECH_REDEYEREMOVER_H
