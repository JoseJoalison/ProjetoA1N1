#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tabela.h"

    //Lê os dados de um arquivo CSV e armazena dinamicamente em um vetor de Tabela.
    // NomeArquivo Nome do arquivo CSV a ser lido.
    // num_registros Ponteiro para um inteiro onde será armazenado o número de registros lidos para uma leitura de linhas dinamicamente.
Tabela *LerDados(char *NomeArquivo, int *num_registros) {
    FILE * fp = fopen(NomeArquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(ERRO);
    }
    
    printf("O arquivo foi aberto com SUCESSO!\n");

    char linha[1000];
    int capacidade = 0;
    int i = 0;
    Tabela *P = NULL;

    // Pular o cabeçalho
    fgets(linha, sizeof(linha), fp);

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), fp) != NULL) {

        //Alocação de memoria dinâmica, dobrando sua capacidade quando necessário
        if (i >= capacidade) {
            capacidade = capacidade == 0 ? 10 : capacidade * 2;
            P = realloc(P, sizeof(Tabela) * capacidade);
            if (!P) {
                printf("Erro ao realocar memoria.\n");
                fclose(fp);
                exit(ERRO);
            }
        }

        // Inicializa o strtok_r
        char *saveptr;
        char *token = strtok_r(linha, ";", &saveptr);


        int campo = 0;
        int campos_lidos = 0;
        
        // Separar os campos usando strtok e armazenar na estrutura
        // Em caso de int ou ll, utiliza-se atoi ou atoll para conversão
        // Em caso de string, utiliza-se strncpy para copiar o valor
        while (token != NULL) {
            switch (campo) {
                case 0:  P[i].id_processo = atoll(token); campos_lidos++; break;
                case 1:  strncpy(P[i].numero_sigilo, token, sizeof(P[i].numero_sigilo)); campos_lidos++; break;
                case 2:  strncpy(P[i].sigla_grau, token, sizeof(P[i].sigla_grau)); campos_lidos++; break;
                case 3:  strncpy(P[i].procedimento, token, sizeof(P[i].procedimento)); campos_lidos++; break;
                case 4:  strncpy(P[i].ramo_justica, token, sizeof(P[i].ramo_justica)); campos_lidos++; break;
                case 5:  strncpy(P[i].sigla_tribunal, token, sizeof(P[i].sigla_tribunal)); campos_lidos++; break;
                case 6:  P[i].id_tribunal = atoi(token); campos_lidos++; break;
                case 7:  P[i].recurso = atoi(token); campos_lidos++; break;
                case 8:  P[i].id_ultimo_oj = atoi(token); campos_lidos++; break;
                case 9:  strncpy(P[i].dt_recebimento, token, sizeof(P[i].dt_recebimento)); campos_lidos++; break;
                case 10: P[i].id_ultima_classe = atoi(token); campos_lidos++; break;
                case 11: P[i].flag_violencia_domestica = atoi(token); campos_lidos++; break;
                case 12: P[i].flag_feminicidio = atoi(token); campos_lidos++; break;
                case 13: P[i].flag_ambiental = atoi(token); campos_lidos++; break;
                case 14: P[i].flag_quilombolas = atoi(token); campos_lidos++; break;
                case 15: P[i].flag_indigenas = atoi(token); campos_lidos++; break;
                case 16: P[i].flag_infancia = atoi(token); campos_lidos++; break;
                case 17: P[i].decisao = atoi(token); campos_lidos++; break;
                case 18: strncpy(P[i].dt_resolvido, token, sizeof(P[i].dt_resolvido)); campos_lidos++; break;
                case 19: P[i].cnm1 = atoi(token); campos_lidos++; break;
                case 20: P[i].primeirasentm1 = atoi(token); campos_lidos++; break;
                case 21: P[i].baixm1 = atoi(token); campos_lidos++; break;
                case 22: P[i].decm1 = atoi(token); campos_lidos++; break;
                case 23: P[i].mpum1 = atoi(token); campos_lidos++; break;
                case 24: P[i].julgadom1 = atoi(token); campos_lidos++; break;
                case 25: P[i].desm1 = atoi(token); campos_lidos++; break;
                case 26: P[i].susm1 = atoi(token); campos_lidos++; break;
            }

            campo++;
            // Pega o próximo token
            token = strtok_r(NULL, ";", &saveptr);
        }

        //Exibe o Número de campos lidos
        printf("Campos lidos no registro %d: %d\n", i, campos_lidos);

        i++;
    }
    
    fclose(fp);
    if (num_registros) *num_registros = i;
    return P;
}

    //Função para contar quantas flags estão com valores verdadeiros (valor = 1), relacionando as causas aos processos.
int ContaFlags(const Tabela *F, int num_registros, int flag) {
    
    //Inicializa a variável de contagem
    int count = 0;
    
    // Conta quantos registros possuem o valor 1 em um campo flag específico do struct Tabela
    // flag: 0=flag_violencia_domestica, 1=flag_feminicidio, 2=flag_ambiental, ...
    for (int i = 0; i < num_registros; i++) {
        int valor = 0;
        switch (flag) {
            case 0: valor = F[i].flag_violencia_domestica; break;
            case 1: valor = F[i].flag_feminicidio; break;
            case 2: valor = F[i].flag_ambiental; break;
            case 3: valor = F[i].flag_quilombolas; break;
            case 4: valor = F[i].flag_indigenas; break;
            case 5: valor = F[i].flag_infancia; break;

            default: valor = 0; break;
        }
        if (valor == 1) count++;
    }
    return count;
}

    //Função para calcular a diferença em dias entre duas datas no formato "YYYY-MM-DD".
int DifData(char *Data1, char *Data2){
    struct tm tm1 = {0}, tm2 = {0};
    int y1, m1, d1,y2, m2, d2;
    
    if (sscanf(Data1, "%d-%d-%d", &y1, &m1, &d1) != 3) {
        printf("Formato de data inválido para Data1: %s\n", Data1);
        return ERRO;
    }

    if (sscanf(Data2, "%d-%d-%d", &y2, &m2, &d2) != 3) {
        printf("Formato de data inválido para Data2: %s\n", Data2);
        return ERRO;
    }

    tm1.tm_year = y1 - 1900; // Anos desde 1900
    tm1.tm_mon = m1 - 1;     // Meses desde janeiro (0-11)
    tm1.tm_mday = d1;

    tm2.tm_year = y2 - 1900; 
    tm2.tm_mon = m2 - 1;     
    tm2.tm_mday = d2;

    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    // Verifica se a conversão foi bem sucedida para o modelo time_t
    if (t1 == (time_t)-1 || t2 == (time_t)-1){
        printf("Erro ao converter datas.\n");
        return ERRO;
    }

    double diferenca = difftime(t2,t1);
    return (int) (diferenca / (60 * 60 * 24)); // Converte segundos para dias (60 segundos * 60 minutos * 24 horas)

}



