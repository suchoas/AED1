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

void inicializar(int m) {
    for (int i = 0; i < m; i++) {
        pai[i] = i;
    }
}

int encontrar(int i) {
    if (pai[i] == i) return i;
    return pai[i] = encontrar(pai[i]);
}

int unir(int i, int j) {
    int raiz_i = encontrar(i);
    int raiz_j = encontrar(j);

    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
        return 1;
    }
    return 0;
}

int comparar(const void *a, const void *b) {
    Aresta *x = (Aresta *)a;
    Aresta *y = (Aresta *)b;
    if(x->custo < y->custo) return -1;
    else
        return 1;
    return 0;
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        
        int total = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].custo);
            total += arestas[i].custo;
        }

        qsort(arestas, n, sizeof(Aresta), comparar);

        inicializar(m);

        int custo_mst = 0;
        int selecionadas = 0;

        for (int i = 0; i < n; i++) {
            if (unir(arestas[i].origem, arestas[i].destino)) {
                custo_mst += arestas[i].custo;
                selecionadas++;
            }
            
            if (selecionadas == m - 1) break;
        }

        printf("%d\n", total - custo_mst);
    }

    return 0;
}
