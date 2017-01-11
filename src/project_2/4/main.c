#include <common.h>

int main()
{
    int n, V;  // declare n items and capacity V

    freopen("../stdin", "r", stdin);
    while (2 == scanf("%d%d", &n, &V) && n && V)
    {
        int c[n], w[n], f[V + 1];

        // initialize
        memset(f, 0, (V + 1) * sizeof(f[0]));
        for (int i = 0; i < n; ++i) scanf("%d%d", &c[i], &w[i]);

        // calculate
        for (int i = 0; i < n; ++i)
        {
            for (int v = c[i]; v <= V; ++v)
            {
                f[v] = max(f[v], f[v - c[i]] + w[i]);
            }
        }

        display(f, 1, V + 1);
    }

    return 0;
}