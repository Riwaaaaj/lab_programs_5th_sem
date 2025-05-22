#include <stdio.h>
#include <math.h>

int round_off(float x) {
    int y = x;
    if ((x - y) < 0.5) {
        return y;
    } else {
        return y + 1;
    }
}

int modulus(int x) {
    if (x < 0) {
        return x * -1;
    } else {
        return x;
    }
}

int main() {
    int i;
    float steps, x1, x2, y1, y2, dx, dy, x, y, delx, dely;

    printf("Enter the starting coordinate: ");
    scanf("%f%f", &x1, &y1);

    printf("Enter the ending coordinate: ");
    scanf("%f%f", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if (modulus(dx) > modulus(dy)) {
        steps = modulus(dx);
    } else {
        steps = modulus(dy);
    }

    delx = dx / steps;
    dely = dy / steps;
    x = x1;
    y = y1;

    printf("x\t\ty\t\tround(x)\tround(y)\n");

    for (i = 1; i <= steps + 1; i++) {
        printf("%f\t%f\t%d\t\t%d\n", x, y, round_off(x), round_off(y));
        x = x + delx;
        y = y + dely;
    }

    return 0;
}
