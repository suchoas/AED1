#include <stdio.h>
 
int main() { 
    int N, notas;
    scanf("%d", &N);
    
    printf("%d\n", N);
    
    notas = N/100;
    printf("%d nota(s) de R$ 100,00\n", notas);
    N = N % 100;
    
    notas = N/50;
    printf("%d nota(s) de R$ 50,00\n", notas);
    N = N % 50;
    
    notas = N/20;
    printf("%d nota(s) de R$ 20,00\n", notas);
    N = N % 20;
    
    notas = N/10;
    printf("%d nota(s) de R$ 10,00\n", notas);
    N = N % 10;
    
    notas = N/5;
    printf("%d nota(s) de R$ 5,00\n", notas);
    N = N % 5;
    
    notas = N/2;
    printf("%d nota(s) de R$ 2,00\n", notas);
    N = N % 2;
    
    notas = N/1;
    printf("%d nota(s) de R$ 1,00\n", notas);
    
    return 0;
}
