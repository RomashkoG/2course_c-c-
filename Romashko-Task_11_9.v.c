#include <stdio.h>
#include <stdlib.h>

void write_to_file(FILE *output, int num){
    fprintf(output, "%d ", num);
}

void display_last_two(int last1, int last2){
    printf("Last two numbers: %d %d\n", last1, last2);
}

int main(){
    FILE *fileF = fopen("F.txt", "r");
    FILE *fileG = fopen("G.txt", "w");
    if (fileF == NULL || fileG == NULL){
        printf("Error opening file");
        return EXIT_FAILURE;
    }

    int number, positiveCount = 0, negativeCount = 0;
    int positives[1000], negatives[1000];


    while (fscanf(fileF, "%d", &number) == 1){
        if (number > 0){
            positives[positiveCount++] = number;
        }
        else if (number < 0){
            negatives[negativeCount++] = number;
        }
    }

    if (positiveCount != negativeCount){
        printf("The file does not contain an equal number of positive and negative numbers.\n");
        fclose(fileF);
        fclose(fileG);
        return EXIT_SUCCESS;
    }

    int i = 0, last1 = 0, last2 = 0;
    while (i < positiveCount && i < negativeCount){
        if (i + 1 < positiveCount){
            write_to_file(fileG, positives[i]);
            write_to_file(fileG, positives[i + 1]);
            last1 = positives[i];
            last2 = positives[i + 1];
        }
        if (i + 1 < negativeCount){
            write_to_file(fileG, negatives[i]);
            write_to_file(fileG, negatives[i + 1]);
            last1 = negatives[i];
            last2 = negatives[i + 1];
        }
        i += 2;
    }


    if (i < positiveCount || i < negativeCount){
        display_last_two(last1, last2);
    }

    fclose(fileF);
    fclose(fileG);

    return EXIT_SUCCESS;
}
