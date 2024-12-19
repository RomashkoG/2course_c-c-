#include<stdio.h>
#include<math.h>

int gcd(int a, int b){
    while (b != 0){
        int buffer = b;
        b = a % b;
        a = buffer;
    }
    return a;
}

void task_4_26(){
    int n, m, gcd_n_m;
    printf("Type n & m through the space for rational number n/m: ");
    scanf("%d %d", &n, &m);
    
    if (m <= 0){
        printf("Invalid m");
    }

    gcd_n_m = gcd(abs(n), m);
    while (gcd_n_m != 1){
        n /= gcd_n_m;
        m /= gcd_n_m;
        gcd_n_m = gcd(n, m);
    }
    printf("Simplified rational number is %d/%d", n, m);
}

int main(){
    task_4_26();
}