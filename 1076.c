#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int T;
    int adj[MAX][MAX]; 
    
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int inicio, V, A;
        int u, v;
        int arestas = 0;

        scanf("%d", &inicio);

        scanf("%d %d", &V, &A);

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < A; i++) {
            scanf("%d %d", &u, &v);

            if (adj[u][v] == 0) {
                arestas++;
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
        }
        printf("%d\n", arestas * 2);
    }

    return 0;
}
