#include <stdio.h>

#define MAX 1025

typedef struct {
    int l, c;
} ponto;

char imagem[MAX][MAX];
int N, M;

ponto pilha[MAX * MAX];
int topo = 0;

void empilha(int l, int c) {
    pilha[topo].l = l;
    pilha[topo].c = c;
    topo++;
}

ponto desempilha() {
    return pilha[--topo];
}

void colorir_regiao(int l_inicial, int c_inicial) {
    empilha(l_inicial, c_inicial);
    imagem[l_inicial][c_inicial] = 'o';

    int dl[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (topo > 0) {
        ponto atual = desempilha();
        int l = atual.l;
        int c = atual.c;

        for (int k = 0; k < 4; k++) {
            int nl = l + dl[k];
            int nc = c + dc[k];

            if (nl >= 0 && nl < N && nc >= 0 && nc < M && imagem[nl][nc] == '.') {
                imagem[nl][nc] = 'o';
                empilha(nl, nc);
            }
        }
    }
}

int main() {
    int cliques = 0;
    int i, j;

    if (scanf("%d %d", &N, &M) != 2) return 0;

    for (i = 0; i < N; i++) {
        scanf("%s", imagem[i]);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (imagem[i][j] == '.') {
                cliques++;
                colorir_regiao(i, j);
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
