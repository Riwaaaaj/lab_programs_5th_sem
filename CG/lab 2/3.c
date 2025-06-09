#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx)  { err += dx; y1 += sy; }
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter the starting point (x1, y1): ");
    scanf("%d%d", &x1, &y1);

    printf("Enter the ending point (x2, y2): ");
    scanf("%d%d", &x2, &y2);

    bresenhamLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
