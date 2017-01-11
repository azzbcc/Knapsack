#include <common.h>

#define MAX 128

int main()
{
    int n, V;  // declare n items and capacity V

    freopen("../stdin", "r", stdin);
    while (2 == scanf("%d%d", &n, &V) && n && V)
    {
        int c[MAX], w[MAX], f[MAX][V + 1];

        // initialize
        memset(f, 0, MAX * sizeof(f[0]));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &c[i], &w[i]);
            while (w[i] * 2 <= V)
            {
                c[i + 1] = c[i] * 2, w[i + 1] = w[i] * 2;
                i++, n++;
            }
        }

        // calculate
        for (int i = 0; i < n; ++i)
        {
            for (int v = c[i]; v <= V; ++v)
            {
                if (!i) f[i][v] = w[i];
                else f[i][v] = max(f[i - 1][v], f[i - 1][v - c[i]] + w[i]);
            }
        }

        display(f[0], n, V + 1);
    }

    return 0;
}