#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void task_11_3_b();
bool is_pow_of_3(int num);

int main(){
    task_11_3_b();
}

void task_11_3_b(){
    FILE *fileF = fopen("F.txt", "w+");
    FILE *fileG = fopen("G.txt", "w");
    if (fileF == NULL || fileG == NULL){
        printf("Error opening file");
        return;
    }

    int num = 1;
    while(num != 0){
        printf("Type number: ");
        scanf("%d", &num);
        fprintf(fileF, "%d", num);
        fprintf(fileF, ", ");
    }

    rewind(fileF);
    
    char ch;
    while((ch = fgetc(fileF)) != EOF){
        if (ch >= '0' && ch <= '9'){
            fscanf(fileF, "%d", &num);
            if(is_pow_of_3(num)){
                fprintf(fileG, "%d", num);
            }
        }
    }
    fclose(fileF);
    fclose(fileG);
}

bool is_pow_of_3(int num){
    if(num <= 0){
        return false;
    }
    printf("%d\n, %d\n", num, (num % 3));
    while(num > 1){
        if(num % 3 != 0){
            return false;
        }
        num /= 3;
    }
    return true;
}