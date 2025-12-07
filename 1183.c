#include <stdio.h>

int main() {
    char operacao;
    double M[12][12];
    double soma = 0.0;
    int contador = 0;
    
    const int TOTAL_ELEMENTOS_AREA = 66;

    if (scanf(" %c", &operacao) != 1) {
        return 1;
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (scanf("%lf", &M[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (j > i) {
                soma += M[i][j];
                contador++; 
            }
        }
    }

    if (operacao == 'S') {
        printf("%.1lf\n", soma);
    } else if (operacao == 'M') {
        double media = soma / TOTAL_ELEMENTOS_AREA;
        printf("%.1lf\n", media);
    }

    return 0;
}
