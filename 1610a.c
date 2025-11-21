#include <stdio.h>
#include <string.h>

#define max_n 10005

char adj[max_n][max_n];
int cor[max_n];
int ciclo;

void dfs(int u, int n) {
    cor[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v]) {
            if (cor[v] == 1) {
                ciclo = 1;
                return;
            }
            if (cor[v] == 0) {
                dfs(v, n);
                if (ciclo) return;
            }
        }
    }
    cor[u] = 2;
}

int main() {
    int t, n, m, a, b;

    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            memset(adj[i], 0, (n + 1) * sizeof(char));
            cor[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            if (a <= n && b <= n) {
                adj[a][b] = 1;
            }
        }

        ciclo = 0;
        for (int i = 1; i <= n; i++) {
            if (cor[i] == 0) {
                dfs(i, n);
                if (ciclo) break;
            }
        }

        if (ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
