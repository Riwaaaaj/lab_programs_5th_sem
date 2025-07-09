#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to draw ellipse using midpoint algorithm
void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0;
    int y = ry;

    long rxSq = rx * rx;
    long rySq = ry * ry;

    long twoRxSq = 2 * rxSq;
    long twoRySq = 2 * rySq;

    long px = 0;
    long py = twoRxSq * y;

    // Region 1
    long p1 = rySq - (rxSq * ry) + (0.25 * rxSq);
        // Region 2
    long p2 = rySq * (x + 0.5) * (x + 0.5) +
              rxSq * (y - 1) * (y - 1) -
              rxSq * rySq;

    while (px < py) {
        // Plot all 4 symmetric points
        putpixel(xc + x, yc + y, RED);
        putpixel(xc - x, yc + y, RED);
        putpixel(xc + x, yc - y, RED);
        putpixel(xc - x, yc - y, RED);

        x++;
        px += twoRySq;
        if (p1 < 0) {
            p1 += rySq + px;
        } else {
            y--;
            py -= twoRxSq;
            p1 += rySq + px - py;
        }
    }

    while (y >= 0) {
        // Plot all 4 symmetric points
        putpixel(xc + x, yc + y, BLUE);
        putpixel(xc - x, yc + y, BLUE);
        putpixel(xc + x, yc - y, BLUE);
        putpixel(xc - x, yc - y, BLUE);

        y--;
        py -= twoRxSq;
        if (p2 > 0) {
            p2 += rxSq - py;
        } else {
            x++;
            px += twoRySq;
            p2 += rxSq - py + px;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, rx, ry;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setbkcolor(WHITE);   // Graphics background
    cleardevice();

    textbackground(WHITE);  // Console background (for printf/scanf)
    textcolor(BLACK);       // Console text color
    clrscr();               // Apply both to console

    printf("Enter center coordinates (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radii (rx, ry): ");
    scanf("%d %d", &rx, &ry);

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}

