#include <stdio.h>
#include <stdlib.h>

int main() {
    char expressao[1005]; 

    while (scanf("%s", expressao) != EOF) {
        
        int saldo = 0;
        int correta = 1; 

        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                saldo++;
            } 
            else if (expressao[i] == ')') {
                saldo--;
                
               
                if (saldo < 0) {
                    correta = 0;
                }
            }
        }

       
        if (saldo != 0) {
            correta = 0;
        }

        if (correta) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
