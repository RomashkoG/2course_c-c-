#include<stdio.h>
#include<stdlib.h>

void printBinaryInt(unsigned int num) {
    static int counter = 0;
    printf("BINARY = ");
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

void printHexInt(unsigned int num) {
    static int counter = 0;
    printf("HEX = 0x");
    for (int i = 28; i >= 0; i -= 4) {
        int hexDigit = (num >> i) & 0xF;
        if (hexDigit < 10) {
            printf("%d", hexDigit);
        } else {
            printf("%c", 'A' + (hexDigit - 10));
        }
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

unsigned int set0_right(unsigned int m, unsigned int set0_size){
    for(int i = 0; i <= (set0_size - 1); i++){
        m &= ~(1 << i);
    }
    return m;
}

// !!! 
// якщо пам'яті виділяється більше бітів чим треба, то функція set0_left не враховує нулі до початку бінарного числа, а обрізає його починаючи вже з самого числа
unsigned int set0_left(unsigned int m, unsigned int set0_size){
    unsigned int size_m = 0, new_m = m;
    while(new_m != 0){
        size_m ++;
        new_m /= 2;
    }
    for(int i = 0; i <= set0_size; i++){
        m &= ~(1 << i + (size_m - (set0_size)));
    }
    return m;
}

void task_6_11(){
    unsigned int m, k;
    printf("Type natural number: ");
    scanf("%u", &m);
    printBinaryInt(m);
    printHexInt(m);

    printf("\nType number of bits set to 0 (max 32): ");
    scanf("%u", &k);

    printf("\nSet binary right k numbers to 0: \nDECIMAL = %u\n", set0_right(m, k));
    printBinaryInt(set0_right(m, k));
    printHexInt(set0_right(m, k));
    printf("\nSet binary left k numbers to 0: \nDECIMAL = %u\n", set0_left(m, k));
    printBinaryInt(set0_left(m, k));
    printHexInt(set0_left(m, k));
}   

int main(){
    task_6_11();
}