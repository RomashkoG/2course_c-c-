#include<stdio.h>
#include<math.h>

int main(){
    double num;
    printf("Type x from 0 to 10000: ");
    scanf("%lf", &num);
    printf(" x^8 = %20.4lf \n", pow(num, 8));
}