#include<stdio.h>
#include<math.h>
#include <stdbool.h>

bool is_cube(double num){
    if (num < 1) {
        return false;
    }
    int cubeRoot = (double)round(pow(num, 1.0 / 3.0));
    return (cubeRoot * cubeRoot * cubeRoot == num);
}

void task_7_8_d(){
    int massif_size;
    printf("Type massif size: ");
    scanf("%d", &massif_size);
    unsigned int massif[massif_size];
    for(int i = 0; i < massif_size; i++){
        printf("Type massive[%d] number: ", i);
        scanf("%u", &massif[i]);
    }

    int counter = 0;
    for(int i = 0; i < massif_size; i++){
        if ((massif[i] % 3 == 0) && is_cube((double)massif[i])){
            counter ++;
        }
    }
    
    printf("%d numbers are divisible by 3 and are the cube of a natural number", counter);
}

int main(){
    task_7_8_d();
}