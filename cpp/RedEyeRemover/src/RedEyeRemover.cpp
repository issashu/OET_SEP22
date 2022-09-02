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
: PixelData(ImagesPixelData), ImagePatternCanvas(ImageWorkCanvas) {

    WorkingCanvas = nullptr;
    EyePatternsCanvas = new std::vector<pixelCanvas>;
    std::cout << "RedEyeRemover created" << std::endl;
}

RedEyeRemover::~RedEyeRemover() {
    delete WorkingCanvas;
    delete EyePatternsCanvas;

    WorkingCanvas = nullptr;
    EyePatternsCanvas = nullptr;
    std::cout << "RedEyeRemover destroyed!" << std::endl;
}

/*######### Other methods ####################*/

void RedEyeRemover::SetEyePatterns() {
    for (int i = 0; i < EYE_PATTERNS_COUNT; i++) {
        int32_t cols = EYE_PATTERN_COL_SIZE;
        int32_t rows = EYE_PATTERNS[i].size();
        EyePatternsCanvas->emplace_back(cols, rows);
        EyePatternsCanvas->at(i) = PatternManipulations::StringToPattern(EYE_PATTERNS[i], cols);
    }
}

void RedEyeRemover::PrintEyePatterns() {
    for (int i = 0; i < EYE_PATTERNS_COUNT; i++) {
        EyePatternsCanvas->at(i).printCanvas();
        std::cout << std::endl;
    }
}

void RedEyeRemover::OutlineRedAreas(const int &imgID) {
    PatternManipulations::FillRedPattern(PixelData, imgID, ImagePatternCanvas);
}

void RedEyeRemover::DetectRedEyes() {
    //TODO Replace range based loop with traditional C style loop. Having separate counter is plain stupid and ugly
    size_t PatternStartPos = 0;
    int32_t counter = 0;
    bool isAnyPatternMatching = false;

    auto tmpCanvas = ImagePatternCanvas.getCanvas();
    auto tmpPattern = EyePatternsCanvas->begin()->getCanvas();

    for (auto element = std::begin(*tmpCanvas); element != std::end(*tmpCanvas); element++, counter++) {
        PatternStartPos = PatternManipulations::PatternMatching(*element, tmpPattern->front());

        if (PatternStartPos <= ImagePatternCanvas.getCanvasWidth()) {
        //If first pattern row is found, grab image portion and loop over the patterns, since they are small
            for (const auto &pattern: *EyePatternsCanvas) {
                int32_t PatternWidth = pattern.getCanvasWidth();
                int32_t PatternHeight = pattern.getCanvasHeight();
                WorkingCanvas = new pixelCanvas(PatternWidth, PatternHeight);

                //Copy pattern from image canvas
                for (int32_t i = 0; i < PatternHeight; i++) {
                    for (int32_t j = 0; j < PatternWidth; j++) {
                        WorkingCanvas->setCanvasElem(i,j,tmpCanvas->at(counter+i)[PatternStartPos+j]);
                    }
                }
                //Compare with pattern
                if (*WorkingCanvas == pattern) {
                    //Call RemoveredEye here
                    RemoveRedEye(counter, PatternStartPos);
                    std::cout << "Bla";
                    delete WorkingCanvas;
                    break;
                }
                delete WorkingCanvas;
            }
            //After wiping return to same row to check for potential second image
            element--;
            counter--;
        }
    }
}
// Row = counter, col = PatternPos
void RedEyeRemover::RemoveRedEye(int32_t row, int32_t col) {
    int64_t pixID = 0;
    for(int32_t i = row; i<(row+WorkingCanvas->getCanvasHeight()); i++){
        for(int32_t j = col; j<(col+WorkingCanvas->getCanvasWidth()); j++){
            if(ImagePatternCanvas.getCanvas()->at(i)[j]=='*'){
                pixID = i * ImagePatternCanvas.getCanvasWidth() + j;
                ImagePatternCanvas.setCanvasElem(i, j, '.');
                PixelData.at(0).pixels.at(pixID).red-=150;
            }
        }
    }
}
