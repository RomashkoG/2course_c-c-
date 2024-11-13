#include<stdio.h>
#include<math.h>

double function_a(double x, double y){
    double result;
    result = pow(x,3) + (3 * pow(x, 2) * y) + (3 * x * pow(y, 2)) + pow(y, 3);
    return result;
}

double function_b(double x, double y){
    double result;
    result = (pow(x,2) * pow(y, 2)) + (pow(x,3) * pow(y, 3)) + (pow(x, 4) * pow(y, 4));
    return result;
}

int main(){
    double x;
    double y;
    printf("Type x:");
    scanf("%lf", &x);
    printf("Type y:");
    scanf("%lf", &y);

    printf("function_a (x^3 + (3 * X^2 * y) + (3 * x * y^2) + y^3) = %lf\n", function_a(x, y));
    printf("function_b ((X^2 * y^2) + (X^3 * y^3) + (x^4 * y^4)) = %lf", function_b(x, y));
}