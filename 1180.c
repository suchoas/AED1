#include <stdio.h>
 
int main() {
    int N, menor, pos;
    int X[1000];
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d", &X[i]);
 
    menor = X[0];
    pos = 0;
    for(int i = 1; i < N; i++){
        if(X[i] < menor){
            menor = X[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);
    return 0;
}
