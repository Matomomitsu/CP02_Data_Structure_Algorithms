//Thomas Joh Kobayashi RM562758

#include <stdio.h>

int main() {
    int N;

    // Leitura do valor de N
    printf("Digite um numero inteiro entre 1 e 20: ");
    scanf("%d", &N);

    // Verificar se N está no intervalo correto
    if (N < 1 || N > 20) {
        printf("O número deve estar entre 1 e 20.\n");
        return 1;  // Encerra o programa com erro
    }

    // Vetor para armazenar os fatoriais
    long long fatorial[N];

    // Preencher o vetor com os fatoriais de 1 até N
    fatorial[0] = 1;  // 1! = 1
    for (int i = 1; i < N; i++) {
        fatorial[i] = fatorial[i - 1] * (i + 1);
    }

    // Imprimir os resultados
    for (int i = 0; i < N; i++) {
        printf("%d! = %lld\n", i + 1, fatorial[i]);
    }

    return 0;
}
