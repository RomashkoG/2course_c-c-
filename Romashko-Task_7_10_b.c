#include<stdio.h>
#include<math.h>

void task_7_10_b(){
    int massif_size;
    printf("Type massif size: ");
    scanf("%d", &massif_size);
    int massif[massif_size];
    for(int i = 0; i < massif_size; i++){
        printf("Type massive[%d] number: ", i);
        scanf("%u", &massif[i]);
    }

    int f_massif_size = (massif_size - 1);
    int f_massif[f_massif_size];
    for(int i = 0; i < massif_size-1; i ++){
        f_massif[i] = massif[i] + massif[i+1];
    }

    int min_num = f_massif[0];
    for(int i = 0; i < f_massif_size; i++){
        if (f_massif[i] < min_num){
            min_num = f_massif[i];
        }
    }

    printf("min(a{1} + a{2}, ..., a{n-1} + a{n}) = %d", min_num);
}

int main(){
    task_7_10_b();
}