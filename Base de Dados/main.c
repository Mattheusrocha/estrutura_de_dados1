#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "TRE_LIB.h"

int main()
{
    const char *arquivos[] = {
        "teste_TRE-AC.csv", "teste_TRE-AL.csv", "teste_TRE-AM.csv", "teste_TRE-AP.csv",
        "teste_TRE-BA.csv", "teste_TRE-CE.csv", "teste_TRE-DF.csv", "teste_TRE-ES.csv",
        "teste_TRE-GO.csv", "teste_TRE-MA.csv", "teste_TRE-MG.csv", "teste_TRE-MS.csv",
        "teste_TRE-MT.csv", "teste_TRE-PA.csv", "teste_TRE-PB.csv", "teste_TRE-PE.csv",
        "teste_TRE-PI.csv", "teste_TRE-PR.csv", "teste_TRE-RJ.csv", "teste_TRE-RN.csv",
        "teste_TRE-RO.csv", "teste_TRE-RR.csv", "teste_TRE-RS.csv", "teste_TRE-SC.csv",
        "teste_TRE-SE.csv", "teste_TRE-SP.csv", "teste_TRE-TO.csv"};

    int opcao = 0;
    do
    {

        printf("================================================================\n");
        printf("|                 Seja Bem vindo ao TRE Manager                |\n");
        printf("|                                                              |\n");
        printf("|                    O que gostaria de fazer?                  |\n");
        printf("================================================================\n\n");

        printf("0 -> Fechar Programa \n1 -> Concatenar todos os arquivos estaduais \n2 -> Gerar Resumo de medidas\n3 -> Relatorio de Ocorrencias por Estado\n\n-->");
        opcao = verificador_de_inteiro();

        system("cls");

        switch (opcao)
        {

        case 0:
            continue;
        case 1:

        {
            char nome[100];
            char nome_arquivo[110];
            int abrir = 0;

            printf("Defina um nome para o arquivo (\"seunome\".csv): ");
            scanf("%99s", nome);
            sprintf(nome_arquivo, "%s.csv", nome);

            concatenar_csv(arquivos, (sizeof(arquivos)/4), nome_arquivo);

            system("cls");

            printf("Seu arquivo foi criado, deseja abrir agora?\n1 - Sim | 0 - Nao\n\n-->");
            abrir = verificador_de_inteiro();

            if (abrir)
            {
                system(("%s", nome_arquivo));
            }
            else
            {
                continue;
            }
        }
        break;

        case 2:
        {
            printf("\n\n-----------Opcao em desenvolvimento\n\n");
            //Para |||HIGOR SAFADO GREGORIO||| - Utiliza esse campo pra colocar a parte das funcoes de calculo
            //Pra todas as funções utilize o arquivo chamado "TRE_Nacional", ta concatenado pra uso interno
        }
        break;

        case 3:
        {
            printf("\n\n------------Opcao em desenvolvimento\n\n");
        }
        break;
        }
    } while (opcao != 0);
}
