#include<stdio.h>
#include<stdlib.h>

typedef struct car{
    int age;
    float price;
}car;

float caraverageprice(car *cpt, int n){
    float allprice = 0;
    int counter = 0;
    for(int i = 0; i < n; i++){
        if((cpt+i)->age > 5){
            allprice += (cpt+i)->price;
            counter += 1;
            // printf("allprise = %f,\n counter = %d\n", allprice, counter);
        }
    }
    return allprice/counter;
}

void task10_7(){
    int n;
    printf("Type num of cars: ");
    scanf("%d", &n);

    car *cptr = malloc(n*sizeof(car));
    if (cptr == NULL){
        printf("Failed to allocate memory\n");
        return;
    }
    for(int i=0;i<n;i++){
        printf("Type %d car age:", i+1);
        scanf("%d", &((cptr+i)->age));
        printf("Type %d car price:", i+1);
        scanf("%f", &((cptr+i)->price));    
    }   
    
    printf("car average price = %f", caraverageprice(cptr, n));
}

int main(){
    task10_7();
}