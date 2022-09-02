//
// Created by Issashu Greybeard on 31.08.22.
//

#ifndef OCADO_TECH_PATTERNMANIPULATIONS_H
#define OCADO_TECH_PATTERNMANIPULATIONS_H

#include "Image.h"
#include "pixelCanvas.h"
#include "EyePatterns.h"

namespace PatternManipulations {
    void FillRedPattern(const std::vector<PackedImage> &images, const int &imgNum, pixelCanvas &Canvas);
    pixelCanvas StringToPattern(const EyePattern& strPattern, const int& row_width);
    size_t PatternMatching(std::string const& pattOne, std::string const& pattTwo);
}


#endif //OCADO_TECH_PATTERNMANIPULATIONS_H
