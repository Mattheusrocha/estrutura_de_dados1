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

long long tranforma_long(char *str) {
    return (str && *str != '\0') ? atoll(str) : 0;
}

void gravar_tribunal(FILE *fout, Tribunal *t) {
    //prepara denominador
    double d1 = (double)t->casos_novos + t->dessobrestados - t->suspensos;
    double d2a = (double)t->distm2_a - t->suspm2_a;
    double d2ant = (double)t->distm2_ant - t->suspm2_ant - t->desom2_ant;
    double d4a = (double)t->distm4_a - t->suspm4_a;
    double d4b = (double)t->distm4_b - t->suspm4_b;
    //faz os calculos
    double meta1 = (d1 != 0) ? (t->julgados_2026 / d1) * 100.0 : 0;
    double meta2a = (d2a != 0) ? (t->julgm2_a / d2a) * (1000.0 / 7.0) : 0;
    double meta2ant = (d2ant != 0) ? (t->julgm2_ant / d2ant) * 100.0 : 0;
    double meta4a = (d4a != 0) ? (t->julgm4_a / d4a) * 100.0 : 0;
    double meta4b = (d4b != 0) ? (t->julgm4_b / d4b) * 100.0 : 0;

    fprintf(fout, "%s,%lld,%.2f,%.2f,%.2f,%.2f,%.2f\n",t->sigla, t->julgados_2026, meta1, meta2a, meta2ant, meta4a, meta4b);        
}

void gerar_resumo_metas(void) {
    FILE *fin = fopen("TRE_Nacional.csv", "r");
    FILE *fout = fopen("resumo.csv", "w");

    if (!fin || !fout) {
        printf("Erro ao abrir os arquivos.\n");
        return; 
    }

    char linha[MAX_LINHA];
    char *colunas[34];
    Tribunal t = {0};

    fprintf(fout, "sigla_tribunal,total_julgados_2026,Meta1,Meta2A,Meta2Ant,Meta4A,Meta4B\n");
    fgets(linha, MAX_LINHA, fin);

    while (fgets(linha, MAX_LINHA, fin)) {
        // Divide a linha usando o separador
        int i = 0;
        char *token = strtok(linha, ";,\n");
        while (token && i < 12) {
            colunas[i++] = token;
            token = strtok(NULL, ";,\n");
        }
        if (i < 32) continue; 
        
        // Se a sigla mudar, grava o tribunal
        if (t.sigla[0] != '\0' && strcmp(t.sigla, colunas[0]) != 0) {
            gravar_tribunal(fout, &t);
            memset(&t, 0, sizeof(Tribunal));
        }
        
        // faz a "somatoria"
        strcpy(t.sigla, colunas[0]);
        t.julgados_2026   += tranforma_long(colunas[11]);
        t.casos_novos     += tranforma_long(colunas[10]);
        t.suspensos       += tranforma_long(colunas[13]);
        t.dessobrestados  += tranforma_long(colunas[14]);
        t.distm2_a        += tranforma_long(colunas[16]);
        t.julgm2_a        += tranforma_long(colunas[17]);
        t.suspm2_a        += tranforma_long(colunas[18]);
        t.distm2_ant      += tranforma_long(colunas[20]);
        t.julgm2_ant      += tranforma_long(colunas[21]);
        t.suspm2_ant      += tranforma_long(colunas[22]);
        t.desom2_ant      += tranforma_long(colunas[23]);
        t.distm4_a        += tranforma_long(colunas[25]);
        t.julgm4_a        += tranforma_long(colunas[26]);
        t.suspm4_a        += tranforma_long(colunas[27]);
        t.distm4_b        += tranforma_long(colunas[29]);
        t.julgm4_b        += tranforma_long(colunas[30]);
        t.suspm4_b        += tranforma_long(colunas[31]);
    }

    // Grava o ultimo tribunal do arquivo
    if (t.sigla[0] != '\0') gravar_tribunal(fout, &t);

    fclose(fin);
    fclose(fout);
    printf("Processamento concluído. Verifique o arquivo resumo.csv\n");
}
