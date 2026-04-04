#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

Indices criar_arq_e_chave() { 
    Indices in;

    printf("\nDigite o nome do estado: ");
    scanf("%[^\n]", &in.estado);

    for (int i = 0; i < strlen(in.estado); i++) // aqui vai transformar as letras pra capslock
    {
        in.estado[i] = toupper(in.estado[i]);
    }

    strcpy(in.nomearquivo, in.estado); // criando o nome do arquivo .csv
    strcat(in.nomearquivo, ".csv");
    sprintf(in.chave, "\"%s\"", in.estado); // criando a chave para comparação

    return in;
} // Criação dos indices: estado, nomearquivo e chave

void gerar_relatorio_de_ocorrencias_por_municipio1(const char *arquivos[], int quant_arquivos)
{
    Indices in = criar_arq_e_chave();
    Dados dado;
    char buffer[2000];
    int x = 0;

    FILE *leitura;
    FILE *relatorio = fopen(in.nomearquivo, "w");
    if (relatorio == NULL)
    {
        printf("Falha ao abrir o arquivo, Ponteiro == NULL");
        exit(-1);
    }
    fclose(relatorio);
    
    for (int i = 0; i < quant_arquivos; i++)
    {
        printf("%s\n", arquivos[i]);
        
        leitura = fopen(arquivos[i], "r");
        fscanf(leitura, "%[^\n]", buffer);
        if (i==0)
        {
            relatorio = fopen(in.nomearquivo, "a");
                if (relatorio == NULL)
                {
                    printf("Falha ao abrir o arquivo, Ponteiro == NULL");
                    exit(-1);
                }
            fprintf(relatorio,"%s",buffer); 
            fclose(relatorio);
        }
        
        while (fscanf(leitura,
                        "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
                        &dado.sigla_tribunal,
                        &dado.procedimento,
                        &dado.ramo_justica,
                        &dado.sigla_grau,
                        &dado.uf_oj,
                        &dado.municipio_oj,
                        &dado.id_ultimo_oj,
                        &dado.nome,
                        &dado.mesano_cnm1,
                        &dado.mesano_sent,
                        &dado.casos_novos_2026,
                        &dado.julgados_2026,
                        &dado.prim_sent2026,
                        &dado.suspensos_2026,
                        &dado.dessobrestados_2026,
                        &dado.cumprimento_meta1,
                        &dado.distm2_a,
                        &dado.julgm2_a,
                        &dado.suspm2_a,
                        &dado.cumprimento_meta2a,
                        &dado.distm2_ant,
                        &dado.julgm2_ant,
                        &dado.suspm2_ant,
                        &dado.desom2_ant,
                        &dado.cumprimento_meta2ant,
                        &dado.distm4_a,
                        &dado.julgm4_a,
                        &dado.suspm4_a,
                        &dado.cumprimento_meta4a,
                        &dado.distm4_b,
                        &dado.julgm4_b,
                        &dado.suspm4_b,
                        &dado.cumprimento_meta4b) != EOF)
        {

            if (strcmp(in.chave, dado.municipio_oj) == 0)
            {
                relatorio = fopen(in.nomearquivo, "a");
                x++;
                printf("Dados Encontrados em %s: %d \n", arquivos[i], x);
                fprintf(relatorio, "%s,%s,%s,%s,%s,%s,%d,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
                dado.sigla_tribunal,
                dado.procedimento,
                dado.ramo_justica,
                dado.sigla_grau,
                dado.uf_oj,
                dado.municipio_oj,
                dado.id_ultimo_oj,
                dado.nome,
                dado.mesano_cnm1,
                dado.mesano_sent,
                dado.casos_novos_2026,
                dado.julgados_2026,
                dado.prim_sent2026,
                dado.suspensos_2026,
                dado.dessobrestados_2026,
                dado.cumprimento_meta1,
                dado.distm2_a,
                dado.julgm2_a,
                dado.suspm2_a,
                dado.cumprimento_meta2a,
                dado.distm2_ant,
                dado.julgm2_ant,
                dado.suspm2_ant,
                dado.desom2_ant,
                dado.cumprimento_meta2ant,
                dado.distm4_a,
                dado.julgm4_a,
                dado.suspm4_a,
                dado.cumprimento_meta4a,
                dado.distm4_b,
                dado.julgm4_b,
                dado.suspm4_b,
                dado.cumprimento_meta4b
                );
                fclose(relatorio);
            }
        }
    fclose(leitura);
    }
}

void gerar_relatorio_de_ocorrencias_por_municipio2(const char *arquivos[], int quant_arquivos) 
{
    Indices in = criar_arq_e_chave();
    Dados dado;
    char* aux;
    int x =0;
    FILE* leitura;
    FILE* relatorio = fopen(in.nomearquivo, "w");
    
    if (relatorio == NULL)
    {
        printf("Falha ao abrir o arquivo, Ponteiro == NULL");
        exit(-1);
    }
    fclose(relatorio);

    for (int i = 0; i < quant_arquivos; i++)
    {
        leitura = fopen(arquivos[i], "r");
        if (leitura == NULL)
        {
            printf("Falha ao abrir o arquivo, Ponteiro == NULL");
            exit(-1);
        }
        
        char buffer[2000];
        fgets(buffer, sizeof(buffer), leitura);
        if (i==0)
        {
            relatorio = fopen(in.nomearquivo, "a");
                if (relatorio == NULL)
                {
                    printf("Falha ao abrir o arquivo, Ponteiro == NULL");
                    exit(-1);
                }
            fprintf(relatorio,"%s",buffer); 
            fclose(relatorio);
        }

        while(fgets(buffer, sizeof(buffer), leitura)) 
        {
            aux = strtok(buffer, ",");
            strcpy(dado.sigla_tribunal, aux);
            for (int k = 1; k < 33; k++)
            {
                aux = strtok(NULL, ",");
                switch (k)
                {
                    case 1:
                        strcpy(dado.procedimento, aux);
                        break;
                    case 2:
                        strcpy(dado.ramo_justica, aux);
                        break;
                    case 3:
                        strcpy(dado.sigla_grau, aux);
                        break;
                    case 4:
                        strcpy(dado.uf_oj, aux);
                        break;
                    case 5:
                        strcpy(dado.municipio_oj, aux);
                        break;
                    case 6:
                        dado.id_ultimo_oj = atoi(aux);
                        break;
                    case 7:
                        strcpy(dado.nome, aux);
                        break;
                    case 8:
                        strcpy(dado.mesano_cnm1, aux);
                        break;
                    case 9:
                        strcpy(dado.mesano_sent, aux);
                        break;
                    case 10:
                        dado.casos_novos_2026 = atoi(aux);
                        break;
                    case 11:
                        dado.julgados_2026 = atoi(aux);
                        break;
                    case 12:
                        dado.prim_sent2026 = atoi(aux);
                        break;
                    case 13:
                        dado.suspensos_2026 = atoi(aux);
                        break;
                    case 14:
                        dado.dessobrestados_2026 = atoi(aux);
                        break;
                    case 15:
                        dado.cumprimento_meta1 = atoi(aux);
                        break;
                    case 16:
                        dado.distm2_a = atoi(aux);
                        break;
                    case 17:
                        dado.julgm2_a = atoi(aux);
                        break;
                    case 18:
                        dado.suspm2_a = atoi(aux);
                        break;
                    case 19:
                        dado.cumprimento_meta2a = atoi(aux);
                        break;
                    case 20:
                        dado.distm2_ant = atoi(aux);
                        break;
                    case 21:
                        dado.julgm2_ant = atoi(aux);
                        break;
                    case 22:
                        dado.suspm2_ant = atoi(aux);
                        break;
                    case 23:
                        dado.desom2_ant = atoi(aux);
                        break;
                    case 24:
                        dado.cumprimento_meta2ant= atoi(aux);
                        break;
                    case 25:
                        dado.distm4_a = atoi(aux);
                        break;
                    case 26:
                        dado.julgm4_a = atoi(aux);
                        break;
                    case 27:
                        dado.suspm4_a = atoi(aux);
                        break;
                    case 28:
                        dado.cumprimento_meta4a = atoi(aux);
                        break;
                    case 29:
                        dado.distm4_b = atoi(aux);
                        break;
                    case 30:
                        dado.julgm4_b = atoi(aux);
                        break;
                    case 31:
                        dado.suspm4_b = atoi(aux);
                        break;
                    case 32:
                        dado.cumprimento_meta4b = atoi(aux);
                        break;
                
                }
            }
            if (strcmp(in.chave, dado.municipio_oj) == 0) 
            {
                relatorio = fopen(in.nomearquivo, "a");
                if (relatorio == NULL)
                {
                    printf("Falha ao abrir o arquivo, Ponteiro == NULL");
                    exit(-1);
                }
                x++;
                printf("Dados Encontrados em %s: %d \n", arquivos[i], x);
                fprintf(relatorio, "%s,%s,%s,%s,%s,%s,%d,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                dado.sigla_tribunal,
                dado.procedimento,
                dado.ramo_justica,
                dado.sigla_grau,
                dado.uf_oj,
                dado.municipio_oj,
                dado.id_ultimo_oj,
                dado.nome,
                dado.mesano_cnm1,
                dado.mesano_sent,
                dado.casos_novos_2026,
                dado.julgados_2026,
                dado.prim_sent2026,
                dado.suspensos_2026,
                dado.dessobrestados_2026,
                dado.cumprimento_meta1,
                dado.distm2_a,
                dado.julgm2_a,
                dado.suspm2_a,
                dado.cumprimento_meta2a,
                dado.distm2_ant,
                dado.julgm2_ant,
                dado.suspm2_ant,
                dado.desom2_ant,
                dado.cumprimento_meta2ant,
                dado.distm4_a,
                dado.julgm4_a,
                dado.suspm4_a,
                dado.cumprimento_meta4a,
                dado.distm4_b,
                dado.julgm4_b,
                dado.suspm4_b,
                dado.cumprimento_meta4b
                );
                fclose(relatorio);
            }
        }
        fclose(leitura);
    }
}