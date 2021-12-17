#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "compute.h"

int sort_asc(const void *a, const void *b) {
    double *x = (double *)a;
    double *y = (double *)b;

    if (*x < *y)
        return -1;
    else if (*x > *y)
        return 1;
    return 0;
}

int sort_desc(const void *a, const void *b) {
    double *x = (double *)a;
    double *y = (double *)b;

    if (*x > *y)
        return -1;
    else if (*x < *y)
        return 1;
    return 0;
}

void compute(double **array, int size, int singlerow) {
    double *nsum = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++)
        nsum[i] = 0;
    double prod = 1;
    int pcount;
    double *pgmean = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++)
        pgmean[i] = 1;
    double *sdiag = (double *)malloc(size * sizeof(double));
    FILE *file = fopen("dataout.txt", "a");

    for (int i = 0; i < size; i++) {
        pcount = 0;
        for (int j = 0; j < size; j++) {
            double num;
            if (singlerow)
                num = *(*array + i * size + j);
            else
                num = array[i][j];

            if (num < 0)
                nsum[j] += num; // negative elem summ in each column
            else if (num >= 0) {
                pgmean[i] *= num; // pos elem g-mean in each row
                pcount++;
            }

            if (i <= size - j - 1) {
                if (i == size - j - 1) // side diag
                    sdiag[j] = num;

                prod *= num; // product of triangle matrix
            }
        }
        if (pcount)
            pgmean[i] = pow(pgmean[i], 1.0 / pcount);
    }

    // 1
    puts("Summa otritsatelnyh elem v kazhdom stolbtse:");
    fputs("Summa otritsatelnyh elem v kazhdom stolbtse:\n", file);
    for (int i = 0; i < size; i++) {
        printf("%4.1lf%c", nsum[i], i == size - 1 ? '\n' : ' ');
        fprintf(file, "%4.1lf%c", nsum[i], i == size - 1 ? '\n' : ' ');
    }

    // 2
    puts("Proizvedeniye elem verhney treugolnoy matritsy vishe pobochnoy "
         "diagonali:");
    fputs("Proizvedeniye elem verhney treugolnoy matritsy vishe pobochnoy "
          "diagonali:\n",
          file);
    printf(" %.3lf\n", prod);
    fprintf(file, " %.3lf\n", prod);

    // 3
    puts("Srednee geometricheskoye polozhitelnih elem v kazhdoy stroke:");
    fputs("Srednee geometricheskoye polozhitelnih elem v kazhdoy stroke:\n",
          file);
    for (int i = 0; i < size; i++) {
        printf("%4.1lf%c", pgmean[i], i == size - 1 ? '\n' : ' ');
        fprintf(file, "%4.1lf%c", pgmean[i], i == size - 1 ? '\n' : ' ');
    }
    qsort(pgmean, size, sizeof(double), sort_desc);
    puts("Posle sortirovki po ubivaniyu:");
    fputs("Posle sortirovki po ubivaniyu:\n", file);
    for (int i = 0; i < size; i++) {
        printf("%4.1lf%c", pgmean[i], i == size - 1 ? '\n' : ' ');
        fprintf(file, "%4.1lf%c", pgmean[i], i == size - 1 ? '\n' : ' ');
    }

    // 4
    puts("Pobochnaya diagonal:");
    fputs("Pobochnaya diagonal:\n", file);
    for (int i = 0; i < size; i++) {
        printf("%4.1lf%c", sdiag[i], i == size - 1 ? '\n' : ' ');
        fprintf(file, "%4.1lf%c", sdiag[i], i == size - 1 ? '\n' : ' ');
    }
    qsort(sdiag, size, sizeof(double), sort_asc);
    puts("Posle sortirovki po vozrastaniyu:");
    fputs("Posle sortirovki po vozrastaniyu:\n", file);
    for (int i = 0; i < size; i++) {
        printf("%4.1lf%c", sdiag[i], i == size - 1 ? '\n' : ' ');
        fprintf(file, "%4.1lf%c", sdiag[i], i == size - 1 ? '\n' : ' ');
    }

    fputs("\n", file);

    free(nsum);
    free(pgmean);
    free(sdiag);
    fclose(file);
}
