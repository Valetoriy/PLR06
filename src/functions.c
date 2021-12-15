#include "functions.h"
#include "compute.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// v tele programmi
void f1() {
    int array[10] = {-2, 7, -5, 3, 1, 3, 9, 5, 8, 0};
    int a[10] = {8, 6, 1, -2, -7, -7, 0, -9, 9, 5};
    int b[10] = {-5, -2, 4, 6, 4, 0, -7, 3, 4, 3};
    int c[10] = {-5, 0, 0, 1, -8, 9, 4, 1, 3, 7};
    int r = 3;

    compute12(array);
    compute3(a, b, c, r);
};

// vvod s ekrana
void f2() {
    int array[10], a[10], b[10], c[10], r;

    puts("Vvedie znacheniya elem. massiva (10 elem.):");
    for (int i = 0; i < 10; i++)
        scanf("%d", array + i);
    compute12(array);

    puts("Vvedie znacheniya elem. A (10 elem.):");
    for (int i = 0; i < 10; i++)
        scanf("%d", a + i);
    puts("Vvedie znacheniya elem. B (10 elem.):");
    for (int i = 0; i < 10; i++)
        scanf("%d", b + i);
    puts("Vvedie znacheniya elem. C (10 elem.):");
    for (int i = 0; i < 10; i++)
        scanf("%d", c + i);
    puts("Vvedie znachenie R:");
    scanf("%d", &r);
    compute3(a, b, c, r);
};

// schitivaniye iz faila
void f3() {
    int array[10], a[10], b[10], c[10], r;
    FILE *file = fopen("data.txt", "r");

    for (int i = 0; i < 10; i++)
        fscanf(file, "%d", array + i);
    compute12(array);

    for (int i = 0; i < 10; i++)
        fscanf(file, "%d", a + i);
    for (int i = 0; i < 10; i++)
        fscanf(file, "%d", b + i);
    for (int i = 0; i < 10; i++)
        fscanf(file, "%d", c + i);
    fscanf(file, "%d", &r);
    compute3(a, b, c, r);

    fclose(file);
};

// generatsiya randomnih chisel
void f4() {
    int array[10], a[10], b[10], c[10], r;
    srand(time(NULL));

    printf("Massiv = ");
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 10;
        if (!(rand() % 3))
            array[i] *= -1;
        printf("%d%c", array[i], i == 9 ? '\n' : ' ');
    }
    compute12(array);

    printf("A = ");
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 10;
        if (!(rand() % 3))
            a[i] *= -1;
        printf("%d%c", a[i], i == 9 ? '\n' : ' ');
    }
    printf("B = ");
    for (int i = 0; i < 10; i++) {
        b[i] = rand() % 10;
        if (!(rand() % 3))
            b[i] *= -1;
        printf("%d%c", b[i], i == 9 ? '\n' : ' ');
    }
    printf("C = ");
    for (int i = 0; i < 10; i++) {
        c[i] = rand() % 10;
        if (!(rand() % 3))
            c[i] *= -1;
        printf("%d%c", c[i], i == 9 ? '\n' : ' ');
    }
    r = rand() % 10;
    if (!(rand() % 3))
        r *= -1;
    printf("R = %d\n", r);
    compute3(a, b, c, r);
};
