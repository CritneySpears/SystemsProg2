#include "types.h"
#include "user.h"

int abs(int number) {
    //return (number^2) / number;
    if (number < 0) {
        return 0 - number;
    }
    else {
        return number;
    }
}

/**
 * Implementation of Bresenham's line algorithm.
 * Fast and simple, using integer addition, subtraction and bit shifting.
 * Based on implementation available on Rosettacode.org available here http://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
*/
void line(int x0, int y0, int x1, int y1, int colour) {

    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1; // calculate delta x 
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1; // calculate delta y
    int err = (dx<dy ? dx : -dy)/2, e2; // calculate error

    for(;;) {
        placepixel(x0, y0, colour);
        if (x0 == x1 && y0 == y1) break; // Have we finished?
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

int main() {
    printf(1, "Demo started.\n");
    
    setvideomode();
    clearscreen();

    placepixel(160, 0, 1);

    for (int i = 0; i < 20; i++) {
        placepixel(160, i * 10 + 5, i * 2);
    }

    for (int i = 0; i < 20; i++) {
        line(0, i * 10, 319, i * 10, i);
    }

    getch();
    exit();
}