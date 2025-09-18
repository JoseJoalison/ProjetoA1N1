#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"

int main() {
    int num_registros = 0;
    
    Tabela *T = LerDados("amostra.csv", &num_registros);

    for (int i = 0; i < num_registros; i++){
        
    printf("id_processo: %lld\n", T[i].id_processo);
    printf("numero_sigilo: %s\n", T[i].numero_sigilo);
    printf("sigla_grau: %s\n", T[i].sigla_grau);
    printf("procedimento: %s\n", T[i].procedimento);
    printf("ramo_justica: %s\n", T[i].ramo_justica);
    printf("sigla_tribunal: %s\n", T[i].sigla_tribunal);
    printf("id_tribunal: %d\n", T[i].id_tribunal);
    printf("recurso: %d\n", T[i].recurso);
    printf("id_ultimo_oj: %d\n", T[i].id_ultimo_oj);
    printf("dt_recebimento: %s\n", T[i].dt_recebimento);
    printf("id_ultima_classe: %d\n", T[i].id_ultima_classe);
    printf("flag_violencia_domestica: %d\n", T[i].flag_violencia_domestica);
    printf("flag_feminicidio: %d\n", T[i].flag_feminicidio);
    printf("flag_ambiental: %d\n", T[i].flag_ambiental);
    printf("flag_quilombolas: %d\n", T[i].flag_quilombolas);
    printf("flag_indigenas: %d\n", T[i].flag_indigenas);
    printf("flag_infancia: %d\n", T[i].flag_infancia);
    printf("decisao: %d\n", T[i].decisao);
    printf("dt_resolvido: %s\n", T[i].dt_resolvido);
    printf("cnm1: %d\n", T[i].cnm1);
    printf("primeirasentm1: %d\n", T[i].primeirasentm1);
    printf("baixm1: %d\n", T[i].baixm1);
    printf("decm1: %d\n", T[i].decm1);
    printf("mpum1: %d\n", T[i].mpum1);
    printf("julgadom1: %d\n", T[i].julgadom1);
    printf("desm1: %d\n", T[i].desm1);
    printf("susm1: %d\n", T[i].susm1);
    
    printf("==============================\n");
    }
    
    printf("Total de registros lidos: %d\n", num_registros);

    // Exibe o resultado da diferença entre as datas do indice determinado
    int DifDatas = DifData(T[0].dt_recebimento,T[0].dt_resolvido);
    printf("Diferença entre as datas do processo %lld e' de %d dias\n", T[0].id_processo, DifDatas);
    
    // Exemplo: contar quantos registros têm flag_violencia_domestica == 1 (verdadeira) (índice 0)
    // índice: 0=flag_violencia_domestica, 1=flag_feminicidio, 2=flag_ambiental, ...
    int total_flagAmbiental = ContaFlags(T, num_registros, 2);
    printf("Total de flag_ambiental: %d\n", total_flagAmbiental);

    int t_flagQuilombolas = ContaFlags(T, num_registros, 3);
    printf("Total de flag_quilombolas: %d\n", t_flagQuilombolas);


    // Libera a memória alocada
    free(T);
    return 0;
}
