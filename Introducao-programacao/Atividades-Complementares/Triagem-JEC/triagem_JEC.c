#include<stdio.h>

void fazerTriagemJEC(double valor_causa, double sal_minimo) {
    if (valor_causa <= (sal_minimo * 20)) {
        printf("JEC competente. Advogado OPCIONAL\n");
    } 
    else if (valor_causa > (sal_minimo * 20) && valor_causa <= (sal_minimo * 40)) {
        printf("JEC competente. Advogado OBRIGATORIO\n");
        
    }
    else {
        printf("ALERTA: JEC nao competente. DEVE PROCURAR ADVOGADO - JUSTICA COMUM.\n");
    }
}

int main() {
    double valor_causa, sal_minimo = 1518.00;

    printf("\n===================== SISTEMA DE TRIAGEM JEC =====================\n");
    printf("\nSalario minimo vigente 2026: R$ %.2f\n", sal_minimo);
    printf("\n==================================================================\n");

    while (1) {
    printf("\nDigite o valor da causa (ou digite 0 para sair): R$ ");
    scanf("%lf", &valor_causa);

    if (valor_causa == 0) {
        printf("Saindo do sistema...\n");
        break;
    }

    printf("\n============ >>> ANALISE JURIDICA DE DISTRIBUICAO <<< ============\n\n");

    fazerTriagemJEC(valor_causa, sal_minimo);

    printf("\n==================================================================\n");
}
    return 0;
}

