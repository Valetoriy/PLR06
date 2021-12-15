#include "functions.h"
#include <stdio.h>

int main() {

    int n = 0;

    puts("Zadacha №16, Krylov Artem Vyacheslavovich, IKPI-14");

    void (*arr[])() = {f1, f2, f3, f4};

    do {
        puts("Viberite vvod ishodnih dannih:\n"
             "    1) V tele programmi\n"
             "    2) C ekrana\n"
             "    3) Iz faila\n"
             "    4) S ispolzovaniem generatsii (psevdo)sluchaynih chisel\n"
             "Dlya zaversheniya raboti vvetide 0");
        scanf("%d", &n);
        if (n)
            arr[n - 1]();
        puts("");

    } while (n);

    return 0;
}
