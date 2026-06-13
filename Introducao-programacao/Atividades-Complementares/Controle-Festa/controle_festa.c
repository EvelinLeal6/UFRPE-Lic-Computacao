#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTICIPANTES 50

typedef struct {
    char nome[50];
    int idade, genero;     
} Participante;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void aguardar_enter() {
    printf("\nTecle ENTER para retornar ao menu de opcoes."); 
    getchar();
}

void limpar_tela() {
    system("cls || clear");
}

void nome_em_maiusculo(char nome_original[], char nome_maiusculo[]) {
    int i = 0;
    while (nome_original[i] != '\0') {
        nome_maiusculo[i] = toupper(nome_original[i]);
        i++;
    }
    nome_maiusculo[i] = '\0';
}

int main() {
    Participante festa[MAX_PARTICIPANTES];
    int total_participantes = 0;
    int i, opcao;

    //variáveis estat.
    float soma_idades = 0;    
    int cont_feminino = 0, cont_masculino = 0, cont_outros = 0;
    int rodando = 1;

    while (rodando && total_participantes < MAX_PARTICIPANTES) {
        limpar_tela();

        printf("+------------------------------------------------+\n");
        printf("|          SISTEMA DE CONTROLE DE ENTRADA        |\n");
        printf("+------------------------------------------------+\n");
        printf("|  1. Cadastrar Participante                     |\n");
        printf("|  2. Listar Participantes                       |\n");
        printf("|  3. Gerar Relatorio Estatistico               |\n");
        printf("|  4. Sair                                       |\n");
        printf("+------------------------------------------------+\n");
        printf("Escolha uma opcao: ");
        
        if (scanf(" %d", &opcao) != 1) {
            printf("Opcao invalida. Por favor, digite opcao valida.\n");
            limpar_buffer();
            aguardar_enter();
            continue;
        }
        limpar_buffer();

        switch (opcao) {
            case 1:
                limpar_tela();
                printf("==================================================\n");
                printf("            OLA, BEM-VINDE A FESTA LEAL!          \n");
                printf("==================================================\n");
                printf(" Para liberar sua entrada, preencha os dados:\n\n");
                printf("NOME COMPLETO: ");
                fgets(festa[total_participantes].nome, sizeof(festa[total_participantes].nome), stdin);
                
                //Limpar \n do fgets
                size_t len = strlen(festa[total_participantes].nome);
                if (len > 0 && festa[total_participantes].nome[len - 1] == '\n') {
                    festa[total_participantes].nome[len - 1] = '\0';
                }

                printf("IDADE: ");
                scanf("%d", &festa[total_participantes].idade);
                limpar_buffer();

                printf("GENERO (1-Feminino, 2-Masculino, 3-Outros): ");
                scanf("%d", &festa[total_participantes].genero);
                limpar_buffer();

                total_participantes++;

                printf("\nParticipante cadastrado com sucesso!\n");
                aguardar_enter();
                break;

            case 2:
                limpar_tela();
                if (total_participantes > 0) {
                    printf("==================================================\n");
                    printf("               LISTA DE PARTICIPANTES             \n");
                    printf("==================================================\n");
                    
                    for (i = 0; i < total_participantes; i++) {
                        char nome_maiusculo[50];
                        nome_em_maiusculo(festa[i].nome, nome_maiusculo);
                        printf("%d. %s, Idade: %d, Genero: ", i + 1, nome_maiusculo, festa[i].idade);
                        
                        if (festa[i].genero == 1) printf("Feminino\n");
                        else if (festa[i].genero == 2) printf("Masculino\n");
                        else printf("Outros\n");
                    }
                    printf("--------------------------------------------------\n");
                } else {
                    printf("\nA festa ainda esta vazia! Nenhum participante cadastrado.\n");
                }
                aguardar_enter();
                break;
            
            case 3:
                limpar_tela();
                printf("==================================================\n"); 
                printf("               RELATORIO ATUAL DA FESTA           \n");
                printf("==================================================\n");

                if (total_participantes > 0) {
                    int mulheres_menores_40 = 0;
                    int homens_maiores_40 = 0;
                    int criancas = 0;

                    soma_idades = 0;
                    cont_feminino = 0;
                    cont_masculino = 0;
                    cont_outros = 0;

                    for (i = 0; i < total_participantes; i++) {
                        soma_idades += festa[i].idade;

                        if (festa[i].genero == 1) {
                            cont_feminino++;
                            if (festa[i].idade < 40) mulheres_menores_40++;
                        } 
                        else if (festa[i].genero == 2) {
                            cont_masculino++;
                            if (festa[i].idade > 40) homens_maiores_40++;
                        } 
                        else if (festa[i].genero == 3) {
                            cont_outros++;
                        }

                        if (festa[i].idade < 12) criancas++;
                    }

                    float media_idade = soma_idades / total_participantes;
                    
                    float pct_feminino = (cont_feminino * 100.0) / total_participantes;
                    float pct_masculino = (cont_masculino * 100.0) / total_participantes;
                    float pct_outros = (cont_outros * 100.0) / total_participantes;
                    float pct_mulheres_sub40 = (mulheres_menores_40 * 100.0) / total_participantes;
                    float pct_homens_plus40  = (homens_maiores_40 * 100.0) / total_participantes;
                    float pct_criancas       = (criancas * 100.0) / total_participantes;

                    printf("Total de participantes cadastrados: %d\n", total_participantes);
                    printf("Media de idade dos participantes:   %.0f anos\n", media_idade);
                    printf("--------------------------------------------------\n");
                    printf("DISTRIBUICAO POR GENERO:\n");
                    printf(" - Feminino:  %d (%.1f%%)\n", cont_feminino, pct_feminino);
                    printf(" - Masculino: %d (%.1f%%)\n", cont_masculino, pct_masculino);
                    printf(" - Outros:    %d (%.1f%%)\n", cont_outros, pct_outros);
                    printf("--------------------------------------------------\n");
                    printf("ANALISE DE PERFIL (Sobre o total da festa):\n");
                    printf(" - Mulheres abaixo de 40 anos:  %d (%.1f%%)\n", mulheres_menores_40, pct_mulheres_sub40);
                    printf(" - Homens acima de 40 anos:     %d (%.1f%%)\n", homens_maiores_40, pct_homens_plus40);
                    printf(" - Criancas (Menores de 12):    %d (%.1f%%)\n", criancas, pct_criancas);
                    
                } else {
                    printf("Nenhum participante registrado na festa ate o momento.\n");
                }
                printf("==================================================\n");
                
                aguardar_enter(); 
                break; 

            case 4: 
                printf("\nObrigada por utilizar o sistema! Encerrando...\n");
                rodando = 0; 
                break;

            default:
                printf("Opcao invalida. Por favor, digite uma opcao valida.\n");
                aguardar_enter();
                break;
        } 
    } 

    return 0;
}
