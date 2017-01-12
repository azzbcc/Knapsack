#include <common.h>

int main()
{
    int n, V;  // declare n items and capacity V

    freopen("../stdin", "r", stdin);
    while (2 == scanf("%d%d", &n, &V) && n && V)
    {
        int m[n], c[n], w[n], f[n][V + 1];

        // initialize
        memset(f, 0, n * sizeof(f[0]));
        for (int i = 0; i < n; ++i) scanf("%d%d%d", &m[i], &c[i], &w[i]);

        // calculate
        for (int i = 0; i < n; ++i)
        {
            for (int v = c[i]; v <= V; ++v)
            {
                int tmp = 0;
                for (int k = 0; k <= min(m[i], v / c[i]); ++k)
                {
                    if (!i) tmp = k * w[i];
                    else tmp = max(tmp, f[i - 1][v - k * c[i]] + k * w[i]);
                }
                f[i][v] = tmp;
            }
        }

        display(f[0], n, V + 1);
    }

    return 0;
}