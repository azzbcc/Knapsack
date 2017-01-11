#include <common.h>

bool check(int *c, int *w, int p, int v)
{
    if (w[p] > v) return true;
    for (int i = 0; i < p; ++i)
    {
        if (c[i] <= c[p] && w[i] >= w[p]) return true;
    }
    return false;
}

int main()
{
    int n, V;  // declare n items and capacity V

    freopen("../stdin", "r", stdin);
    while (2 == scanf("%d%d", &n, &V) && n && V)
    {
        int c[n], w[n], f[n][V + 1];

        // initialize
        memset(f, 0, n * sizeof(f[0]));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &c[i], &w[i]);
            if (check(c, w, i, V)) i--, n--;
        }

        // calculate
        for (int i = 0; i < n; ++i)
        {
            for (int v = c[i]; v <= V; ++v)
            {
                int m = 0;
                for (int k = 0; k <= v / c[i]; ++k)
                {
                    if (!i) m = k * w[i];
                    else m = max(m, f[i - 1][v - k * c[i]] + k * w[i]);
                }
                f[i][v] = m;
            }
        }

        display(f[0], n, V + 1);
    }

    return 0;
}