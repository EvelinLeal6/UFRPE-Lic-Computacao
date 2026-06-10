#include <stdio.h>
#include <time.h>

/*Regras CPC e TJPE
ATO CONJUNTO Nº 43-2025-TJPE
Mês 0 (Jan): 1 a 6 (Ano Novo + Recesso)
Mês 1 (Fev): 16, 17 e 18 (Carnaval e Cinzas)
Mês 2 (Mar): 6 (Data Magna de PE)
Mês 3 (Abr): 2 e 3 (Semana Santa), 21 (Tiradentes)
Mês 4 (Mai): 1 (Dia do Trabalho)
Mês 5 (Jun): 22 (Corpus Christi), 20 a 30 (Recesso Junino)
Mês 6 (Jul): 16 (Nossa Sra. do Carmo)
Mês 7 (Ago): 10 (Cursos Jurídicos)
Mês 8 (Set): 7 (Independência)
Mês 9 (Out): 12 (Nossa Sra. Aparecida), 30 (Servidor Público)
Mês 10 (Nov): 2 (Finados), 20 (Consciência Negra)
Mês 11 (Dez): 8 (Dia da Justiça), 23 a 31 (Recesso Final)
*/

int feriado_tjpe(int dia, int mes) {

    if (mes == 0) {
        if (dia >= 1 && dia <= 6) return 1;     
    }

    if (mes == 1) {
        if (dia >= 16 && dia <= 18) return 1;     
    }

    if (mes == 2 && dia == 6) return 1;

    if (mes == 3) {
        if (dia == 2 || dia == 3 || dia == 21) return 1;                 
    }

    if (mes == 4 && dia == 1) return 1;
    
    if (mes == 5) {
        if (dia >= 20 && dia <= 30) return 1;
    }

    //2º semestre

    if (mes == 6 && dia == 16) return 1;
    /*10 de agosto, segunda-feira – em razão do Dia dos Cursos Jurídicos 
    (Código de Organização Judiciária – COJE - LC Nº 100/2007, art. 94) - (antecipado do dia 11 de agosto, terça-feira)
    */
    if (mes == 7 && dia == 10) return 1;

    if (mes == 8 && dia == 7) return 1;
    
    //Dia serv pub transferido 28 --> 30
    if (mes == 9 && (dia == 12 || dia == 30)) return 1;

    if (mes == 10 && (dia == 2 || dia == 20)) return 1;

    if (mes == 11) {
        if (dia == 8 || (dia >= 23 && dia <= 31)) return 1;       
    }
    
    return 0;
      
    
    
                
        
        
}
        


