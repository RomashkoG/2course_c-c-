#include <stdio.h>
#include <math.h>

double sign(double num){
    if (num > 0){
        return 1;
    }
    else if (num == 0){
        return 0;
    }
    else if (num < 0){
        return -1;
    }
}

double fa(double num){
    return fabs(num);
}

double fb(double num){
    return (fabs(fabs(num) - 1.0) - 1.0);
}

double fc(double num){
    return sign(fabsl(num));
}

double fd(double num){
    return sin(num);
}

void task_3_11(){
    double x;
    printf("List of functions:\na)f(x)=|x|;\nb)f(x)=||x|-1|-1;\nc)f(x)=sign(x);\nd)f(x)=sin(|x|);\nType x: ");
    scanf("%lf", &x);
    printf("f(x) = %lf\n", fa(x));
    printf("f(x) = %lf\n", fb(x));
    printf("f(x) = %lf\n", fc(x));
    printf("f(x) = %lf\n", fd(x));
}

int main(){
    task_3_11();
}