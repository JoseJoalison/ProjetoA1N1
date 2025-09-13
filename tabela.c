#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"


Tabela *LerDados(char *NomeArquivo) {
    FILE * fp = fopen(NomeArquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(ERRO);
    }
    
    printf("O arquivo foi aberto com SUCESSO!\n");

    Tabela *P = malloc(N * sizeof(Tabela));
    if (P == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(ERRO);
    }

    char linha[1000];  // Buffer para armazenar cada linha do CSV
    int i = 0;

    while (fgets(linha, sizeof(linha), fp) != NULL && i < N) {
        // Remover a quebra de linha no final, se presente
        linha[strcspn(linha, "\n")] = 0;  

        // Processamento da linha
        int items_read = sscanf(linha, "%lld;%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;%d;%[^;];%d;%d;%d;%d;%d;%d;%d;%d;%[^;];%d;%d;%d;%d;%d;%d;%d;%d",
            &P[i].id_processo,
            P[i].numero_sigilo,
            P[i].sigla_grau,
            P[i].procedimento,
            P[i].ramo_justica,
            P[i].sigla_tribunal,
            &P[i].id_tribunal,
            &P[i].recurso,
            &P[i].id_ultimo_oj,
            P[i].dt_recebimento,
            &P[i].id_ultima_classe,
            &P[i].flag_violencia_domestica,
            &P[i].flag_feminicidio,
            &P[i].flag_ambiental,
            &P[i].flag_quilombolas,
            &P[i].flag_indigenas,
            &P[i].flag_infancia,
            &P[i].decisao,
            P[i].dt_resolvido,
            &P[i].cnm1,
            &P[i].primeirasentm1,
            &P[i].baixm1,
            &P[i].decm1,
            &P[i].mpum1,
            &P[i].julgadom1,
            &P[i].desm1,
            &P[i].susm1);
        
        printf("itens_read: %d\n", items_read);

        if (items_read != 27) {
            printf("Aviso: Linha não lida corretamente.\n");
        }

        i++;
    }

    fclose(fp);
    return P;
}
