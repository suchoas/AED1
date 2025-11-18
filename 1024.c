#include <stdio.h>
#include <string.h>

int main(){
    int N, i, M;
    char linha[1005];
    scanf("%d", &N);
    getchar();

    while(N--){
        gets(linha);
        M = strlen(linha);

        for(i = 0; i < M; i++){
            if((linha[i] >= 'a' && linha[i] <= 'z') || (linha[i] >= 'A' && linha[i] <= 'Z')){
                linha[i] = linha[i] + 3;
            }
        }

        for(i=0;i < M/2; i++){
            char temp = linha[i];
            linha[i] = linha[M - 1 -i];
            linha[M - 1 - i] = temp;
        }

        for(i = M/2; i < M; i++){
            linha[i] = linha[i] - 1;
        }
        printf("%s\n", linha);
    }
    return 0;
}
