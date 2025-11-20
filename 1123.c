#include <stdio.h>

#define INFINITO 0x3f3f3f3f
#define MAX_CIDADES 255

int matriz_custos[MAX_CIDADES][MAX_CIDADES];
int custo_minimo[MAX_CIDADES];
int verificado[MAX_CIDADES];

int encontrar_menor_custo(int n, int origem, int destino) {
    int i, j;
    
    for (i = 0; i < n; i++) {
        custo_minimo[i] = INFINITO;
        verificado[i] = 0;
    }
    custo_minimo[origem] = 0;

    for (i = 0; i < n; i++) {
        int cidade_atual = -1;
        int menor_valor = INFINITO;

        for (j = 0; j < n; j++) {
            if (!verificado[j] && custo_minimo[j] < menor_valor) {
                menor_valor = custo_minimo[j];
                cidade_atual = j;
            }
        }

        if (cidade_atual == -1 || cidade_atual == destino) break;

        verificado[cidade_atual] = 1;

        for (j = 0; j < n; j++) {
            if (matriz_custos[cidade_atual][j] != INFINITO) {
                if (custo_minimo[cidade_atual] + matriz_custos[cidade_atual][j] < custo_minimo[j]) {
                    custo_minimo[j] = custo_minimo[cidade_atual] + matriz_custos[cidade_atual][j];
                }
            }
        }
    }

    return custo_minimo[destino];
}

int main() {
    int N, M, C, K;
    int u, v, p;
    int i, j;

    while (scanf("%d %d %d %d", &N, &M, &C, &K) && (N || M || C || K)) {
        
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                matriz_custos[i][j] = INFINITO;
            }
        }

        for (i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &p);
            if (p < matriz_custos[u][v]) { 
                matriz_custos[u][v] = p;
                matriz_custos[v][u] = p;
            }
        }

        for (i = 0; i < C - 1; i++) {
            int custo_rota = matriz_custos[i][i+1];
            
            for (j = 0; j < N; j++) {
                matriz_custos[i][j] = INFINITO;
            }
            
            matriz_custos[i][i+1] = custo_rota;
        }

        int resultado = encontrar_menor_custo(N, K, C - 1);

        printf("%d\n", resultado);
    }

    return 0;
}
