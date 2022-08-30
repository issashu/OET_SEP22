//
// Created by Issashu Greybeard on 30.08.22.
//

#include "RedEyeRemover/includes/pixelCanvas.h"
#include <iostream>
//TODO Remove debug prints
pixelCanvas::pixelCanvas(int32_t width, int32_t height) : canvasWidth(width), canvasHeight(height) {
    Canvas = new char *[canvasHeight];

    for (int i = 0; i < canvasHeight; i++) {
        Canvas[i] = new char[canvasWidth];
    }
    std::cout<<"Created canvas"<<std::endl;
}

pixelCanvas::~pixelCanvas() {
    for (int i = 0; i < canvasHeight; i++) {
        delete[] Canvas[i];
    }

    delete[] Canvas;
    std::cout<<"Destroyed Canvas!"<<std::endl;
}

/*######### Other methods ###########*/
char **pixelCanvas::getCanvas() const {
    return Canvas;
}

void pixelCanvas::setCanvasElem(int32_t row, int32_t col, char element) {
    Canvas[row][col] = element;
}

int32_t pixelCanvas::getCanvasHeight() const {
    return canvasHeight;
}

int32_t pixelCanvas::getCanvasWidth() const {
    return canvasWidth;
}

char pixelCanvas::getCavnasElement(int32_t row, int32_t col) const {
    return Canvas[row][col];
}

void pixelCanvas::printCanvas() {
    for(int i = 0; i < canvasHeight; i++) {
        for (int j = 0; j < canvasWidth; j++) {
            std::cout << Canvas[i][j];
        }
        std::cout << std::endl;
    }
}

