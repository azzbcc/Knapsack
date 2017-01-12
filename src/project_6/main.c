#include <common.h>

int main()
{
    int n, V, K;  // declare n items and capacity V、U

    freopen("stdin", "r", stdin);
    while (3 == scanf("%d%d%d", &n, &V, &K) && n && V)
    {
        int c[n], w[n], f[V + 1], sk[n][n + 1];

        for (int i = 0; i < n; ++i) scanf("%d%d", &c[i], &w[i]);
        for (int i = 0; i < K; ++i)
        {
            scanf("%d", &sk[i][0]);
            for (int j = 1; j <= sk[i][0]; ++j) scanf("%d", &sk[i][j]);
        }

        // initialize
        memset(f, 0, (V + 1) * sizeof(f[0]));

        // calculate
        for (int k = 0; k < K; ++k)
        {
            for (int v = V; v >= 0; --v)
            {
                for (int i = 1; i <= sk[k][0]; ++i)
                {
                    int item = sk[k][i] - 1;
                    if (v >= c[item]) f[v] = max(f[v], f[v - c[item]] + w[item]);
                }
            }
        }

        display(f, 1, V + 1);
    }

    return 0;
}