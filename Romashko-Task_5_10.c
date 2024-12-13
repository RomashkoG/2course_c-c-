#include<stdio.h>
#include<math.h>

double v_i(int i);
double u_i(int i);

double v_i(int i){
    if (i == 0 || i == 1){
        return 1;
    }
    // printf("process v{%d} sucless\n", i);
    return ((u_i(i-1) - v_i(i-1)) / (fabs(u_i(i-2) + v_i(i-1)) + 2));
}

double u_i(int i){
    if (i == 0 || i == 1){
        return 0;
    }
    // printf("process u{%d} sucless\n", i);
    return ((u_i(i-1) - u_i(i-2) * v_i(i-1) - v_i(i-2)) / (1 + pow(u_i(i-1), 2) + pow(v_i(i-1), 2)));
}

void task_5_10(){
    int i;
    printf("numerations:\nv_i = (u_{i-1} - v_{i-1}) / (|u_{i-2} + v_{i-1}| + 2);\nu_i = (u_{i-1} - u_{i-2} * v_{i-1} - v_{i-2}) / (1 + u_{i-1}^2 + v_{i-1}^2);\n");
    printf("Type number of element v: ");
    scanf("%d", &i);

    printf("v_{%d} = %lf", i, v_i(i));
}

int main(){
    task_5_10();
}