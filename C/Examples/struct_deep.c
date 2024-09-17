#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} Point;

typedef struct triangle {
    Point *p1;
    Point *p2;
    Point *p3;
} Triangle;

void deepCopy(Triangle *dest, Triangle *src) {
    dest->p1 = (Point *)malloc(sizeof(Point));
    dest->p1->x = src->p1->x;
    dest->p1->y = src->p1->y;

    dest->p2 = (Point *)malloc(sizeof(Point));
    dest->p2->x = src->p2->x;
    dest->p2->y = src->p2->y;

    dest->p3 = (Point *)malloc(sizeof(Point));
    dest->p3->x = src->p3->x;
    dest->p3->y = src->p3->y;
}

int main() {

    Triangle t1;

    Point p1;
    p1.x = 0;
    p1.y = 0;

    Point p2;
    p2.x = 1;
    p2.y = 1;

    Point p3;
    p3.x = 0;
    p3.y = 1;

    t1.p1 = &p1;
    t1.p2 = &p2;
    t1.p3 = &p3;

    Triangle *t2 = (Triangle *)malloc(sizeof(Triangle));
    deepCopy(t2, &t1);
    t2->p1->x = 10;

    printf("t1.p1->x=%d, p1.x=%d, t2->p1->x=%d\n", t1.p1->x, p1.x, t2->p1->x);

    return 0;
}
