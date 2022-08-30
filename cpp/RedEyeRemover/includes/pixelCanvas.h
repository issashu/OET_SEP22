//
// Created by Issashu Greybeard on 30.08.22.
//

#ifndef OCADO_TECH_PIXELCANVAS_H
#define OCADO_TECH_PIXELCANVAS_H

#include <cstdint>

class pixelCanvas {
//TODO Make private and getters
private:
    //Simple C-style array of strings, since we don't modify its size
    char **Canvas;
    int32_t canvasWidth;
    int32_t canvasHeight;

public:
    pixelCanvas() = delete;
    pixelCanvas(int32_t width, int32_t height);
    ~pixelCanvas();
    [[nodiscard]] char** getCanvas() const;
    int32_t getCanvasHeight() const;
    int32_t getCanvasWidth() const;
    void setCanvasElem(int32_t row, int32_t col, char element);
    char getCavnasElement(int32_t row, int32_t col) const;
    void printCanvas();
};


#endif //OCADO_TECH_PIXELCANVAS_H
