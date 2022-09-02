//
// Created by Issashu Greybeard on 31.08.22.
//

#ifndef OCADO_TECH_PATTERNMANIPULATIONS_H
#define OCADO_TECH_PATTERNMANIPULATIONS_H

#include "Image.h"
#include "pixelCanvas.h"
#include "EyePatterns.h"

struct PatternLimits{
    int32_t StartRow {0};
    int32_t StartCol {0};
    int32_t RowLimit {0};
    int32_t ColLimit {0};

    void SetPatternLimits(int32_t row, int32_t col, int32_t rowlim, int32_t collim);
};

namespace PatternManipulations {
    void FillRedPattern(const std::vector<PackedImage> &images, const int &imgNum, pixelCanvas &Canvas);
    pixelCanvas StringToPattern(const EyePattern& strPattern, const int& row_width);
    size_t PatternMatching(std::string const& pattOne, std::string const& pattTwo);
    void ClearFalsePattern(PatternLimits const& Limits, pixelCanvas& ImagePatternCanvas);
}


#endif //OCADO_TECH_PATTERNMANIPULATIONS_H
