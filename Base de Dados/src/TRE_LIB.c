#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TRE_LIB.H"

void concatenar_csv(const char* arquivos[], int quant_arquivos, const char* saida){
    FILE* arquivo_final = fopen(saida, "w");
    
    if (arquivo_final == NULL){
        printf("ERRO: Não foi possivel criar o arquivo");
        exit(1);
    }

    char linha[2000];
    int  primeira=1;

    for(int i = 0; i < quant_arquivos;i++){
        FILE* arquivo_entrada =  fopen(arquivos[i], "r");

        if (arquivo_entrada == NULL){
            printf("Nao foi possivel abrir os arquivos");
            continue;
        }
        
        int primeira_linha = 1;

        while(fgets(linha,sizeof(linha), arquivo_entrada)){

            if (!primeira && primeira_linha){
                primeira_linha = 0;
                continue;
            }
            fputs(linha, arquivo_final);
            primeira_linha = 0;
        }
        fclose(arquivo_entrada);
        primeira = 0;
    }

fclose(arquivo_final);



}
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


int contar_linhas(const char* arquivo) {
    FILE* f = fopen(arquivo, "r");
    char linha[4096];
    int count = 0;
    char sigla[4096];

    fgets(linha, sizeof(linha), f); 

    while (fgets(linha, sizeof(linha), f)) {
        char *sigla = strtok(linha, f)
        
        count++;
    }

    fclose(f);
    return count;
}

int somatoria(int col){
    int linha;
    int aux = 0;
    for( int l = 1;l <= contar_linhas(TRE_Nacional.csv); l++){
        aux += matriz[l][col];
    }
    return aux;
}

 typedef struct Dados{

        int julgados_2026 ;
        int casos_novos_2026;
        int dessobrestados_2026;
        int suspensos_2026;
        int julgm2_a;
        int distm2_a;
        int suspm2_a;
        int julgm2_ant;
        int distm2_ant;
        int suspm2_ant;
        int desom2_ant;
        int julgm4_a;
        int distm4_a;
        int suspm4_a;
        int julgm4_b;
        int distm4_b;
        int suspm4_b;

    }DADOS
    typedef struct siglas{
        char sigla [50];
        Dados


    }

int selecionador (char arq){

   
}
