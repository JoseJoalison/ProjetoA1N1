#ifndef TABELA_H
#define TABELA_H

#define N 2000   // número máximo de processos
#define ERRO -1

typedef struct {
    long long id_processo;
    char numero_sigilo[100];
    char sigla_grau[10];
    char procedimento[100];
    char ramo_justica[50];
    char sigla_tribunal[20];
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    char dt_recebimento[20];
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    int decisao;
    char dt_resolvido[50];
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;
} Tabela;

Tabela *LerDados(char * NomeArquivo);

int Datas(char *data);

#endif
