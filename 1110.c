#include <stdio.h>
#include <stdlib.h>

#define MAX 51 

typedef struct {
    int dados[MAX];
    int inicio, fim;
} Fila;


void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}


int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}


int filaCheia(Fila *f) {
    return (f->fim + 1) % MAX == f->inicio;
}


void enfileirar(Fila *f, int valor) {
    if (!filaCheia(f)) {
        f->dados[f->fim] = valor;
        f->fim = (f->fim + 1) % MAX;
    }
}

int desenfileirar(Fila *f) {
    if (!filaVazia(f)) {
        int valor = f->dados[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        return valor;
    }
    return -1; // erro
}

int tamanhoFila(Fila *f) {
    if (f->fim >= f->inicio) {
        return f->fim - f->inicio;
    } else {
        return MAX - f->inicio + f->fim;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Fila f;
        inicializarFila(&f);


        for (int i = 1; i <= n; i++) {
            enfileirar(&f, i);
        }

        printf("Discarded cards:");
        int primeira = 1;

        while (tamanhoFila(&f) > 1) {
            int descartada = desenfileirar(&f);
            if (primeira) {
                printf(" %d", descartada);
                primeira = 0;
            } else {
                printf(", %d", descartada);
            }

            int movida = desenfileirar(&f);
            enfileirar(&f, movida);
        }

        printf("\nRemaining card: %d\n", desenfileirar(&f));
    }
    return 0;
}
