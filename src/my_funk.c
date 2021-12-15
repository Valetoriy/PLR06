#include "my_funk.h"
#include "compute.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// v tele programmi
void f1() {
    int n = 5;
    double *array = (double*)malloc(n * n * sizeof(double));
    free(array);
};

// vvod s ekrana
void f2() {
    int n;
    puts("Vvedite N dlya matritsi NxN elem.:");
    scanf("%d", &n);

    // allocate memory
    double **array = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
        array[i] = (double*)malloc(n * sizeof(double));

    // free allocated memory
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
};

// schitivaniye iz faila
void f3() {
};

// generatsiya randomnih chisel
void f4() {
};
