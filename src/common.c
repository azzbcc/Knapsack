#include <common.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

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

void completePack(int *f, int c, int w, int v)
{
    for (int i = c; i <= v; ++i)
    {
        f[i] = max(f[i], f[i - c] + w);
    }
}

void multiplePack(int *f, int c, int w, int m, int v)
{
    // 当数量×占用空间不小于容量时，可以看作完全背包问题
    if (c * m >= v)
    {
        completePack(f, c, w, v);
        return;
    }

    int k = 1;
    while (k < m)
    {
        zeroOnePack(f, k * c, k * w, v);
        m -= k;
        k *= 2;
    }
    zeroOnePack(f, m * c, m * w, v);
}