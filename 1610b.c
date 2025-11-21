#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_n 10005
#define max_m 30005

int head[max_n];
int to[max_m];
int prox[max_m];
int aresta_cnt;

int cor[max_n]; 
int ciclo;

void init(int n) {
    memset(head, -1, (n + 1) * sizeof(int));
    memset(cor, 0, (n + 1) * sizeof(int));
    aresta_cnt = 0;
    ciclo = 0;
}

void add(int u, int v) {
    to[aresta_cnt] = v;
    prox[aresta_cnt] = head[u];
    head[u] = aresta_cnt++;
}

void dfs(int u) {
    cor[u] = 1; 
    for (int i = head[u]; i != -1; i = prox[i]) {
        int v = to[i];
        if (cor[v] == 1) {
            ciclo = 1;
            return;
        }
        if (cor[v] == 0) {
            dfs(v);
            if (ciclo) return;
        }
    }
    cor[u] = 2; 
}

int main() {
    int t, n, m, a, b;
    
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        scanf("%d %d", &n, &m);
        
        init(n);

        while (m--) {
            scanf("%d %d", &a, &b);
            add(a, b);
        }

        for (int i = 1; i <= n; i++) {
            if (cor[i] == 0) {
                dfs(i);
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
