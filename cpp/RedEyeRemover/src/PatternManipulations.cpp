//
// Created by Issashu Greybeard on 31.08.22.
//

#include "PatternManipulations.h"
#include "pixelCanvas.h"
#include <algorithm>

void PatternManipulations::FillRedPattern(const std::vector<PackedImage> &images, const int &imgNum,
                                          pixelCanvas &Canvas) {
    int pixelID = 0;

    int32_t canvasH = Canvas.getCanvasHeight();
    int32_t canvasW = Canvas.getCanvasWidth();
    for (int i = 0; i < canvasH; i++) {
        for (int j = 0; j < canvasW; j++) {
            if (images[imgNum].pixels[pixelID++].red >= RED_TRESHOLD) {
                Canvas.setCanvasElem(i, j, RED_PIXEL);
            }
        }
    }
}

pixelCanvas PatternManipulations::StringToPattern(const EyePattern &strPattern, const int &row_width) {
    u_int32_t row_count = strPattern.size();
    pixelCanvas tmpCanvas (row_width, row_count);
    tmpCanvas.clearCanvas();
    for (int row = 0; row < row_count; row++){
        for (int col = 0; col < row_width; col++) {
            if(strPattern[row][col] != ' '){
                tmpCanvas.setCanvasElem(row, col, RED_PIXEL);
            }
        }
    }

    return tmpCanvas;
}

size_t PatternManipulations::PatternMatching(std::string const& pattOne, std::string const& pattTwo){
    size_t found = pattOne.find(pattTwo);
    return found;
}

void PatternManipulations::ClearFalsePattern(PatternLimits const& Limits, pixelCanvas& ImagePatternCanvas) {
    for(int32_t i = Limits.StartRow; i < Limits.RowLimit; i++){
        for(int32_t j = Limits.StartCol; j < Limits.ColLimit; j++){
            if(ImagePatternCanvas.getCanvas()->at(i)[j]==RED_PIXEL){
                ImagePatternCanvas.setCanvasElem(i, j, WHITESPACE);
            }
        }
    }
}

void PatternLimits::SetPatternLimits(int32_t row, int32_t col, int32_t rowlim, int32_t collim) {
    StartRow = row;
    StartCol = col;
    RowLimit = rowlim;
    ColLimit = collim;
}
