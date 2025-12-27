#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} celula;

void BuscaERemove (int x, celula *lst) {
    celula *p, *q;
    p = lst;
    q = lst->seg;
    while (q != NULL && q->conteudo != x) {
        p = q;
        q = q->seg;
    }
    if (q != NULL) {
        p->seg = q->seg;
        free (q);
    }
}

void InsereNoFim(celula **fim, int valor) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->seg = NULL;
    
    (*fim)->seg = nova;
    *fim = nova;
}

void Imprime(celula *lst) {
    celula *p;
    int primeiro = 1;
    for (p = lst->seg; p != NULL; p = p->seg) {
        if (!primeiro) printf(" ");
        printf("%d", p->conteudo);
        primeiro = 0;
    }
    printf("\n");
}

int main() {
    int N, M, id;
    
    celula *lista = malloc(sizeof(celula));
    lista->seg = NULL;
    celula *fim = lista; 

    if (scanf("%d", &N) != 1) return 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &id);
        InsereNoFim(&fim, id);
    }

    if (scanf("%d", &M) == 1) {
        for (int i = 0; i < M; i++) {
            scanf("%d", &id);
            BuscaERemove(id, lista);
        }
    }
    Imprime(lista);

    celula *p = lista;
    while (p != NULL) {
        celula *t = p->seg;
        free(p);
        p = t;
    }

    return 0;
}
