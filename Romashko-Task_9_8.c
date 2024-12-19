#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void calculateStatistics(double *vector, int size, double *mean, double *variance)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += vector[i];
    }
    *mean = (double)sum / size;

    double sumSquaredDiffs = 0;
    for (int i = 0; i < size; i++)
    {
        sumSquaredDiffs += pow(vector[i] - *mean, 2); // shouldnt be abs?
    }
    *variance = sumSquaredDiffs / size;
}

int task9_8(){
    int numVectors;
    printf("Enter the number of vectors you want to input: ");
    scanf("%d", &numVectors);

    for (int i = 0; i < numVectors; i++){
        int size;
        printf("\nEnter the size of vector %d: ", i + 1);
        scanf("%d", &size);

        double *vector = (double *)malloc(size * sizeof(double));
        if (vector == NULL){
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter %d elements of vector %d:\n", size, i + 1);
        for (int j = 0; j < size; j++){
            printf("Element %d: ", j + 1);
            scanf("%lf", &vector[j]);
        }

        double mean, variance;
        calculateStatistics(vector, size, &mean, &variance);

        printf("Mean of vector %d: %.2f\n", i + 1, mean);
        printf("Variance of vector %d: %.2f\n", i + 1, variance);

        free(vector);
    }

    return 0;
}

int main(){
    task9_8();
}
