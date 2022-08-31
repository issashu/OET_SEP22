//
// Created by Issashu Greybeard on 30.08.22.
//

#ifndef OCADO_TECH_PIXELCANVAS_H
#define OCADO_TECH_PIXELCANVAS_H

#include <cstdint>

class pixelCanvas {
private:
    //Simple C-style array of strings, since we don't modify its size and not needed all vector func.
    char **Canvas;
    int32_t canvasWidth;
    int32_t canvasHeight;

public:
    pixelCanvas() = delete;
    pixelCanvas(int32_t width, int32_t height);

    pixelCanvas(const pixelCanvas& other);
    pixelCanvas& operator=(pixelCanvas const& other);

    pixelCanvas(pixelCanvas&& other) noexcept ;
    pixelCanvas& operator=(pixelCanvas&& other) noexcept ;
    ~pixelCanvas();

    char** getCanvas() const;
    int32_t getCanvasHeight() const;
    int32_t getCanvasWidth() const;
    void setCanvasElem(int32_t row, int32_t col, char element);
    char getCavnasElement(int32_t row, int32_t col) const;
    void clearCanvas();
    void printCanvas();
};


#endif //OCADO_TECH_PIXELCANVAS_H
