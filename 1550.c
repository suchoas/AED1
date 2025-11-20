#include <stdio.h>

#define MAX 10005

int distancia[MAX];
int fila[MAX];

int inverte_numero(int n) {
    int invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n /= 10;
    }
    return invertido;
}

int menor_caminho(int inicio, int fim) {
    for (int i = 0; i < MAX; i++) {
        distancia[i] = -1;
    }
    
    int frente = 0;
    int tras = 0;
    
    fila[tras++] = inicio;
    distancia[inicio] = 0;
    
    while (frente < tras) {
        int atual = fila[frente++];
        
        if (atual == fim) {
            return distancia[atual];
        }
        
        int proximo1 = atual + 1;
        if (proximo1 < MAX && distancia[proximo1] == -1) {
            distancia[proximo1] = distancia[atual] + 1;
            fila[tras++] = proximo1;
        }
        
        int proximo2 = inverte_numero(atual);
        if (proximo2 < MAX && distancia[proximo2] == -1) {
            distancia[proximo2] = distancia[atual] + 1;
            fila[tras++] = proximo2;
        }
    }
    
    return -1;
}

int main() {
    int T, A, B;
    
    if (scanf("%d", &T) != 1) return 0;
    
    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", menor_caminho(A, B));
    }
    
    return 0;
}
