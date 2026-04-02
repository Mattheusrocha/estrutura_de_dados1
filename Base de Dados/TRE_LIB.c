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
