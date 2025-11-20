#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 200005
#define MAX_ARESTAS 200005

typedef struct {
    int origem;
    int destino;
    int custo;
} Aresta;

Aresta arestas[MAX_ARESTAS];
int pai[MAX_VERTICES];

void inicializar_conjuntos(int m) {
    for (int i = 0; i < m; i++) {
        pai[i] = i;
    }
}

int encontrar_raiz(int i) {
    if (pai[i] == i) return i;
    return pai[i] = encontrar_raiz(pai[i]);
}

int unir_conjuntos(int i, int j) {
    int raiz_i = encontrar_raiz(i);
    int raiz_j = encontrar_raiz(j);

    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
        return 1;
    }
    return 0;
}

int comparar_arestas(const void *a, const void *b) {
    return ((Aresta*)a)->custo - ((Aresta*)b)->custo;
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        
        int custo_total_inicial = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].custo);
            custo_total_inicial += arestas[i].custo;
        }

        qsort(arestas, n, sizeof(Aresta), comparar_arestas);

        inicializar_conjuntos(m);

        int custo_mst = 0;
        int arestas_selecionadas = 0;

        for (int i = 0; i < n; i++) {
            if (unir_conjuntos(arestas[i].origem, arestas[i].destino)) {
                custo_mst += arestas[i].custo;
                arestas_selecionadas++;
            }
            
            if (arestas_selecionadas == m - 1) break;
        }

        printf("%d\n", custo_total_inicial - custo_mst);
    }

    return 0;
}
