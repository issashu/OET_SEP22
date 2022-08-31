//
// Created by Issashu Greybeard on 30.08.22.
//

#include "RedEyeRemover/includes/pixelCanvas.h"
#include <iostream>
//TODO Remove debug prints
//TODO Redo the canvas as one contigeous block of memory rather then point to point (see screenshot on desktop)
/*######### Constructors and Destructor ########*/
pixelCanvas::pixelCanvas(int32_t width, int32_t height) : canvasWidth(width), canvasHeight(height) {
    Canvas = new char *[canvasHeight];

    for (int i = 0; i < canvasHeight; i++) {
        Canvas[i] = new char[canvasWidth];
    }
    std::cout << "Created canvas" << std::endl;
}

pixelCanvas::~pixelCanvas() {
    for (int i = 0; i < canvasHeight; i++) {
        delete[] Canvas[i];
    }
    delete[] Canvas;
    Canvas = nullptr;
    canvasHeight = 0;
    canvasWidth = 0;
    std::cout << "Destroyed Canvas!" << std::endl;
}

pixelCanvas::pixelCanvas(const pixelCanvas &other) {
    this->canvasWidth = other.canvasWidth;
    this->canvasHeight = other.canvasHeight;

    Canvas = new char *[canvasHeight];
    for (int i = 0; i < canvasHeight; i++) {
        Canvas[i] = new char[canvasWidth];
    }

    for (int i = 0; i < canvasHeight; i++) {
        this->Canvas[i] = other.Canvas[i];
    }
}

pixelCanvas::pixelCanvas(pixelCanvas &&other) noexcept {
    this->canvasHeight = other.canvasHeight;
    this->canvasWidth = other.canvasWidth;
    this->Canvas = other.Canvas;

    other.canvasHeight = 0;
    other.canvasWidth = 0;
    other.Canvas = nullptr;
}

/*######### Other methods ####################*/
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
    for (int i = 0; i < canvasHeight; i++) {
        for (int j = 0; j < canvasWidth; j++) {
            std::cout << Canvas[i][j];
        }
        std::cout << std::endl;
    }
}

void pixelCanvas::clearCanvas() {
    for (int i = 0; i < canvasHeight; i++) {
        for (int j = 0; j < canvasWidth; j++) {
            Canvas[i][j] = '.';
        }
    }
}

pixelCanvas &pixelCanvas::operator=(pixelCanvas const &other) {

    if (this != &other) {
        pixelCanvas tmp(other);
        swap(*this, tmp);
        std::cout << "Copied canvas" << std::endl;
    }

    return *this;
}

pixelCanvas &pixelCanvas::operator=(pixelCanvas &&other) noexcept {

    if (this != &other) {
        for (int i = 0; i < canvasHeight; i++) {
            delete[] Canvas[i];
        }
        delete[] Canvas;

        this->canvasHeight = other.canvasHeight;
        this->canvasWidth = other.canvasWidth;
        this->Canvas = other.Canvas;

        other.canvasHeight = 0;
        other.canvasWidth = 0;
        other.Canvas = nullptr;

        std::cout << "Moved canvas" << std::endl;
    }

    return *this;
}

void swap(pixelCanvas &first, pixelCanvas &second) {
    std::swap(first.canvasWidth, second.canvasWidth);
    std::swap(first.canvasHeight, second.canvasHeight);
    std::swap(first.Canvas, second.Canvas);
}






