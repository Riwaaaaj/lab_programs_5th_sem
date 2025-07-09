#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void drawEllipse(int X, int Y, int a, int b) {
    float x = 0, y = b;

    // Initial decision parameter for Region 1
    float p1 = b * b - a * a * b + (0.25 * a * a);
    float dx = 2 * b * b * x;
    float dy = 2 * a * a * y;
    
    // Initial decision parameter for Region 2
    float p2 = b * b * (x + 0.5) * (x + 0.5) +
               a * a * (y - 1) * (y - 1) -
               a * a * b * b;
    // Region 1
    while (dx < dy) {
        // Plotting 4 symmetric points
        putpixel(X + x, Y + y, BLUE);
        putpixel(X - x, Y + y, BLUE);
        putpixel(X + x, Y - y, RED);
        putpixel(X - x, Y - y, RED);

        x++;
        dx = dx + (2 * b * b);
        
        if (p1 < 0) {
            p1 = p1 + dx + (b * b);
        } else {
            y--;
            dy = dy - (2 * a * a);
            p1 = p1 + dx - dy + (b * b);
        }
    }


    // Region 2
    while (y >= 0) {
        // Plotting 4 symmetric points
        putpixel(X + x, Y + y, BLUE);
        putpixel(X - x, Y + y, BLUE);
        putpixel(X + x, Y - y, RED);
        putpixel(X - x, Y - y, RED);

        y--;
        dy = dy - (2 * a * a);
        if (p2 > 0) {
            p2 = p2 - dy + (a * a);
        } else {
            x++;
            dx = dx + (2 * b * b);
            p2 = p2 + dx - dy + (a * a);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int X, Y, a, b;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    // setbkcolor(WHITE);
    cleardevice();

    printf("Enter center coordinates (X, Y): ");
    scanf("%d %d", &X, &Y);
    printf("Enter radii a and b: ");
    scanf("%d %d", &a, &b);

    drawEllipse(X, Y, a, b);

    getch();
    closegraph();
    return 0;
}
