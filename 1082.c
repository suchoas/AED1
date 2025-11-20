#include <stdio.h>
#include <stdlib.h>

int grafo[30][30];
int ja_foi[30];
int lista[30];
int tamanho_lista;
int num_vertices;

void verificar_vizinhos(int atual) {
    ja_foi[atual] = 1;
    lista[tamanho_lista] = atual;
    tamanho_lista++;

    for (int i = 0; i < num_vertices; i++) {
        if (grafo[atual][i] == 1 && ja_foi[i] == 0) {
            verificar_vizinhos(i);
        }
    }
}

void ordenar_lista() {
    int aux;
    for (int i = 0; i < tamanho_lista; i++) {
        for (int j = i + 1; j < tamanho_lista; j++) {
            if (lista[i] > lista[j]) {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

int main() {
    int casos_teste, arestas, k;
    char v1, v2;
    int caso_atual = 1;

    scanf("%d", &casos_teste);

    for (k = 0; k < casos_teste; k++) {
        scanf("%d %d", &num_vertices, &arestas);

        for (int i = 0; i < 30; i++) {
            ja_foi[i] = 0;
            for (int j = 0; j < 30; j++) {
                grafo[i][j] = 0;
            }
        }

        for (int i = 0; i < arestas; i++) {
            scanf(" %c %c", &v1, &v2);
            int id1 = v1 - 'a';
            int id2 = v2 - 'a';

            grafo[id1][id2] = 1;
            grafo[id2][id1] = 1;
        }

        printf("Case #%d:\n", caso_atual);
        caso_atual++;

        int cont_grupos = 0;

        for (int i = 0; i < num_vertices; i++) {
            if (ja_foi[i] == 0) {
                cont_grupos++;
                tamanho_lista = 0;
                
                verificar_vizinhos(i);
                
                ordenar_lista();

                for (int j = 0; j < tamanho_lista; j++) {
                    printf("%c,", lista[j] + 'a');
                }
                printf("\n");
            }
        }

        printf("%d connected components\n\n", cont_grupos);
    }

    return 0;
}
