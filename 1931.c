#include <stdio.h>
#include <stdlib.h>

#define CUSTO_INFINITO 0x3f3f3f3f
#define MAX_CIDADES 10005
#define MAX_ESTRADAS 100005

int destino[MAX_ESTRADAS];
int peso[MAX_ESTRADAS];
int proxima_aresta[MAX_ESTRADAS];
int primeira_aresta[MAX_CIDADES];
int contador_arestas;

void limpar_grafo(int n) {
    contador_arestas = 0;
    for (int i = 0; i <= n; i++) {
        primeira_aresta[i] = -1;
    }
}

void adicionar_estrada(int de, int para, int custo) {
    destino[contador_arestas] = para;
    peso[contador_arestas] = custo;
    proxima_aresta[contador_arestas] = primeira_aresta[de];
    primeira_aresta[de] = contador_arestas;
    contador_arestas++;
}

struct Estado {
    int custo;
    int cidade;
    int paridade;
};

struct Estado fila[MAX_ESTRADAS * 4];
int tamanho_fila;

void trocar(int a, int b) {
    struct Estado temp = fila[a];
    fila[a] = fila[b];
    fila[b] = temp;
}

void adicionar_na_fila(int custo, int cidade, int paridade) {
    int i = tamanho_fila++;
    fila[i].custo = custo;
    fila[i].cidade = cidade;
    fila[i].paridade = paridade;

    while (i > 0) {
        int pai = (i - 1) / 2;
        if (fila[pai].custo <= fila[i].custo) break;
        trocar(i, pai);
        i = pai;
    }
}

struct Estado tirar_da_fila() {
    struct Estado retorno = fila[0];
    fila[0] = fila[--tamanho_fila];
    
    int i = 0;
    while (i * 2 + 1 < tamanho_fila) {
        int filho = i * 2 + 1;
        if (filho + 1 < tamanho_fila && fila[filho + 1].custo < fila[filho].custo) {
            filho++;
        }
        if (fila[i].custo <= fila[filho].custo) break;
        trocar(i, filho);
        i = filho;
    }
    return retorno;
}

int menor_custo[MAX_CIDADES][2];

int resolver_dijkstra(int num_cidades) {
    for (int i = 1; i <= num_cidades; i++) {
        menor_custo[i][0] = CUSTO_INFINITO;
        menor_custo[i][1] = CUSTO_INFINITO;
    }

    menor_custo[1][0] = 0;
    tamanho_fila = 0;
    adicionar_na_fila(0, 1, 0);

    while (tamanho_fila > 0) {
        struct Estado atual = tirar_da_fila();
        
        int custo_atual = atual.custo;
        int u = atual.cidade;
        int paridade_atual = atual.paridade;

        if (custo_atual > menor_custo[u][paridade_atual]) continue;

        for (int i = primeira_aresta[u]; i != -1; i = proxima_aresta[i]) {
            int v = destino[i];
            int custo_pedagio = peso[i];

            int nova_paridade = 1 - paridade_atual;
            int novo_custo = custo_atual + custo_pedagio;

            if (novo_custo < menor_custo[v][nova_paridade]) {
                menor_custo[v][nova_paridade] = novo_custo;
                adicionar_na_fila(novo_custo, v, nova_paridade);
            }
        }
    }

    int resposta = menor_custo[num_cidades][0];
    
    if (resposta == CUSTO_INFINITO) return -1;
    return resposta;
}

int main() {
    int C, V;
    int u, v, p;

    while (scanf("%d %d", &C, &V) != EOF) {
        limpar_grafo(C);

        for (int i = 0; i < V; i++) {
            scanf("%d %d %d", &u, &v, &p);
            adicionar_estrada(u, v, p);
            adicionar_estrada(v, u, p);
        }

        printf("%d\n", resolver_dijkstra(C));
    }

    return 0;
}
