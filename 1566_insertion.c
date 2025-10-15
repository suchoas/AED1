#include <stdio.h>

#define ALTURA_MIN 20
#define ALTURA_MAX 230

int main() {
    
    int NC; 
    scanf("%d", &NC);

    while (NC--) {
        int N; 
        scanf("%d", &N);

        int altura, contagem_alturas[ALTURA_MAX + 1] = {0};

        for (int i = 0; i < N; i++) {
            scanf("%d", &altura);
            contagem_alturas[altura]++;
        }

        int imprimir = 1;
        
        for (int h = ALTURA_MIN; h <= ALTURA_MAX; h++) {
  
            for (int i = 0; i < contagem_alturas[h]; i++) {
                if (imprimir) {
                    printf("%d", h);
                    imprimir = 0;
                } else {
                    printf(" %d", h);
                }
            }
        }
        printf("\n"); 
    }

    return 0;
}
