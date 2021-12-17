#include "my_funk.h"
#include "compute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5

// v tele programmi
void f1() {
    double sarr[N][N] = {{3.3, 9.9, 5.5, 8.8, 0.0},
                         {-1.1, 0.0, -9.9, 9.9, 5.5},
                         {0.0, -7.7, 3.3, 4.4, 3.3},
                         {9.9, 4.4, 1.1, 3.3, 7.7},
                         {2.2, 6.6, -8.8, 4.4, 9.9}};
    double *array = (double *)malloc(N * N * sizeof(double));
    memcpy(array, sarr, N * N * sizeof(double));

    compute(&array, N, 1);

    free(array);
};

// vvod s ekrana
void f2() {
    int n;
    puts("Vvedite N dlya matritsi NxN elem:");
    scanf("%d", &n);

    // allocate memory and get the array from console
    double **array = (double **)malloc(n * sizeof(double *));
    printf("Vvedite zhacheniya elem matritsi %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        array[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &(array[i][j]));
        }
    }

    compute(array, n, 0);

    // free allocated memory
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
};

// schitivaniye iz faila
void f3() {
    int n;
    FILE *file = fopen("data.txt", "r");
    fscanf(file, "%d", &n);

    // allocate memory and get the array from file
    double **array = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        array[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            fscanf(file, "%lf", &(array[i][j]));
        }
    }

    compute(array, n, 0);

    // free allocated memory
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);

    fclose(file);
};

// generatsiya randomnih chisel
void f4() {
    srand(time(NULL));

    int n = rand() % 10 + 1;
    printf("N = %d\n", n);

    // allocate memory and print the array
    double **array = (double **)malloc(n * sizeof(double *));
    printf("N");
    for (int i = 0; i < n; i++)
        printf("%4d%c", i, i == n - 1 ? '\n' : ' ');
    for (int i = 0; i < n; i++) {
        array[i] = (double *)malloc(n * sizeof(double));
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 10;
            array[i][j] += array[i][j] * 0.1;
            if (!(rand() % 3) && array[i][j])
                array[i][j] *= -1;
            printf("%4.1lf%c", array[i][j], j == n - 1 ? '\n' : ' ');
        }
    }

    compute(array, n, 0);

    // free allocated memory
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
};
