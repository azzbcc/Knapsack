#include <common.h>

#define MAX 128

int main()
{
    int n, V;  // declare n items and capacity V

    freopen("../stdin", "r", stdin);
    while (2 == scanf("%d%d", &n, &V) && n && V)
    {
        int m[n], c[MAX], w[MAX], f[V + 1];

        // initialize
        memset(f, 0, (V + 1) * sizeof(f[0]));
        for (int i = 0, p = 0; i < n; ++i, ++p)
        {
            scanf("%d%d%d", &m[p], &c[i], &w[i]);

            int k = 1;
            while (k * 2 <= m[p])
            {
                c[i + 1] = c[i] * 2, w[i + 1] = w[i] * 2;
                i++, n++, k *= 2;
            }
            if (m[p] > k)
            {
                c[i + 1] = c[i] / k * (m[p] - k), w[i + 1] = w[i] / k * (m[p] - k);
                i++, n++;
            }
        }

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