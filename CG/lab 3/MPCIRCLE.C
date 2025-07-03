#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    float p = 5 / 4 - r;

    while (x <= y) {
	// Plot the 8 symmetric points
	putpixel(xc + x, yc + y, WHITE);
	putpixel(xc + y, yc + x, RED);
	putpixel(xc + y, yc - x, WHITE);
	putpixel(xc + x, yc - y, RED);
	putpixel(xc - x, yc - y, WHITE);
	putpixel(xc - y, yc - x, RED);
	putpixel(xc - y, yc + x, WHITE);
	putpixel(xc - x, yc + y, RED);

	x++;

	if (p < 0)
	    p = p + 2 * x + 1;
	else {
	    y--;
	    p = p + 2 * (x - y) + 1;
	}
    }
}

int main() {
    int gd = DETECT, gm;
    int a, b, r;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    printf("Enter center (a, b) and radius: ");
    scanf("%d %d %d", &a, &b, &r);

    drawCircle(a, b, r);

    getch();
    closegraph();
    return 0;
}
