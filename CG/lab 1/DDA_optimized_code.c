#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
// A function to round a float to the nearest integer.
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
    // Calculate the difference in x and y
    dx = x2 - x1;
    dy = y2 - y1;
    // Determine the number of steps for the DDA algorithm
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);
    // Calculate increment values for x and y
    delx = dx / steps;
    dely = dy / steps;
    // Set the initial point
    x = x1;
    y = y1;
    // Line drawing using DDA
    for (k = 0; k <= steps; k++) {
        // Plot the rounded coordinates
        putpixel(roundoff(x), roundoff(y), WHITE);
        delay(100);
        // Update x and y for the next point
        x += delx;
        y += dely;
    }
    getch();
    closegraph();
    return 0;
}
