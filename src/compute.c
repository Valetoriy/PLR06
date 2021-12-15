#include <limits.h>
#include <stdio.h>

#include "compute.h"

void compute12(int *array) {
    int mine = INT_MAX, maxe = INT_MIN;
    int firstpi = -1, lastpi = -1, summ = 0;
    for (int i = 0; i < 10; i++) {
        int num = array[i];

        // min && max elem
        if (num < mine)
            mine = num;
        if (num > maxe)
            maxe = num;

        // positive elem indexes
        if (num > 0) {
            if (firstpi == -1)
                firstpi = i;
            lastpi = i;
        }
    }

    for (int i = firstpi + 1; i < lastpi; i++)
        summ += array[i];

    printf("Min elem. massiva = %d, max elem. massiva = %d\n", mine, maxe);
    printf("Summa elem. mezhdu pervim i poslednim polozh. elem. = %d\n", summ);

    // write to file
    FILE *file = fopen("dataout.txt", "a");
    fprintf(file, "Min elem. massiva = %d, max elem. massiva = %d\n", mine,
            maxe);
    fprintf(file, "Summa elem. mezhdu pervim i poslednim polozh. elem. = %d\n",
            summ);
    fclose(file);
}

void compute3(int *a, int *b, int *c, int r) {
    int x[10], y[10];
    for (int i = 0; i < 10; i++) {
        // x(i) = max(a(9-i), b(i), r)
        if (a[9 - i] > b[i]) {
            if (a[9 - i] > r)
                x[i] = a[9 - i];
            else
                x[i] = r;
        } else {
            if (b[i] > r)
                x[i] = b[i];
            else
                x[i] = r;
        }
        // y(i) = max(b(9-i), c(i), r)
        if (b[9 - i] > c[i]) {
            if (b[9 - i] > r)
                y[i] = b[9 - i];
            else
                y[i] = r;
        } else {
            if (c[i] > r)
                y[i] = c[i];
            else
                y[i] = r;
        }
    }

    printf("X = ");
    for (int i = 0; i < 10; i++)
        printf("%d%c", x[i], i == 9 ? '\n' : ' ');
    printf("Y = ");
    for (int i = 0; i < 10; i++)
        printf("%d%c", y[i], i == 9 ? '\n' : ' ');

    // write to file
    FILE *file = fopen("dataout.txt", "a");
    fprintf(file, "X = ");
    for (int i = 0; i < 10; i++)
        fprintf(file, "%d%c", x[i], i == 9 ? '\n' : ' ');
    fprintf(file, "Y = ");
    for (int i = 0; i < 10; i++)
        fprintf(file, "%d%c", y[i], i == 9 ? '\n' : ' ');
    fprintf(file, "\n");
    fclose(file);
};
