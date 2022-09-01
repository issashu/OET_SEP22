//
// Created by Issashu Greybeard on 30.08.22.
//

#include "RedEyeRemover/includes/pixelCanvas.h"
#include <iostream>

//TODO Remove debug prints
/*######### Constructors and Destructor ########*/
pixelCanvas::pixelCanvas(int32_t width, int32_t height) : canvasWidth(width), canvasHeight(height) {
    Canvas = new std::vector<std::string> (canvasHeight);
    std::cout << "Created canvas" << std::endl;
}

pixelCanvas::~pixelCanvas() {
    delete Canvas;
    Canvas = nullptr;
    canvasHeight = 0;
    canvasWidth = 0;
    std::cout << "Destroyed Canvas!" << std::endl;
}

pixelCanvas::pixelCanvas(const pixelCanvas &other) {
    this->canvasWidth = other.canvasWidth;
    this->canvasHeight = other.canvasHeight;

    Canvas = new std::vector<std::string> (canvasHeight);

    std::copy(other.Canvas->begin(), other.Canvas->end(), this->Canvas->begin());
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
auto* pixelCanvas::getCanvas() const {
    return Canvas;
}

void pixelCanvas::setCanvasElem(int32_t row, int32_t col, char element) {
    Canvas->at(row).replace(col,1,1,element);
}

int32_t pixelCanvas::getCanvasHeight() const {
    return canvasHeight;
}

int32_t pixelCanvas::getCanvasWidth() const {
    return canvasWidth;
}

void pixelCanvas::printCanvas() {
    for (int i = 0; i < canvasHeight; i++) {
        std::cout << Canvas->at(i);
        std::cout << std::endl;
    }
}

void pixelCanvas::clearCanvas() {
    for (int i = 0; i < canvasHeight; i++) {
        Canvas->at(i).replace(0, canvasWidth, canvasWidth, '.') ;
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
        delete Canvas;

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






