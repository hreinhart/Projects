#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct point
{
    int x;
    int y;
} Point;

typedef struct line{
    Point *p1;
    Point p2;
}Line;

Point *getPoint(char prompt[]);

Line *getLine (char prompt[]);

void printLine (Line *line);

double length (Line *line);

void freeLine(Line *line);

// function signature
// return-type name(formal_parameter1, formal_parameter2, ...);
double dist (Point *p1, Point *p2);

int main() {

    Line *line = getLine ("Enter points for a line\n");
    printLine (line);
    printf("Line length: %.2lf\n", length(line));
    freeLine (line);
    /*
    //Point *p1 = getPoint("Enter an x and a y for point 1:\n");
    //Point *p2 = getPoint("Enter an x and a y for point 2:\n");

    double d = dist (p1, p2);
    printf("The distance between the points is %.2lf\n", d);

    free (p1);
    free (p2);
    */
    return 0;
}

//function to free dynamic memory that hasn't been freed
void freeLine(Line *line){
    free (line->p1);
    free (line);
}

//function to calculate distance
double length (Line *line){
    return dist (line->p1, &line->p2);
}

void printLine (Line *line){
    printf ("The line runs from (%d, %d) to (%d, %d)\n", line->p1->x, line->p1->y, line->p2.x, line->p2.y);
}

Line *getLine (char prompt[]){
    printf("%s", prompt);
    Line *line = malloc (sizeof(Line));

    line->p1 = getPoint("Enter an x and a y for point 1:\n");
    Point *temp = getPoint("Enter an x and a y for point 2:\n");
    line->p2 = *temp;
    free (temp);

    return line;
}

Point *getPoint(char prompt[]){
    printf("%s", prompt);
    Point *p = malloc (sizeof(Point));
    scanf("%d %d", &p->x, &p->y);

    return p;
}

// function definition
// return-type name(params) { statements(s); }
double dist (Point *p1, Point *p2){
    int xVal = p2->x - p1->x;
    int yVal = p2->y - p1->y;
    double dist = sqrt ((xVal * xVal) + (yVal * yVal));


    return dist;

}
