#include <stdio.h>

int main() {
    int N; 
    scanf("%d", &N);

    for (int k = 0; k < N; k++) {
        int M; 
        scanf("%d", &M);

        int original[1005]; 
        int ordenado[1005];

        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i]; 
        }

        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                if (ordenado[j] > ordenado[i]) {
                
                    int temp = ordenado[i];
                    ordenado[i] = ordenado[j];
                    ordenado[j] = temp;
                }
            }
        }

        int nao_mudou = 0;
        for (int i = 0; i < M; i++) {
            if (original[i] == ordenado[i]) {
                nao_mudou++;
            }
        }
        printf("%d\n", nao_mudou);
    }

    return 0;
}
