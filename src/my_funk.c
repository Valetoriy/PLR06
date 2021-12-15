#include "my_funk.h"
#include "compute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 5

// v tele programmi
void f1() {
    double sarr[N][N] = {{3, 9, 5, 8, 0},
                         {-7, 0, -9, 9, 5},
                         {0, -7, 3, 4, 3},
                         {9, 4, 1, 3, 7},
                         {2, 6, -7, 4, 9}};
    double *array = (double *)malloc(N * N * sizeof(double));
    memcpy(array, sarr, N * N * sizeof(double));

    compute(&array, 1); // ???

    free(array);
};

// vvod s ekrana
void f2() {
    int n;
    puts("Vvedite N dlya matritsi NxN elem.:");
    scanf("%d", &n);

    // allocate memory
    double **array = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        array[i] = (double *)malloc(n * sizeof(double));

    compute(array, n);

    // free allocated memory
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
};

// schitivaniye iz faila
void f3() {
    int n;
    puts("Vvedite N dlya matritsi NxN elem.:");
    scanf("%d", &n);

    // allocate memory
    double **array = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
        array[i] = (double *)malloc(n * sizeof(double));

    compute(array, n);

    // free allocated memory
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
};

// generatsiya randomnih chisel
void f4() {
    srand(time(NULL));

    int n = rand() % 10 + 1;
    printf("N = %d\n", n);

    // allocate memory and print the array
    double **array = (double **)malloc(n * sizeof(double *));
    printf("N ");
    for (int i = 0; i < n; i++)
        printf("%2d%c", i, i == n - 1 ? '\n' : ' ');
    for (int i = 0; i < n; i++) {
        array[i] = (double *)malloc(n * sizeof(double));
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 10;
            if (!(rand() % 3))
                array[i][j] *= -1;
            printf("%2.0lf%c", array[i][j], j == n - 1 ? '\n' : ' ');
        }
    }

    compute(array, n);

    // free allocated memory
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
};
