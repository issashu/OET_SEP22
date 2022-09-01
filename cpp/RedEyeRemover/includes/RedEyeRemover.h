//
// Created by Issashu Greybeard on 1.09.22.
//

#ifndef OCADO_TECH_REDEYEREMOVER_H
#define OCADO_TECH_REDEYEREMOVER_H

#include "utils/Image.h"
#include "RedEyeRemover/includes/pixelCanvas.h"

class RedEyeRemover {
private:
    std::vector<PackedImage>& Image;
    pixelCanvas& ImagePatternCanvas;
    std::vector<pixelCanvas>* EyePatternsCanvas;

public:
    RedEyeRemover() = delete;
    RedEyeRemover(std::vector<PackedImage>& pic, pixelCanvas& imageCanvas);
    ~RedEyeRemover();

    void detectRedEyeAreas(const int &imgID);
    void setEyePatterns();
    void printEyePatterns();
};


#endif //OCADO_TECH_REDEYEREMOVER_H
