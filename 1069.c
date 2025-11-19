#include <stdio.h>

int main() {
    int N;
    char mina[1005]; 

    scanf("%d", &N);

    for (int k = 0; k < N; k++) {
        
        scanf("%s", mina);

        int diamantes = 0;
        int menor = 0; 

        for (int i = 0; mina[i] != '\0'; i++) {
            
            if (mina[i] == '<') {
                menor++; 
            } 
            else if (mina[i] == '>') {
                if (menor > 0) {
                    diamantes++;
                    menor--;
                }
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
