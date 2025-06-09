#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int roundoff(float x) {
    return (int)(x + 0.5);
}

int main() {
    float dx, dy, steps, x1, y1, x2, y2, delx, dely, x, y;
    int k;
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
    clrscr();

    // Input coordinates
    printf("Enter the initial coordinates (x1, y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter the ending coordinates (x2, y2): ");
    scanf("%f %f", &x2, &y2);

    // Calculate deltas
    dx = x2 - x1;
    dy = y2 - y1;

    // Determine the number of steps
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    // Compute increments
    delx = dx / steps;
    dely = dy / steps;

    // Initialize starting point
    x = x1;
    y = y1;

    // Draw line using DDA algorithm
    for (k = 0; k <= steps; k++) {
        putpixel(roundoff(x), roundoff(y), WHITE);
        delay(100);
        x += delx;
        y += dely;
    }

    getch();
    closegraph();
    return 0;
}
