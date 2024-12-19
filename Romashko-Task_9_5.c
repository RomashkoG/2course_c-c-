#include<stdio.h>
#include<stdlib.h>

int **createMatrix(int rows, int cols){
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void inputMatrix(int **matrix, int rows, int cols){
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void freeMatrix(int **matrix, int rows){
    for (int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int calculateDeterminant(int **matrix, int n){
    if (n == 1){
        return matrix[0][0];
    }
    if (n == 2){
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int determinant = 0;
    for (int i = 0; i < n; i++){
        int **minor = createMatrix(n - 1, n - 1);
        for (int j = 1; j < n; j++){
            int colIndex = 0;
            for (int k = 0; k < n; k++){
                if (k == i)
                    continue;
                minor[j - 1][colIndex] = matrix[j][k];
                colIndex++;
            }
        }
        determinant += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * calculateDeterminant(minor, n - 1);
        freeMatrix(minor, n - 1);
    }
    return determinant;
}

int calculateRank(int **matrix, int rows, int cols){

    int rank = cols;
    for (int row = 0; row < rank; row++){
        if (matrix[row][row]){
            for (int col = 0; col < rows; col++){
                if (col != row){
                    double mult = (double)matrix[col][row] / matrix[row][row];
                    for (int i = 0; i < rank; i++){
                        matrix[col][i] -= mult * matrix[row][i];
                    }
                }
            }
        }
        else{
            int reduce = 1;
            for (int i = row + 1; i < rows; i++){
                if (matrix[i][row]){
                    int *temp = matrix[row];
                    matrix[row] = matrix[i];
                    matrix[i] = temp;
                    reduce = 0;
                    break;
                }
            }
            if (reduce){
                rank--;
                for (int i = 0; i < rows; i++){
                    matrix[i][row] = matrix[i][rank];
                }
            }
            row--;
        }
    }
    return rank;
}

int task9_5(){
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **matrix = createMatrix(rows, cols);
    inputMatrix(matrix, rows, cols);

    printf("The input matrix is:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (rows == cols){
        int determinant = calculateDeterminant(matrix, rows);
        printf("Determinant of the matrix: %d\n", determinant);
    }
    else{
        printf("Determinant is not defined for non-square matrices.\n");
    }

    int rank = calculateRank(matrix, rows, cols);
    printf("Rank of the matrix: %d\n", rank);

    freeMatrix(matrix, rows);
}

int main(){
    task9_5();
}