#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawCircle(int a, int b, int r) {
    int x = 0;
    int y = r;
    float p = 5 / 4 - r;

    while (x <= y) {

		putpixel(a + x, b + y, BLUE);
		putpixel(a + y, b + x, RED);
		putpixel(a + y, b - x, BLUE);
		putpixel(a + x, b - y, RED);
		putpixel(a - x, b - y, BLUE);
		putpixel(a - y, b - x, RED);
		putpixel(a - y, b + x, BLUE);
		putpixel(a - x, b + y, RED);

		x++;
		p = p + 2 * x + 1;
		
		if (p >= 0) {
			y--;
			p = p - 2 *y;
		}
	}
}

int main() {
    int gd = DETECT, gm;
    int a, b, r;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	setbkcolor(WHITE);  // 👈 Set background color to white
    printf("Enter center (a, b) and radius: ");
    scanf("%d %d %d", &a, &b, &r);

    drawCircle(a, b, r);

    getch();
    closegraph();
    return 0;
}