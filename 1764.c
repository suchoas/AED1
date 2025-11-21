#include <stdio.h>
#include <stdlib.h>

#define max_cidades 40005
#define max_rotas 50005

typedef struct {
    int u;
    int v;
    int peso;
} aresta;

int pai[max_cidades];
int rank[max_cidades];
aresta arestas[max_rotas];

int comparar(const void *a, const void *b) {
    aresta *aa = (aresta *)a;
    aresta *bb = (aresta *)b;
    return aa->peso - bb->peso;
}

void inicializa(int m) {
    for (int i = 0; i < m; i++) {
        pai[i] = i;
        rank[i] = 0;
    }
}

int find_set(int i) {
    if (pai[i] != i) {
        pai[i] = find_set(pai[i]);
    }
    return pai[i];
}

void union_sets(int i, int j) {
    int raiz_i = find_set(i);
    int raiz_j = find_set(j);

    if (raiz_i != raiz_j) {
        if (rank[raiz_i] > rank[raiz_j]) {
            pai[raiz_j] = raiz_i;
        } else {
            pai[raiz_i] = raiz_j;
            if (rank[raiz_i] == rank[raiz_j]) {
                rank[raiz_j]++;
            }
        }
    }
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }

        qsort(arestas, n, sizeof(aresta), comparar);

        inicializa(m);

        int custo = 0;
        int arestas_selecionadas = 0;

        for (int i = 0; i < n; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;

            if (find_set(u) != find_set(v)) {
                union_sets(u, v);
                custo += arestas[i].peso;
                arestas_selecionadas++;
            }
            
            if (arestas_selecionadas == m - 1) break;
        }

        printf("%d\n", custo);
    }

    return 0;
}
