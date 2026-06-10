/*******************************************************************************
 * UFRPE - UNIVERSIDADE FEDERAL RURAL DE PERNAMBUCO
 * CURSO: LICENCIATURA EM COMPUTAÇÃO
 * ALUNA: EVELIN LEAL
 * [QUESTÃO 1] - SISTEMA DE ESTATISTICAS DE SEGURANCA
 * OBJETIVO: Processar dados de ocorrencias policiais em Recife e gerar metricas 
 * sobre perfil de vitimas, modus operandi e horarios de maior frequencia.
 *******************************************************************************/

#include <stdio.h>

int main () {
    //Variáveis gerais n inteiros.
    int idade, sexo, obj_roubo, armado, sozinho, hora_roubo;
    int total_entrevistados = 0;

    //Variáveis específicas. Contadores e acumuladores.
    int fem_noite = 0;
    int menores_20_armados = 0;
    int total_pessoas_obj_celular = 0;
    int sozinhos_armados = 0;

    //Variáveis para a média
    int soma_idade_masc_carro = 0;
    int cont_masc_carro = 0;
     
    //Contadores de horário.
    int cont_manha = 0, cont_tarde = 0, cont_noite = 0, cont_madrugada = 0;

    //Variáveis cálculos percentuais.
    float perc_celular = 0;
    float perc_sozinhos_armados = 0;

    while (1) {
        printf("\n--- NOVA ENTREVISTA --- (Digite zero para sair)\n");
        
        printf("Informe sua idade: ");
        scanf(" %d", &idade);

        if (idade <=0) break;

        //Registro total pessoas entrevistadas.
        total_entrevistados++;

        //As perguntas da pesquisa. Uso espaço antes do % para limpeza buffer.
        printf("Sexo (1-Fem / 2-Mas): ");
        scanf(" %d", &sexo);

        printf("Informe o objeto roubado (1-Carteira / 2-Celular / 3-Carro / 4-Outros): ");
        scanf(" %d", &obj_roubo);

        printf("O assaltante estava armado? (0-Nao / 1-Sim): ");
        scanf(" %d", &armado);

        printf("O assaltante estava sozinho? (0-Nao / 1-Sim): ");
        scanf(" %d", &sozinho);

        printf("Qual horario da ocorrencia?? (1-Manha / 2-Tarde / 3-Noite / 4-Madrugada): ");
        scanf(" %d", &hora_roubo);

        // --- PROCESSAMENTO ---
        //Qtdd Fem roubadas noite.
        if (sexo == 1 && hora_roubo == 3) {
            fem_noite++;
        }
        //Qtdd menor 20 armado.
        if (idade < 20 && armado == 1) {
            menores_20_armados++;
        }
        //Qtdd pessoas celulares roubados.
        if (obj_roubo == 2) {
            total_pessoas_obj_celular++;
        }
        //Media idade Mas com carro roubado.
        if (sexo == 2 && obj_roubo == 3) {
            soma_idade_masc_carro += idade;
            cont_masc_carro++;
        }
        //Qtdd sozinho e armado.
        if (sozinho == 1 && armado == 1) {
            sozinhos_armados++;

        }
        //Frequência hora.
        if (hora_roubo == 1) cont_manha++;
        else if (hora_roubo ==2) cont_tarde++;
        else if (hora_roubo ==3) cont_noite++;
        else if (hora_roubo ==4) cont_madrugada++;
    }
    //Saída dados
    printf("\n==================== RESULTADO DA PESQUISA ====================\n");
    //Quantidade de mulheres que foram assaltadas à noite. 
    printf("Quantidade de mulheres assaltadas a noite: %d\n", fem_noite);
    //Menores de 20 assaltados com uso armas.
    printf("Quantidade de menores de 20 anos assaltadas com uso de arma: %d\n", menores_20_armados);
    //Percentual pessoas com celular roubado.
    if (total_entrevistados > 0) {
        //Resultado percentual em float com 2 casas decimais (.2f).
        perc_celular = ((float)total_pessoas_obj_celular / total_entrevistados) * 100;
        printf("Percentual de pessoas que tiveram o celular roubado: %.2f%%\n", perc_celular);
    }
    //Percentual de assaltantes sozinhos e armados. Mesma lógica percentual acima.
    if (total_entrevistados > 0) {
        perc_sozinhos_armados = ((float)sozinhos_armados / total_entrevistados) * 100;
        printf("Percentual de assaltantes que agiram sozinhos e armados: %.2f%%\n", perc_sozinhos_armados);
    }
    //Media idade homens carro roubado.
    if (cont_masc_carro > 0) {
        float media_idade_masc_carro = (float)soma_idade_masc_carro / cont_masc_carro;
        printf("Media da idade dos homens que tiveram o carro roubado: %.2f\n", media_idade_masc_carro);
    } else {
        printf("Nenhum homem teve o carro roubado.\n");
    }
    //Hora maior frequência.
    printf("Horario com maior frequencia de assaltos: ");    
    if (cont_manha >= cont_tarde && cont_manha >= cont_noite && cont_manha >= cont_madrugada) 
        printf("Manha");
    else if (cont_tarde >= cont_manha && cont_tarde >= cont_noite && cont_tarde >= cont_madrugada) 
        printf("Tarde");
    else if (cont_noite >= cont_manha && cont_noite >= cont_tarde && cont_noite >= cont_madrugada) 
        printf("Noite");
    else 
        printf("Madrugada");

        printf("\n================================================================\n");

        
    return 0;
}


