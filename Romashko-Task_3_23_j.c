#include <stdio.h>
#include <math.h>

double sinc(double num){
    if (num == 0){
        return 1;
    }
    else{
        return (sin(num)/num);
    }
}

double derivative(double (*func)(double), double x) {
    double h = 1e-5;
    return (func(x + h) - func(x - h)) / (2 * h);
}

void task_3_23_g(){
    double x;
    printf("Type x: ");
    scanf("%lf", &x);

    printf("sinc(%lf) = %lf;\n", x, sinc(x));
    printf("sinc'(%lf) = %lf;", x, derivative(sinc, x));
}

int main(){
    task_3_23_g();
}