#include <common.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void display(int *f, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%2d%c", f[i * col + j], "\n "[j < col - 1]);
        }
    }
    printf("max: %d\n\n", f[row * col - 1]);
}

void zeroOnePack(int *f, int c, int w, int v)
{
    for (int i = v; i >= c; --i)
    {
        f[i] = max(f[i], f[i - c] + w);
    }
}