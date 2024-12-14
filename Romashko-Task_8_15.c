#include<stdio.h>
#include<math.h>
#define N 5

void printMatrix(int n, int *matrix){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%5d ", *(matrix + (i * n) + j));
        }
        printf("\n");
    }
    printf("\n");
    // {{21, 2, 3, 4, -9,  5, -6, 7, 8, -7,9, 22, -11, 12, -6, {13, 14, 15, 16, -2}, {17, 18, 19, 20, 21}};
}

void reduceMatrix(int n, int *matrix, int rowToRemove, int colToRemove){
    printf("reduceMatrix n == %d\n", n);
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1; j++){
            int sourceRow = i + (i >= rowToRemove);
            int sourceCol = j + (j >= colToRemove);
            int reducedMatrixElem = *((int *)matrix + (i * (n - 1)) + j);
            int fullMatrixElem = *((int *)matrix + (sourceRow * n) + sourceCol);
            int reducedShift = (i * (n - 1)) + j;
            int fullMatrixShift = (sourceRow * n) + sourceCol;
            printf("Replacing %d (at %d) with %d (at %d)\n", reducedMatrixElem, reducedShift, fullMatrixElem, fullMatrixShift);
                        
            *((int *)matrix + reducedShift) = *((int *)matrix + fullMatrixShift);

        }
    }
}

void task8_15()
{
    int n = N;
    int matrix[N][N] = {
        {21, 2, 3, 4, -9},
        {5, -6, 7, 8, -7},
        {9, 22, -11, 12, -6},
        {13, 14, 15, 16, -2},
        {17, 18, 19, 20, 21}};

    printf("Original Matrix:\n");
    printMatrix(n, (int *)matrix);

    while (n > 1)
    {
        int maxRow = 0, maxCol = 0;
        int maxElement = abs(*(int *)matrix);
        int candidate = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                candidate = *(((int *)matrix + (i * n) + j));
                // printf("Candidate == %d\n", candidate);
                if (abs(candidate) > maxElement)
                {
                    maxElement = abs(candidate);
                    maxRow = i;
                    maxCol = j;
                    // printf("New max element == %d, maxRow == %d, maxCol == %d\n", maxElement, maxRow, maxCol);
                }
            }
        }

        printf("Removing row %d and column %d with element %d\n", maxRow, maxCol, *(((int *)matrix) + maxRow * n + maxCol));

        reduceMatrix(n, (int *)matrix, maxRow, maxCol);
        n--;

        printf("Matrix after reduction:\n");
        printMatrix(n, (int *)matrix);
    }
}

int main(){
    task8_15();
}