#include <graphics.h>

// driver code
int main()
{
    // gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file
    int gd = DETECT, gm;

    // initgraph initializes the
    // graphics system by loading
    // a graphics driver from disk
    initgraph(&gd, &gm, "");

    // location of text
    int x = 150;
    int y = 150;

    // font style
    int font = 8;

    // font direction
    int direction = 0;

    // font size
    int font_size = 5;

    // for setting text style
    settextstyle(font, direction, font_size);

    // for printing text in graphics window
    outtextxy(x, y, "Geeks For Geeks");

    getch();

    // closegraph function closes the
    // graphics mode and deallocates
    // all memory allocated by graphics
    // system .
    closegraph();

    return 0;
}
