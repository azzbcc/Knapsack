/*
 * 当问题是“每种有若干件的物品能否填满给定容量的背包”,只须考虑填满背包的
 * 可行性,不需考虑每件物品的价值时,多重背包问题同样有 O(V N ) 复杂度的算法。
 */

#include <common.h>

int main()
{
    int n, V;  // declare n items and capacity V

    freopen("stdin", "r", stdin);
    while (2 == scanf("%d%d", &n, &V) && n && V)
    {
        int m[n + 1], c[n + 1], f[n + 1][V + 1];

        // initialize
        f[0][0] = 0;
        for (int i = 1; i <= V; f[0][i++] = -1);
        for (int i = 1; i <= n; ++i) scanf("%d%d", &m[i], &c[i]);

        // calculate
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= V; ++j)
            {
                f[i][j] = f[i - 1][j] >= 0 ? m[i] : -1;
            }
            for (int j = 0; j <= V - c[i]; ++j)
            {
                if (f[i][j] > 0) f[i][j + c[i]] = max(f[i][j + c[i]], f[i][j] - 1);
            }
        }

        display(f[0], n + 1, V + 1);
    }

    return 0;
}