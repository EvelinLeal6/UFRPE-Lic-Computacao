#include <stdio.h>

#define VERDE    "\x1b[32m"
#define AMARELO  "\x1b[33m"
#define RESET    "\x1b[0m"

int main() {
    float horas_diarias[31]; 
    int dia, i, opcao;
    int dias_trabalhados = 0; 
    float total_horas = 0, total_ganho = 0;
    float valor_hora = 13.5; 

    for (i = 0; i < 31; i++) {
        horas_diarias[i] = 0;
    }

    while (1) {
        printf("\n--- %sSISTEMA DE HORAS (EURO)%s ---\n", AMARELO, RESET);
        printf("1 - Lancar horas\n");
        printf("2 - Gerar Relatorio\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        if (opcao == 1) {
            printf("Digite o dia do mes (1-31): ");
            scanf("%d", &dia);

            if (dia >= 1 && dia <= 31) {
                printf("Quantas horas trabalhou no dia %d? ", dia);
                scanf("%f", &horas_diarias[dia-1]); 
                printf("%sHoras registradas!%s\n", VERDE, RESET);
            } else {
                printf("Dia invalido!\n");
            }
        } 
        else if (opcao == 2) {
            total_horas = 0;
            dias_trabalhados = 0;

            printf("\n+-------------------------------------------------------+");
            printf("\n|                %sRELATORIO DE GANHOS%s                    |", AMARELO, RESET);
            printf("\n+-------------------------------------------------------+");
            printf("\n|                                                       |");
            
            for (i = 0; i < 31; i++) {
                if (horas_diarias[i] > 0) {
                    float ganho_dia = horas_diarias[i] * valor_hora;
                  
                    printf("\n| Dia %02d: %4.1f horas  | Ganho: %sEUR %-10.2f%s      |", i + 1, horas_diarias[i], VERDE, ganho_dia, RESET);
                    
                    total_horas += horas_diarias[i];
                    dias_trabalhados++;
                }
            }
            
            total_ganho = total_horas * valor_hora;
            
            printf("\n|                                                       |");
            printf("\n+-------------------------------------------------------+");
            printf("\n| DIAS TRABALHADOS: %-35d |", dias_trabalhados);
            printf("\n| TOTAL DE HORAS:   %-35.1f |", total_horas);
            printf("\n| TOTAL A RECEBER:  %sEUR %-31.2f%s |", VERDE, total_ganho, RESET);
            printf("\n+-------------------------------------------------------+");
            printf("\n");
        }
    }

    return 0;
}
