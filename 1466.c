#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

no* criar_no(int v) {
    no* novo = (no*)malloc(sizeof(no));
    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

no* inserir(no* raiz, int v) {
    if (raiz == NULL) return criar_no(v);
    if (v < raiz->valor)
        raiz->esq = inserir(raiz->esq, v);
    else
        raiz->dir = inserir(raiz->dir, v);
    return raiz;
}

void liberar(no* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

void bfs(no* raiz) {
    if (raiz == NULL) return;

    no* fila[505];
    int inicio = 0;
    int fim = 0;

    fila[fim++] = raiz;
    int primeiro = 1;

    while (inicio < fim) {
        no* atual = fila[inicio++];
        
        if (!primeiro) printf(" ");
        printf("%d", atual->valor);
        primeiro = 0;

        if (atual->esq != NULL) fila[fim++] = atual->esq;
        if (atual->dir != NULL) fila[fim++] = atual->dir;
    }
    printf("\n\n");
}

int main() {
    int c, n, v;
    
    scanf("%d", &c);

    for (int i = 1; i <= c; i++) {
        scanf("%d", &n);
        
        no* raiz = NULL;
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &v);
            raiz = inserir(raiz, v);
        }

        printf("Case %d:\n", i);
        bfs(raiz);
        liberar(raiz);
    }

    return 0;
}
