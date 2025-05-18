// Mateus Scandiuzzi Valente Tomomitsu RM561565
// Thomas Joh Kobayashi RM562758
// Henrique Mandrick RM562715
// Luiz Henrique Zaim da Cruz RM563615
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>


char    get_number(void)
{
    char input[3];

    printf("Digite a sua escolha: \t");
    fgets(input, 3, stdin);

    if (input[1] != '\n' && input[1] != '\0')
    {
        printf("Entrada inválida\n");
        while(fgetc(stdin) != '\n');
        return('\0');
    }
    return (input[0]);
}

void fibonacci(void) {
    int n;

    printf("Digite a quantidade de termos da sequência de Fibonacci (1 a 50): ");
    scanf("%d", &n);
    while (fgetc(stdin) != '\n');

    if (n < 1 || n > 50) {
        printf("Número de termos inválido. Deve estar entre 1 e 50.\n");
        return;
    }

    // Declarando um vetor de inteiros para armazenar a sequência de Fibonacci
    int fib_sequence[n];

    // Inicializando os dois primeiros números da sequência de Fibonacci
    if (n >= 1) {
        fib_sequence[0] = 0;  // O primeiro número da sequência é 0
    }
    if (n >= 2) {
        fib_sequence[1] = 1;  // O segundo número da sequência é 1
    }

    // Preenchendo o vetor com os números seguintes da sequência de Fibonacci
    for (int i = 2; i < n; i++) {
        // Cada número é a soma dos dois anteriores
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }

    // Imprimindo a sequência de Fibonacci
    printf("Sequência de Fibonacci: ");
    for (int i = 0; i < n; i++) {
        // Imprime cada número da sequência
        printf("%d ", fib_sequence[i]);
    }
    printf("\n");  // Pula para a próxima linha após a sequência
}

void factorial(void) {
    int N;

    // Leitura do valor de N
    printf("Digite um numero inteiro entre 1 e 20: ");
    scanf("%d", &N);
    while(fgetc(stdin) != '\n');

    // Verificar se N está no intervalo correto
    if (N < 1 || N > 20) {
        printf("O número deve estar entre 1 e 20.\n");
        return;  // Encerra o programa com erro
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

    return;
}

void    palindromo(void)
{
    char palavra[101];
    int tamanho = 0;
    int eh_palindromo = 1;

    printf("Digite a palavra: ");
    scanf(" %100s", palavra);
    while (fgetc(stdin) != '\n');


    while (palavra[tamanho] != '\0') {
        tamanho++;
    }

    for (int i = 0; i < tamanho / 2; i++) {
        if (palavra[i] != palavra[tamanho - i - 1]) {
            eh_palindromo = 0;
            break;
        }
    }

    if (eh_palindromo) {
        printf("A palavra é um palíndromo.\n");
    } else {
        printf("A palavra NÃO é um palíndromo.\n");
    }
}

void    check_substring(void)
{
    char str1[101];
    char str2[101];
    int i = 0;
    int j;

    printf("Digite a primeira string:\t");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    if (strcspn(str1, "\0") == 100)
    {
        while(fgetc(stdin) != '\n');
    }
    printf("Digite a segunda string:\t");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    if (strcspn(str2, "\0") == 100)
    {
        while(fgetc(stdin) != '\n');
    }

    while(str1[i] != '\0')
    {
        j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
            j++;
        }
        if (str2[j] == '\0')
        {
            printf("A segunda string está contida na primeira.\n");
            return;
        }
        i++;
    }

    printf("A segunda string NÃO está contida na primeira.\n");
}

int main()
{
    bool continue_loop = true;
    char number;

    setlocale(LC_ALL, "Portuguese");
    while(continue_loop)
    {
        printf("===== MENU DE EXERCÍCIOS =====\n1 - Sequência de Fibonacci;\n2 - Fatoriais;\n3 - Verificar Palíndromo;\n4 - Verificar Substring.\n5 - Sair.\n");
        number = get_number();
        if (number == '\0')
            continue;
        switch(number)
        {
            case '1':
                fibonacci();
                break;
            case '2':
                factorial();
                break;
            case '3':
                palindromo();
                break;
            case '4':
                check_substring();
                break;
            case '5':
                continue_loop = false;
                break;
            default:
                printf("Entrada inválida\n");
                break;
        }
        printf("\n");
    }

    return 0;
}
