#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"

int main() {

    int i = 1;

Tabela *T = LerDados("amostra.csv");

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


return 0;
}
