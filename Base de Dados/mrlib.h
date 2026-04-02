#ifndef MRLIB_H
#define MRLIB_H
#define SAUDACAO printf("Bem vindo")

#define TROCA(a, b, c) \
    c = a;             \
    a = b;             \
    b = c // questão 1
#define Returnk system("start cmd.exe")
#define MULTIPLO(a, b) (a % b == 0) ? "eh multiplo" : "nao eh multiplo"                                                                                                                                           // questão 2
#define IS_VOGAL(char) (char == 'A' || char == 'a' || char == 'E' || char == 'e' || char == 'I' || char == 'i' || char == 'O' || char == 'o' || char == 'U' || char == 'u') ? "eh uma vogal" : "nao eh uma vogal" // questao 3

void travador();
float SOMA(float a, float b);
float SUB(float a, float b);
float DIV(float a, float b);
float MULT(float a, float b);
float POT(float a, float b);
void CONVERTE_SEG(int total_segundos, int *h, int *m, int *s);

// Operações matematicas com recurssividade---------------------------------------------------------

// soma
int soma(int a, int b);

// subtracao
int sub(int a, int b);

// divisao
int divi(int a, int b);

// multiplicacao
int mult(int a, int b);

// potenciacao
int potencia(int a, int b);

// verificadores e funcoes importantes----------------------------------------------------------------

// verificador de par ou impar
int verifica_par_impar(int num);

// verificador de numeros primos
int ehPrimo(int n);
void intervalo_primo(int inicio, int fim);

// intervalo de armstrong
int eh_armstrong(long long int n);
void intervalo_armstrong(long long int inicio, long long int fim);

// Recurssiva de fibonacci
long long int fibonacci_termo(int n);

// Conversor decimal pra binario
void binario(int num);

// Anti burros
int verificador_de_inteiro(void);
long long int verificador_de_lld(void);

#endif