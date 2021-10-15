#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point;

typedef struct{
    point A;
    point B;
} line;

float dist(line Line){
    return (sqrt((Line.A.x - Line.B.x)*(Line.A.x - Line.B.x) + (Line.A.y - Line.B.y)*(Line.A.y - Line.B.y)));
}

int main(){
    float d;
    line Line;

    printf("The coordinates of the point A are: ");
    scanf("%f %f", &Line.A.x,&Line.A.y);

    printf("\nThe coordinates of the point B are: ");
    scanf("%f %f", &Line.B.x, &Line.B.y);

    printf("\nThe distance between A and B is %f\n", dist(Line));

    return 0;
}