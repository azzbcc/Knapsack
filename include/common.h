#ifndef KNAPSACK_COMMON_H
#define KNAPSACK_COMMON_H

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

int min(int, int);

int max(int, int);

void display(int *f, int row, int col);

void zeroOnePack(int *f, int c, int w, int v);

void completePack(int *f, int c, int w, int v);

void multiplePack(int *f, int c, int w, int m, int v);

#endif //KNAPSACK_COMMON_H
