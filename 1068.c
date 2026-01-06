#include <stdio.h>

int main() {
    char expressao[1005];

    while (scanf("%s", expressao) != EOF) {

        int aberto = 0;
        int correta = 1;

        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                aberto++;
            } 
            else if (expressao[i] == ')') {
                aberto--;
                if (aberto < 0) {
                    correta = 0;
                    break; 
                }
            }
        }

        if (aberto != 0) {
            correta = 0;
        }

        if (correta)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}
