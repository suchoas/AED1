#include <stdio.h>
#include <stdlib.h>

int saida[1005];
int pilha[1005];

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {
        
        while (1) {
            scanf("%d", &saida[0]);
            
            if (saida[0] == 0) {
                printf("\n"); 
                break;
            }

            for (int i = 1; i < N; i++) {
                scanf("%d", &saida[i]);
            }

            int topo = 0;          
            int vagao = 1; 
            int posicao = 0;  

         
            while (vagao <= N) {
                
                pilha[topo] = vagao;
                topo++;
                vagao++;

            
                while (topo > 0 && posicao < N && pilha[topo - 1] == saida[posicao]) {
                    topo--;      
                    posicao++; 
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
