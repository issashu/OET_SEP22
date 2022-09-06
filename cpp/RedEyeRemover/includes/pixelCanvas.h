//
// Created by Issashu Greybeard on 30.08.22.
//

#ifndef OCADO_TECH_PIXELCANVAS_H
#define OCADO_TECH_PIXELCANVAS_H

#include <cstdint>
#include <vector>
#include <string>

class pixelCanvas {
private:
    std::vector<std::string>* Canvas;
    int32_t canvasHeight;
    int32_t canvasWidth;

public:
    pixelCanvas() = delete;
    pixelCanvas(int32_t width, int32_t height);

    pixelCanvas(const pixelCanvas& other);
    pixelCanvas& operator=(pixelCanvas const& other);

    pixelCanvas(pixelCanvas&& other) noexcept ;
    pixelCanvas& operator=(pixelCanvas&& other) noexcept ;

    bool operator==(pixelCanvas const& other);
    friend void swap(pixelCanvas& first, pixelCanvas& second);

    ~pixelCanvas();

    std::vector<std::string>* getCanvas() const;
    int32_t getCanvasHeight() const;
    int32_t getCanvasWidth() const;
    void setCanvasElem(int32_t row, int32_t col, char element);
    void clearCanvas();
    void printCanvas();
};


#endif //OCADO_TECH_PIXELCANVAS_H
