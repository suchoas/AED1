#include <stdio.h>
#include <stdlib.h>

int alvo[1005];
int pilha[1005];

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        
        while (1) {
            scanf("%d", &alvo[0]);
            
            if (alvo[0] == 0) {
                printf("\n"); 
                break;
            }

            for (int i = 1; i < N; i++) {
                scanf("%d", &alvo[i]);
            }

            int topo = 0;          
            int vagao = 1; 
            int indiceAlvo = 0;  

         
            while (vagao <= N) {
                
                pilha[topo] = vagao;
                topo++;
                vagao++;

            
                while (topo > 0 && indiceAlvo < N && pilha[topo - 1] == alvo[indiceAlvo]) {
                    topo--;      
                    indiceAlvo++; 
                }
            }
            if (topo == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
