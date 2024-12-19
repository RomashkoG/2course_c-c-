#include<stdio.h>
#include<math.h>

double fg(double num, int n){
    double result = 0;
    while (n >= 0){
        result += n * pow(num, (n-1));
        n -= 1;
    }
    return result;
}

void task_4_13_g(){
    int n;
    printf("Type n: ");
    scanf("%d", &n);
    double x;
    printf("Type x: ");
    scanf("%lf", &x);
    
    printf("%lf\n", fg(x, n));
}

int main(){
    task_4_13_g();
}