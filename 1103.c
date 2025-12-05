#include <stdio.h>

int main() {
    int H1, M1, H2, M2;

    while (1) {
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);

        if (H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0)
            break;

        int atual = H1 * 60 + M1;
        int alarme = H2 * 60 + M2;

        int minutos;

        if (alarme >= atual) {
            minutos = alarme - atual;
        } else {
            minutos = (24 * 60 - atual) + alarme;
        }

        printf("%d\n", minutos);
    }

    return 0;
}
