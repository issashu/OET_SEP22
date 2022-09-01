//
// Created by Issashu Greybeard on 31.08.22.
//

#include "PatternManipulations.h"
#include "pixelCanvas.h"
#include <algorithm>
#include <iostream>

/*TO GET PIXID ROWS*WIDTH + J + 1*/
void PatternManipulations::FillRedPattern(const std::vector<PackedImage> &images, const int &imgNum,
                                          pixelCanvas &Canvas) {
    int pixelID = 0;

    int32_t canvasH = Canvas.getCanvasHeight();
    int32_t canvasW = Canvas.getCanvasWidth();
    for (int i = 0; i < canvasH; i++) {
        for (int j = 0; j < canvasW; j++) {
            if (images[imgNum].pixels[pixelID++].red >= RED_TRESHOLD) {
                Canvas.setCanvasElem(i, j, '*');
            }
        }
    }
}

pixelCanvas PatternManipulations::StringToPattern(const EyePattern &strPattern, const int &row_width) {
    u_int32_t row_count = strPattern.size();
    pixelCanvas tmpCanvas (row_width, row_count);
    tmpCanvas.clearCanvas();
    for (int row = 0; row < row_count; row++){
        for (int col = 0; col < row_width; col++) {
            if(strPattern[row][col] != ' '){
                tmpCanvas.setCanvasElem(row, col, '*');
            }
        }
    }

    return tmpCanvas;
}

void PatternManipulations::PatternMatching(std::string const& pattOne, std::string const& pattTwo){
    std::size_t found = pattOne.find(pattTwo);
    if (found!=std::string::npos){
        std::cout << "found at: " << found << '\n';
    }
}


/*
 auto it = std::find( vrecords.begin(), vrecords.end(), "Buy" );

if ( it != vrecords.end() )
{
    std::cout << "Word \"" << "Buy"
              << "\" is found at position "
              << std::distance( vrecords.begin(), it )
              << std::endl;
}
 */

/*
const char * s[] = { "Buy", "Sell" };

auto it = std::find_first_of( vrecords.begin(), vrecords.end(),
                              std::begin( s ), std::end( s ) );

if ( it != vrecords.end() )
{
    std::cout << "One of the words \"" << "Buy and Sell"
              << "\" is found at position "
              << std::distance( vrecords.begin(), it )
              << std::endl;
}
*/