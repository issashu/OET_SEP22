//
// Created by Issashu Greybeard on 1.09.22.
//

#include "RedEyeRemover/includes/RedEyeRemover.h"
#include "utils/EyePatterns.h"
#include "RedEyeRemover/includes/PatternManipulations.h"
#include <iostream>

//TODO Remove debug prints
/*######### Constructors and Destructor ########*/

RedEyeRemover::RedEyeRemover(std::vector<PackedImage> &pic, pixelCanvas &imageCanvas)
:Image(pic), ImagePatternCanvas(imageCanvas){
    EyePatternsCanvas = new std::vector<pixelCanvas>;
    std::cout << "RedEyeRemover created"<< std::endl;
}

RedEyeRemover::~RedEyeRemover() {
    delete EyePatternsCanvas;
    EyePatternsCanvas = nullptr;
    std::cout << "RedEyeRemover destroyed!"<< std::endl;
}

/*######### Other methods ####################*/

void RedEyeRemover::setEyePatterns() {
    for (int i = 0; i < EYE_PATTERNS_COUNT; i++){
        int32_t cols = EYE_PATTERN_COL_SIZE;
        int32_t rows = EYE_PATTERNS[i].size();
        EyePatternsCanvas->emplace_back(cols,rows);
        EyePatternsCanvas->at(i) = PatternManipulations::StringToPattern(EYE_PATTERNS[i], cols);
    }
}

void RedEyeRemover::printEyePatterns() {
    for (int i = 0; i < EYE_PATTERNS_COUNT; i++){
        EyePatternsCanvas->at(i).printCanvas();
        std::cout<<std::endl;
    }
}

void RedEyeRemover::detectRedEyeAreas(const int &imgID) {
    PatternManipulations::FillRedPattern(Image, imgID, ImagePatternCanvas);
}

