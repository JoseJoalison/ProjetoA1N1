#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"

/**
 * Lê os dados de um arquivo CSV e armazena dinamicamente em um vetor de Tabela.
 * NomeArquivo Nome do arquivo CSV a ser lido.
 * num_registros Ponteiro para inteiro onde será armazenado o número de registros lidos.
 */
Tabela *LerDados(char *NomeArquivo) {
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

    // Número de campos em cada linha
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

    return P;
}

