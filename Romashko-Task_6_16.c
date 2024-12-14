#include<stdio.h>

void f(unsigned int num){
    unsigned int a, newnum = num;
    char binarnum[33];
    for(int i = 31; i >= 0; i--){
        a = newnum % 2;
        newnum /= 2;
        if (a == 0){
            binarnum[i] = 'Y';
        }
        if (a == 1){
            binarnum[i] = 'X';
        }
    }
    binarnum[32] = '\0';
    printf("%s", binarnum);
}

int main(){
    unsigned int num;
    printf("Type number:");
    scanf("%u", &num);
    f(num);
}