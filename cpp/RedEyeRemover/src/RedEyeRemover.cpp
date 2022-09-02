//
// Created by Issashu Greybeard on 1.09.22.
//

#include "RedEyeRemover.h"
#include "EyePatterns.h"
#include <iostream>

/*######### Constructors and Destructor ########*/

RedEyeRemover::RedEyeRemover(std::vector<PackedImage> &ImagesPixelData, pixelCanvas &ImageWorkCanvas)
: PixelData(ImagesPixelData), ImagePatternCanvas(ImageWorkCanvas) {

    WorkingCanvas = nullptr;
    EyePatternsCanvas = new std::vector<pixelCanvas>;
}

RedEyeRemover::~RedEyeRemover() {
    delete WorkingCanvas;
    delete EyePatternsCanvas;

    WorkingCanvas = nullptr;
    EyePatternsCanvas = nullptr;
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
        std::cout << "\n";
    }
}

void RedEyeRemover::OutlineRedAreas(const int &imgID) {
    PatternManipulations::FillRedPattern(PixelData, imgID, ImagePatternCanvas);
}

void RedEyeRemover::DetectRedEyes(const int &imgID) {
    size_t PatternStartPos = 0;
    int32_t counter = 0;
    PatternLimits WorkLimits;

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

                //Set working limitations for cleaner
                WorkLimits.SetPatternLimits(counter, PatternStartPos, counter+WorkingCanvas->getCanvasHeight(),
                                            PatternStartPos+WorkingCanvas->getCanvasWidth() );

                //Compare with pattern and remove if equal
                if (*WorkingCanvas == pattern) {
                    RemoveRedEye(WorkLimits, imgID);
                    delete WorkingCanvas;
                    WorkingCanvas= nullptr;
                    break;
                }
                delete WorkingCanvas;
                WorkingCanvas= nullptr;
            }
            PatternManipulations::ClearFalsePattern(WorkLimits, ImagePatternCanvas);

            //After wiping the pattern from the canvas return to same row to check for potential second image on same row
            element--;
            counter--;
        }
    }
}
//Row = counter, col = PatternPos
//TO GET PIXEL ID ROWS*WIDTH + J
void RedEyeRemover::RemoveRedEye(PatternLimits const& WL, const int &imgID) {
    int64_t pixID = 0;
    for(int32_t i = WL.StartRow ; i < WL.RowLimit; i++) {
        for(int32_t j = WL.StartCol; j < WL.ColLimit; j++) {
            if(ImagePatternCanvas.getCanvas()->at(i)[j] == RED_PIXEL) {
                pixID = i * ImagePatternCanvas.getCanvasWidth() + j;
                ImagePatternCanvas.setCanvasElem(i, j, WHITESPACE);
                PixelData.at(imgID).pixels.at(pixID).red-=150;
            }
        }
    }
}
