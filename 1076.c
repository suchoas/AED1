#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100

int main() {
    int T;
    int adj[MAX_V][MAX_V]; 
    
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int inicio, V, A;
        int u, v;
        int arestas_unicas = 0;

        scanf("%d", &inicio);

        scanf("%d %d", &V, &A);

        for (int i = 0; i < MAX_V; i++) {
            for (int j = 0; j < MAX_V; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < A; i++) {
            scanf("%d %d", &u, &v);

            if (adj[u][v] == 0) {
                arestas_unicas++;
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
        }
        printf("%d\n", arestas_unicas * 2);
    }

    return 0;
}
