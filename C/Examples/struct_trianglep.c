#include <stdio.h>

typedef struct point {
    int x;
    int y;
} Point;

typedef struct triangle {
    Point *p1;
    Point *p2;
    Point *p3;
} Triangle;

int main() {

    Point p1;
    p1.x = 0;
    p1.y = 0;

    Point p2;
    p2.x = 1;
    p2.y = 1;

    Point p3;
    p3.x = 0;
    p3.y = 1;

    Triangle t1;
    t1.p1 = &p1;
    t1.p2 = &p2;
    t1.p3 = &p3;

    Triangle t2 = t1;
    t2.p1->x = 10;

    printf("t1.p1->x=%d, p1.x=%d, t2.p1->x=%d\n", t1.p1->x, p1.x, t2.p1->x);

    return 0;
}
