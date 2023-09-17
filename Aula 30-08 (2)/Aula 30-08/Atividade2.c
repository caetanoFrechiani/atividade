#include <stdio.h>

int main() {
    int A, B, C, D;

    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);
    printf("Digite o valor de C: ");
    scanf("%d", &C);
    printf("Digite o valor de D: ");
    scanf("%d", &D);

    int menor = A;
    int maior = A;

    if (B < menor) {
        menor = B;
    }
    if (B > maior) {
        maior = B;
    }

    if (C < menor) {
        menor = C;
    }
    if (C > maior) {
        maior = C;
    }

    if (D < menor) {
        menor = D;
    }
    if (D > maior) {
        maior = D;
    }

    printf("O menor valor é: %d\n", menor);
    printf("O maior valor é: %d\n", maior);

    return 0;
}
