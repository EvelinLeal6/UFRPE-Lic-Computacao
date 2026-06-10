/*******************************************************************************
 * UFRPE - UNIVERSIDADE FEDERAL RURAL DE PERNAMBUCO
 * CURSO: LICENCIATURA EM COMPUTAÇÃO
 * ALUNA: EVELIN LEAL
 * PRIMEIRA AVALIAÇÃO [QUESTÃO 1] - PESQUISA PACIENTES UPA
 * OBJETIVO: Processar dados de quantidade pacientes por idade, tipo de atendimento, exame e se fz exame.
 * *******************************************************************************/

#include <stdio.h>

int main()
{
    // Variáveis gerais n inteiros.
    int idade, sexo, tipo_atend, exame_realizado;

    // Variáveis específicas. Contadores de qtdd.
    int pac_menor = 0;
    int pac_fem_exame_realizado = 0;
    int pac_ortop = 0;
    int total_fem = 0;
    int fem_mais50 = 0;
    int total_pac = 0;

    // Variáveis média.

    int total_masc_cardio = 0;
    int soma_idade_masc_cardio = 0;

    // Variáveis cálculos.
    float perc_fem_mais50 = 0;
    float perc_ortop = 0;
    float media_idade_masc_cardio;

    // Contador pacientes.
    int num_pac = 1;

    // Tela usuário.
    printf("===============================================================\n");
    printf("             SISTEMA DE CADASTRO DE PACIENTES - UPA            \n");
    printf("        --> Encerrar e ver os resultados --> Digite -1          \n");
    printf("===============================================================\n");

    // Dados (LOOP)
    while (1)
    {
        // Tela usuário.
        printf("==================================================================================================\n");
        printf("                     DADOS DO PACIENTE N %d\n", num_pac);
        printf("==================================================================================================\n");

        printf("Informe a idade do paciente: ");
        scanf(" %d", &idade);

        if (idade < 0)
        {
            break;
        }
       
        printf("Informe o sexo do paciente (1-fem / 2-masc): ");
        scanf(" %d", &sexo);

        // Proteger n diferente das opcoes.
        if (sexo < 1 || sexo > 2) {
            printf("\n[ERRO] Opcao de sexo invalida! Reiniciando cadastro do paciente.\n\n");
            continue;
        }

        printf("Informe o tipo de atendimento (1-Clinico Geral / 2-Cardiologista / 3-Ortopedista / 4-Pediatra): ");
        scanf(" %d", &tipo_atend);

        // Proteger n diferente das opcoes.
        if (tipo_atend < 1 || tipo_atend > 4) {
            printf("\n[ERRO] Tipo de atendimento invalido! Reiniciando cadastro do paciente.\n\n");
            continue;
        }

        printf("O paciente realizou algum exame? (1-Sim / 2-Nao): ");
        scanf(" %d", &exame_realizado);

         // Proteger n diferente das opcoes.
         if (exame_realizado < 1 || exame_realizado > 2) {
            printf("\n[ERRO] Opcao de exame invalida! Reiniciando cadastro do paciente.\n\n");
            continue;
        }

        total_pac++;
        printf("-----------------------------------------------------------------------------------\n");

       
        if (idade < 12)
        {
            pac_menor++;
        }

        if (sexo == 1)
        {
            total_fem++;
            if (idade > 50)
            {
                fem_mais50++;
            }
        }

        if (sexo == 1 && exame_realizado == 1)
        {
            pac_fem_exame_realizado++;
        }

        if (tipo_atend == 3)
        {
            pac_ortop++;
        }

        if (sexo == 2 && tipo_atend == 2)
        {
            total_masc_cardio++;
            soma_idade_masc_cardio += idade;
        }
        num_pac++;
    }

    // Cálculos finais. exibição.

    if (total_pac > 0)
    {
        // Média idade masc cardio.

        if (total_masc_cardio > 0)
        {
            media_idade_masc_cardio = (float)soma_idade_masc_cardio / total_masc_cardio;
        }
        else
        {
            media_idade_masc_cardio = 0;
        }
        // Percentual ortoped.
        perc_ortop = ((float)pac_ortop / total_pac) * 100;

        // Percentual fem +50.
        if (total_fem > 0)
        {
            perc_fem_mais50 = ((float)fem_mais50 / total_fem) * 100;
        }
        else
        {
            perc_fem_mais50 = 0;
        }
        // Resultados tela.
        printf("\n==================== RESULTADO PESQUISA UPA =====================\n");
        printf("\nQuantidade de pacientes menores de 12 anos: %d\n", pac_menor);
        printf("\nQuantidade de mulheres que realizaram exame: %d\n", pac_fem_exame_realizado);

        if (total_masc_cardio > 0)
        {
            printf("\nMedia da idade dos homens que foram ao cardiologista: %.1f anos\n", media_idade_masc_cardio);
        }
        else
        {
            printf("\nNenhum homem foi ao cardiologista.\n");
        }

        printf("\nPercentual de pessoas que foram ao ortopedista: %.2f%%\n", perc_ortop);
        printf("\nPercentual de mulheres com mais de 50 anos: %.2f%%\n", perc_fem_mais50);
        printf("\n=================================================================\n");
    }
    else
    {
        printf("\nNenhum paciente cadastrado.\n");
    }
    return 0;
}
