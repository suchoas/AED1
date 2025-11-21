#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int valor;
    struct celula *prox;
} celula;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m, c;
        scanf("%d %d", &m, &c);

        celula *tabela[105];
        for (int j = 0; j < m; j++) {
            tabela[j] = NULL;
        }

        for (int j = 0; j < c; j++) {
            int chave;
            scanf("%d", &chave);
            int indice = chave % m;

            celula *nova = (celula *)malloc(sizeof(celula));
            nova->valor = chave;
            nova->prox = NULL;

            if (tabela[indice] == NULL) {
                tabela[indice] = nova;
            } else {
                celula *temp = tabela[indice];
                while (temp->prox != NULL) {
                    temp = temp->prox;
                }
                temp->prox = nova;
            }
        }

        if (i > 0) printf("\n");

        for (int j = 0; j < m; j++) {
            printf("%d -> ", j);
            celula *temp = tabela[j];
            while (temp != NULL) {
                printf("%d -> ", temp->valor);
                temp = temp->prox;
            }
            printf("\\\n");
        }

        for (int j = 0; j < m; j++) {
            celula *temp = tabela[j];
            while (temp != NULL) {
                celula *aux = temp;
                temp = temp->prox;
                free(aux);
            }
        }
    }

    return 0;
}
