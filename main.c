#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"



int main() {
    int num_registros = 0;
    Tabela *T = LerDados("TJDFT_filtrado.csv", &num_registros);

    // printf("Total de registros lidos: %d\n", num_registros);

    //     printf(" ID | Numero Sigilo | Sigla Grau | Procedimento | Ramo Justica | Sigla Tribunal | ID Tribunal | Recurso | ID Ultimo OJ | Data Recebimento | ID Ultima Classe | Flag Violencia Domestica | Flag Feminicidio | Flag Ambiental | Flag Quilombolas | Flag Indigenas | Flag Infancia | Decisao | Data Resolvido | CNM1 | Primeira Sentenca M1 | Baix M1 | Dec M1 | MPU M1 | Julgado M1 | Des M1 | Sus M1 \n");
    //     printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // for (int i = 0; i < num_registros; i++) {
    //     printf("%lld | %s | %s | %s | %s | %s | %d | %d | %d | %s | %d | %d | %d | %d | %d | %d | %d | %s | %d | %d | %d | %d | %d | %d | %d \n",T[i].id_processo, T[i].numero_sigilo, T[i].sigla_grau, T[i].procedimento, T[i].ramo_justica, T[i].sigla_tribunal, T[i].id_tribunal, T[i].recurso, T[i].id_ultimo_oj, T[i].dt_recebimento, T[i].id_ultima_classe, T[i].flag_violencia_domestica, T[i].flag_feminicidio, T[i].flag_ambiental, T[i].flag_quilombolas, T[i].flag_indigenas, T[i].flag_infancia, T[i].decisao, T[i].dt_resolvido, T[i].cnm1, T[i].primeirasentm1, T[i].baixm1, T[i].decm1, T[i].mpum1, T[i].julgadom1, T[i].desm1, T[i].susm1
    //     );
    //     printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    // }

    // int DifDatas = DifData(T[0].dt_recebimento,T[0].dt_resolvido);
    // printf("Diferença entre as datas do processo %lld e' de %d dias\n", T[0].id_processo, DifDatas);

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