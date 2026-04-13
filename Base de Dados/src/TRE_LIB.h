#ifndef TRE_LIB_H
#define TRE_LIB_H
#define ERRO 1
#define MAX_LINHA 8192

typedef struct{

    char sigla_tribunal[10];
    char procedimento[30];
    char ramo_justica[30];
    char sigla_grau[30];
    char uf_oj[30];
    char municipio_oj[30];
    int id_ultimo_oj;
    char nome[30];
    char mesano_cnm1[30];
    char mesano_sent[30];
    int casos_novos_2026;
    int julgados_2026;
    int prim_sent2026;
    int suspensos_2026;
    int dessobrestados_2026;
    int cumprimento_meta1;
    int distm2_a;
    int julgm2_a;
    int suspm2_a;
    double cumprimento_meta2a;
    int distm2_ant;
    int julgm2_ant;
    int suspm2_ant;
    int desom2_ant;
    int cumprimento_meta2ant;
    int distm4_a;
    int julgm4_a;
    int suspm4_a;
    int cumprimento_meta4a;
    int distm4_b;
    int julgm4_b;
    int suspm4_b;
    int cumprimento_meta4b;

}Dados;

typedef struct {
    char estado[30];
    char nomearquivo[40];
    char chave[40];
}Indices;

typedef struct {
    char sigla[10];
    double julgados_2026;
    double casos_novos_2026;
    double suspensos_2026;
    double dessobrestados_2026;
    double julgm2_a;
    double distm2_a;
    double suspm2_a;
    double julgm2_ant;
    double distm2_ant;
    double suspm2_ant;
    double desom2_ant;
    double julgm4_a;
    double distm4_a;
    double suspm4_a;
    double julgm4_b;
    double distm4_b;
    double suspm4_b;

    double Meta1;
    double Meta2A;
    double Meta2Ant;
    double Meta4A;
    double Meta4B;
} Tribunal;

typedef struct {
    char sigla[50];
    double julgados_2026;
    double casos_novos;
    double suspensos;
    double dessobrestados;
    double julgm2_a;
    double distm2_a;
    double suspm2_a;
    double julgm2_ant;
    double distm2_ant;
    double suspm2_ant;
    double desom2_ant;
    double julgm4_a;
    double distm4_a;
    double suspm4_a;
    double julgm4_b;
    double distm4_b;
    double suspm4_b;
} Tribunal2;

void concatenar_csv(const char* arquivos[], int quant_arquivos, const char* saida);//Concatena todos os arquivos citados em char* Arquivos, n é o numero de arquivos citados

int verificador_de_inteiro(void);//Verifica se a opção digitada é int pra evitar looping infinito

void gerar_resumo(const char *arquivos[], int quant_arquivos);

Indices criar_arq_e_chave();

void gerar_relatorio_de_ocorrencias_por_municipio1(const char *arquivos[], int quant_arquivos);

void gerar_relatorio_de_ocorrencias_por_municipio2(const char *arquivos[], int quant_arquivos);



#endif