#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void bresenhamLine (float x1, float y1, float x2, float y2) {
	float dx, dy, x, y;
	float pk;
	int Lx, Ly, k;

	dx = fabs(x2 - x1);
	dy = fabs(y2 - y1);

	Lx = (x2 - x1)? 1 : -1;
	Ly = (y2 - y1)? 1: -1;

	x = x1;
	y = y1;

	putpixel(x, y, WHITE);

	if (dx > dy) {
		pk = 2 * dy - dx;
		for (k = 0; k < dx; k++) {
			if (pk < 0) {
				x += Lx;
				pk = pk + 2 * dy;
			} else {
				x += Lx;
				y += Ly;
				pk = pk + 2 * dy - 2 * dx;
			}
			putpixel(x, y, WHITE);
		}
	} else {
		pk = 2 * dx - dy;
		for (k = 0; k < dy; k++) {
			if (pk < 0) {
				y += Ly;
				pk = pk + 2 * dx;
			} else {
				x += Lx;
				y += Ly;
				pk = pk + 2 * dx - 2 * dy;
			}
			putpixel(x, y, WHITE);
			}
		}
	}

int main() {
	int gd = DETECT, gm;
	float x1, y1, x2, y2;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the starting point (x1, y1): " );
	scanf("%f%f", &x1, &y1);
	printf("Enter ending points (x2, y2): ");
	scanf("%f%f", &x2, &y2);

	bresenhamLine(x1, y1, x2, y2);

	getch();
	closegraph();
	return 0;
}