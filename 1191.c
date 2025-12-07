#include <stdio.h>
#include <string.h>

int encontrar_indice_raiz(const char *percurso_infixo, char caractere_raiz, int tamanho_subarvore) {
    for (int i = 0; i < tamanho_subarvore; i++) {
        if (percurso_infixo[i] == caractere_raiz) {
            return i;
        }
    }
    return -1; 
}

void calcular_posfixo_recursivamente(const char *prefixo_atual, const char *infixo_atual, int tamanho_atual) {
    if (tamanho_atual <= 0) {
        return; 
    }

    char raiz_atual = prefixo_atual[0];

    int tamanho_esquerda = encontrar_indice_raiz(infixo_atual, raiz_atual, tamanho_atual);

    int tamanho_direita = tamanho_atual - 1 - tamanho_esquerda;

    calcular_posfixo_recursivamente(
        prefixo_atual + 1,
        infixo_atual,
        tamanho_esquerda
    );

    calcular_posfixo_recursivamente(
        prefixo_atual + 1 + tamanho_esquerda,
        infixo_atual + tamanho_esquerda + 1,
        tamanho_direita
    );

    printf("%c", raiz_atual);
}

int main() {
    char percurso_prefixo_total[27];
    char percurso_infixo_total[27];

    while (scanf("%s %s", percurso_prefixo_total, percurso_infixo_total) == 2) {
        int tamanho_arvore = strlen(percurso_prefixo_total);
        
        calcular_posfixo_recursivamente(
            percurso_prefixo_total, 
            percurso_infixo_total, 
            tamanho_arvore
        );
        
        printf("\n");
    }

    return 0;
}
