#ifndef KNAPSACK_COMMON_H
#define KNAPSACK_COMMON_H

#include <stdio.h>
#include <limits.h>
#include <string.h>

int max(int, int);

void display(int *f, int row, int col);

void zeroOnePack(int *f, int c, int w, int v);

#endif //KNAPSACK_COMMON_H
