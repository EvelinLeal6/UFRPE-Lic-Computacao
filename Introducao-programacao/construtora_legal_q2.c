/*******************************************************************************
 * UFRPE - UNIVERSIDADE FEDERAL RURAL DE PERNAMBUCO
 * CURSO: LICENCIATURA EM COMPUTAÇÃO
 * ALUNA: EVELIN LEAL
 * [QUESTÃO 2] - CONSTRUTORA LEGAL
 * OBJETIVO: Cálcular salário com base em especialidade, tempo de 
 * experiência e adicional de idade superior a 45 anos.
 *******************************************************************************/

#include<stdio.h>

int main() {
    //Declaro variaveis
    char nome[50];
    int espec, idade, anos_exp, outro_usuario;
    float sal_base, adc_exp, adc_45, sal_total;

    do {
        printf("\n--- Entrada de Dados - Construtora Legal ---\n");

        printf("Informe o nome do funcionario: ");
        scanf("%s", nome);

        printf("Informe a idade do funcionario: ");
        scanf("%d", &idade);

        printf("Informe a especialidade (1-pedreiro, 2-pintor, 3-hidraulica, 4-eletricista): ");
        scanf("%d", &espec);

        printf("Informe a quantidade de anos de experiencia do funcionario: ");
        scanf("%d", &anos_exp);
        //Defino salario-base por espec
        if (espec == 1) {
            sal_base = 1100.00;            
        }else if (espec == 2) {
            sal_base = 1250.00;
        }else if (espec == 3) {
            sal_base = 1300.00;
        }else {
            sal_base = 1400.00;
        }
        //Calculo adicional de experiencia (R$ 70 --> por ano de exp)
        adc_exp = anos_exp * 70.00;
        //Somo parcial. calculo bonus de idade (mais de 45 anos)
        sal_total = sal_base + adc_exp;
        
        //Verifico se tem mais de 45 anos para aplicar 8%
        if (idade > 45) {
            adc_45 = sal_total * 0.08;
            
        }else {
            adc_45 = 0;
        }
        //Valor total com adicional de idade
        sal_total = sal_total + adc_45;          
        // --- Impressao alinhamento ---
        printf("\n---------------------------------------------------------------");
        printf("\n  Construtora Legal");
        printf("\n");
        printf("\n  Salario do Funcionario %s", nome);
        printf("\n");
        printf("\n  Valor Total: R$ %.2f.", sal_total);
        printf("\n");
        printf("\n  Recebeu R$ %.2f pela experiencia.", adc_exp);
        printf("\n");
        printf("\n  Recebeu adicional de R$ %.2f por ter mais de 45 anos.", adc_45);
        printf("\n");
        printf("\n---------------------------------------------------------------");
        printf("\n");
    
       printf("\n  Informar dados de outro funcionario (1-sim/0-nao)?: ");
       scanf("%d", &outro_usuario); 
                   
    } while (outro_usuario == 1);

    return 0;
}
