#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

// Function to round a float to the nearest integer
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

    // Calculate dx, dy
    dx = x2 - x1;
    dy = y2 - y1;

    // Determine number of steps
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    // Calculate increments
    delx = dx / steps;
    dely = dy / steps;

    // Initial point
    x = x1;
    y = y1;

    printf("\n");
    // DDA line drawing
    for (k = 0; k <= steps; k++) {
        x += delx;
        y += dely;
        steps = fabs(dy);
    }
    delx = dx / steps;
    dely = dy / steps;
    x = x1;
    y = y1;
    for (k = 0; k <= steps; k++) {
        x += delx;
        y += dely;
        // Draw pixel
        putpixel(roundoff(x), roundoff(y), WHITE);
        delay(100);
    }

    getch();
    // Close the graphics mode
    closegraph();
    return 0;
}