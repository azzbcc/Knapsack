#include <common.h>

int main()
{
    int n, V;  // declare n items and capacity V

    freopen("../stdin", "r", stdin);
    while (2 == scanf("%d%d", &n, &V) && n && V)
    {
        int c[n], w[n], f[n][V + 1];

        // initialize
        memset(f, 0, n * sizeof(f[0]));
        for (int i = 0; i < n; ++i) scanf("%d%d", &c[i], &w[i]);

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