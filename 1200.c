#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char conteudo;
    struct no *esq;
    struct no *dir;
} no;

no* criar_no(char c) {
    no *novo = malloc(sizeof(no));
    novo->conteudo = c;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

no* insere(no *r, char c) {
    if (r == NULL) {
        return criar_no(c);
    }
    if (c < r->conteudo) {
        r->esq = insere(r->esq, c);
    } else if (c > r->conteudo) {
        r->dir = insere(r->dir, c);
    }
    return r;
}

int busca(no *r, char c) {
    if (r == NULL) return 0;
    if (r->conteudo == c) return 1;
    
    if (c < r->conteudo) 
        return busca(r->esq, c);
    else 
        return busca(r->dir, c);
}

void infixa(no *r, int *primeiro) {
    if (r != NULL) {
        infixa(r->esq, primeiro);
        
        if (!*primeiro) printf(" ");
        printf("%c", r->conteudo);
        *primeiro = 0;
        
        infixa(r->dir, primeiro);
    }
}
void prefixa(no *r, int *primeiro) {
    if (r != NULL) {
        if (!*primeiro) printf(" ");
        printf("%c", r->conteudo);
        *primeiro = 0;
        
        prefixa(r->esq, primeiro);
        prefixa(r->dir, primeiro);
    }
}

void posfixa(no *r, int *primeiro) {
    if (r != NULL) {
        posfixa(r->esq, primeiro);
        posfixa(r->dir, primeiro);
        
        if (!*primeiro) printf(" ");
        printf("%c", r->conteudo);
        *primeiro = 0;
    }
}

void liberar_arvore(no *r) {
    if (r != NULL) {
        liberar_arvore(r->esq);
        liberar_arvore(r->dir);
        free(r);
    }
}

int main() {
    no *raiz = NULL;
    char comando[20];
    char valor;
    while (scanf("%s", comando) != EOF) {
        
        if (comando[0] == 'I') {
            if (comando[1] == '\0') {
                scanf(" %c", &valor);
                raiz = insere(raiz, valor);
            } 
            else {
                int primeiro = 1;
                infixa(raiz, &primeiro);
                printf("\n");
            }
        } 
        else if (comando[0] == 'P') {
            if (comando[1] == '\0') {
                scanf(" %c", &valor);
                if (busca(raiz, valor)) {
                    printf("%c existe\n", valor);
                } else {
                    printf("%c nao existe\n", valor);
                }
            }
            else if (comando[1] == 'R') {
                int primeiro = 1;
                prefixa(raiz, &primeiro);
                printf("\n");
            }
            else if (comando[1] == 'O') {
                int primeiro = 1;
                posfixa(raiz, &primeiro);
                printf("\n");
            }
        }
    }

    liberar_arvore(raiz);
    return 0;
}
