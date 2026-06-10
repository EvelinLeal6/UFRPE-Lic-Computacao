/****************************************************************************************
 * UFRPE - UNIVERSIDADE FEDERAL RURAL DE PERNAMBUCO
 * CURSO: LICENCIATURA EM COMPUTAÇÃO
 * ALUNA: EVELIN LEAL
 * PRIMEIRA AVALIAÇÃO [QUESTÃO 2] - SISTEMA CÁLCULO PREÇO CAVALO
 * OBJETIVO: Calcular o preço individual de cavalos com base em raça, idade e finalidade.
 * **************************************************************************************/

#include <stdio.h>

int main()
{
// Variáveis gerais n inteiros.
int raca, idade, finalid, opcao = 1;

// Variáveis cálculo preços.
float preco_inicial, acresc, preco_final;

//Tela usuário.
printf("===================================================================================\n");
printf("                           CALCULO PRECO CAVALO                                     \n");
printf("                  --> Para encerrar --> Digite -1 <--                              \n");

//Dados (LOOP)
while (opcao != 2)
{
//Tela usuário.
printf("===================================================================================\n");
printf("                           INFORME OS DADOS DO CAVALO                              \n");
printf("-----------------------------------------------------------------------------------\n");

printf("Informe a idade do cavalo: ");
scanf(" %d", &idade);

if (idade < 0) {
    printf("\nFinalizando o sistema...\n");
    break;
}

printf("\nInforme a raca do cavalo (1-Quarto de Milha / 2-Mangalarga Marchador / 3-Arabe): ");
scanf(" %d", &raca);

//Proteger n diferente das opcoes.
if (raca < 1 || raca > 3) {
    printf("\n[ERRO] Raca invalida! Cadastro cancelado. Tente novamente.\n\n");
    continue;
}
printf("\nInforme a finalidade do cavalo (1-Esporte / 2-Trabalho / 3-Reproducao): ");
scanf(" %d", &finalid);

//Proteger n diferente das opcoes.
if (finalid < 1 || finalid > 3) {
    printf("\n[ERRO] Finalidade invalida! Cadastro cancelado. Tente novamente.\n\n");
    continue; 
}

//Calculo preço inicial

if (raca == 1) {
    if(idade <=2) {
        preco_inicial = 7000.00;
    }
    else {
        preco_inicial = 5500.00;
    }
}
else if(raca == 2) {
    if(idade <=2) {
        preco_inicial = 9000.00;
    }
    else {
        preco_inicial = 6000.00;
    } 
    
}
else if(raca == 3) {
    if(idade <=2) {
        preco_inicial = 18000.00;
    }
    else {
        preco_inicial = 15000.00;
    }
}
//Calculo acresc.
if (finalid == 1) {
    acresc = preco_inicial * 0.15;
}
else if (finalid == 2) {
    acresc = preco_inicial * 0.20; 
}
else if (finalid == 3) {
    acresc = preco_inicial * 0.30;
}
//Soma total dos prços calculados.
preco_final = preco_inicial + acresc;

//Resultados.
printf("\n\n************************************************************\n");
printf("           PRECO FINAL DO CAVALO: R$ %.2f\n", preco_final);
printf("************************************************************\n");
printf("\n           DETALHAMENTO DO CALCULO (PARA O CLIENTE)       \n");
printf("------------------------------------------------------------\n");
printf("Preco inicial (tabelado por raca/idade): R$ %.2f\n", preco_inicial);
printf("Acrescimo aplicado (tabelado por finalidade): R$ %.2f\n", acresc);
printf("------------------------------------------------------------\n\n");
printf("Deseja calcular o preco de outro cavalo? (1-Sim / 2-Sair): ");
scanf(" %d", &opcao);

if (opcao == 2) {
    printf("\nFinalizando o sistema...\n");
    break;
}
printf("\n\n");

}

return 0;

}

