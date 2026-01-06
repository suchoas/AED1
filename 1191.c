#include <stdio.h>
#include <string.h>

int busca(const char *infixo, char raiz, int subarvore) {
    for (int i = 0; i < subarvore; i++) {
        if (infixo[i] == raiz) {
            return i;
        }
    }
    return -1; 
}

void posfixo(const char *prefixo_atual, const char *infixo_atual, int tamanho) {
    if (tamanho <= 0) {
        return; 
    }

    char raiz_atual = prefixo_atual[0];

    int tamanho_esquerda = busca(infixo_atual, raiz_atual, tamanho);

    int tamanho_direita = tamanho - 1 - tamanho_esquerda;

    posfixo(
        prefixo_atual + 1,
        infixo_atual,
        tamanho_esquerda
    );

    posfixo(
        prefixo_atual + 1 + tamanho_esquerda,
        infixo_atual + tamanho_esquerda + 1,
        tamanho_direita
    );

    printf("%c", raiz_atual);
}

int main() {
    char prefixo_total[27];
    char infixo_total[27];

    while (scanf("%s %s", prefixo_total, infixo_total) == 2) {
        int tamanho_arvore = strlen(prefixo_total);
        
        posfixo(
            prefixo_total, 
            infixo_total, 
            tamanho_arvore
        );
        
        printf("\n");
    }

    return 0;
}
