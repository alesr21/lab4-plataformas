#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcion para encontrar la longitud de la linea mas larga de 1s en una matriz

void findLargestLine(int **matrix, int size, int *result) {
    *result = 0; // Inicializar el valor en cero
    int currentLength = 0;

    // Recorremos cada elemento de la matriz
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int *ptr = *(matrix + i) + j; 

            if (*ptr == 1) {
                currentLength++;  
                if (currentLength > *result) {
                    *result = currentLength;  
                }
            } else {
                currentLength = 0;  // Reiniciar la secuencia si se encuentra un cero
            }
        }
    }
}

//Funcion para reservar la matriz en memoria dinamica

void allocateMatrix(int ***matrix, int size) {
    *matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        (*matrix)[i] = (int *)malloc(size * sizeof(int));
    }
}

// Función para llenar la matriz con valores aleatorios con 0s y 1s

void fillMatrix(int **matrix, int size) {
    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2; 
        }
    }
}

//Funcion para imprimir la matriz

void printMatrix(int **matrix, int size) {
    printf("Matrix (%dx%d):\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]); 
        }
        printf("\n"); 
    }
}

//Funcion para calcular la matriz transpuesta

void matriztranspuesta(int **matrix, int ***transpuesta, int size) {
    allocateMatrix(transpuesta, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            (*transpuesta)[j][i] = matrix[i][j];
        }
    }
}

//Funcion para liberar la memoria asignada de una matriz

void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}


int main() {
    int size;
    //Solicitar al usuario ingresar el tamano de la matriz
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &size);

    int **matrix = NULL, **transpuesta = NULL;
    int largestLine = 0, largestLineTranspuesta = 0;

    //Llenar la matriz con valores aleatorios
    allocateMatrix(&matrix, size);
    fillMatrix(matrix, size);
    //Imprimir matriz original y calcular la secuencia de 1s mas larga
    printf("\nMatriz original:\n");
    printMatrix(matrix, size);
    findLargestLine(matrix, size, &largestLine);
    printf("La secuencia de 1s más larga en la matriz original es: %d\n", largestLine);

    //Calcular la matriz transpuesta
    matriztranspuesta(matrix, &transpuesta, size);

    //Imprimir y calcular la cantidad de 1s consecutivos de la matriz transpuesta
    printf("\nMatriz transpuesta:\n");
    printMatrix(transpuesta, size);
    findLargestLine(transpuesta, size, &largestLineTranspuesta);
    printf("La secuencia de 1s más larga en la matriz transpuesta es: %d\n", largestLineTranspuesta);

    //Liberación de memoria
    freeMatrix(matrix, size);
    freeMatrix(transpuesta, size);

    return 0;
}







