#include <common.h>

int main()
{
    int n, V, U;  // declare n items and capacity V、U

    freopen("stdin", "r", stdin);
    while (3 == scanf("%d%d%d", &n, &V, &U) && n && V && U)
    {
        int c[n], d[n], w[n], f[V + 1][U + 1];

        for (int i = 0; i < n; ++i) scanf("%d%d%d", &c[i], &d[i], &w[i]);

        // zero one pack problem

        // initialize
        memset(f, 0, (V + 1) * sizeof(f[0]));

        // calculate
        for (int i = 0; i < n; ++i)
        {
            for (int v = V; v >= c[i]; --v)
            {
                for (int u = U; u >= d[i]; --u)
                {
                    f[v][u] = max(f[v][u], f[v - c[i]][u - d[i]] + w[i]);
                }
            }
        }

        display(f[0], V + 1, U + 1);

        // complete pack problem

        // initialize
        memset(f, 0, (V + 1) * sizeof(f[0]));

        // calculate
        for (int i = 0; i < n; ++i)
        {
            for (int v = c[i]; v <= V; ++v)
            {
                for (int u = d[i]; u <= U; ++u)
                {
                    f[v][u] = max(f[v][u], f[v - c[i]][u - d[i]] + w[i]);
                }
            }
        }

        display(f[0], V + 1, U + 1);
    }

    return 0;
}