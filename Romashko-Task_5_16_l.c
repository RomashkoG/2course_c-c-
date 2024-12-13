#include <stdio.h>
#include <math.h>

double f(double x){
    double segment = 1, e = 0.0000000001, result, counter = 1;
    while(fabs(segment) > e){
        result += segment;
        segment *= (2 * counter - 1) / (2 * counter) * x * (-1);
        counter ++;
    }
    return result;
}

void task_5_16_l(){
    double x;
    printf("Type x (|x| < 1): ");
    scanf("%lf", &x);

    if (fabs(x) > 1) {
        printf("Wrong x\n");
        return;
    }

    printf("Normal result 1/sqrt(1+x) = %.11lf\n", 1 / sqrt(1.0 + x));
    printf("Close result 1/sqrt(1+x)=1-(1/2)*x+(1*3)/(2*4)*x^2-(1*3*5)/(2*4*6)*x^3+... = %.11lf", f(x));
}

int main() {
    task_5_16_l();
}