//
// Created by Issashu Greybeard on 1.09.22.
//

#include "RedEyeRemover.h"
#include "EyePatterns.h"
#include "PatternManipulations.h"
#include <iostream>

//TODO Remove debug prints
/*######### Constructors and Destructor ########*/

RedEyeRemover::RedEyeRemover(std::vector<PackedImage> &ImagesPixelData, pixelCanvas &ImageWorkCanvas)
: PixelData(ImagesPixelData), ImagePatternCanvas(ImageWorkCanvas){
    EyePatternsCanvas = new std::vector<pixelCanvas>;
    std::cout << "RedEyeRemover created"<< std::endl;
}

RedEyeRemover::~RedEyeRemover() {
    delete EyePatternsCanvas;
    EyePatternsCanvas = nullptr;
    std::cout << "RedEyeRemover destroyed!"<< std::endl;
}

/*######### Other methods ####################*/

void RedEyeRemover::SetEyePatterns() {
    for (int i = 0; i < EYE_PATTERNS_COUNT; i++){
        int32_t cols = EYE_PATTERN_COL_SIZE;
        int32_t rows = EYE_PATTERNS[i].size();
        EyePatternsCanvas->emplace_back(cols,rows);
        EyePatternsCanvas->at(i) = PatternManipulations::StringToPattern(EYE_PATTERNS[i], cols);
    }
}

void RedEyeRemover::PrintEyePatterns() {
    for (int i = 0; i < EYE_PATTERNS_COUNT; i++){
        EyePatternsCanvas->at(i).printCanvas();
        std::cout<<std::endl;
    }
}

void RedEyeRemover::OutlineRedAreas(const int &imgID) {
    PatternManipulations::FillRedPattern(PixelData, imgID, ImagePatternCanvas);
}

void RedEyeRemover::DetectRedEyes() {
    //TODO Add a small 5x5 canvas to the class to use for snipping out patterns
    for(auto & PatternRow : *ImagePatternCanvas.getCanvas()) {
        PatternManipulations::PatternMatching(PatternRow,
                                              EyePatternsCanvas->at(0).getCanvas()->at(0));
    }
}

