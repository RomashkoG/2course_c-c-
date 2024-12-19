#include <stdio.h>

typedef struct Sphere{
    float x;
    float y;
    float z;
    float r;
} Sphere;

void scansphere(Sphere *sphere){
    printf("Type x, y, z, r: ");
    scanf("%f %f %f %f", &(sphere->x), &(sphere->y), &(sphere->z), &(sphere->r));
}

void printsphere(Sphere *sphere){
    printf("x=%f, y=%f, z=%f, r=%f", (sphere->x), (sphere->y), (sphere->z), (sphere->r));
}

void task10_6_j(){
    Sphere sphere;
    scansphere(&sphere);
    printsphere(&sphere);
}

int main(){
    task10_6_j();
}
