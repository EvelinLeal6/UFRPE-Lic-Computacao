# 📊 Atividades Complementares - Projetos e Utilitários Práticos

Este diretório armazena ferramentas e sistemas utilitários desenvolvidos em **C** de forma autoral para fins de atividades complementares e aprofundamento prático no curso de Licenciatura em Computação na **UFRPE**.

Diferente dos laboratórios tradicionais, estes projetos simulam regras de negócios reais do cotidiano e exploram a estilização do terminal e organização de estruturas de dados.

---

## 💶 1. Sistema de Horas e Ganhos Diários (Euro)

Um software de controle de ponto e simulação de folha de pagamento projetado para gerenciar o faturamento de jornadas de trabalho freelancers baseadas em ganho por hora (`EUR 13.50/h`).

### ⚙️ Funcionalidades e Lógica
* **Mapeamento por Vetor**: Aloca um array estático de floats de 31 posições onde cada índice representa diretamente um dia do mês.
* **Faturamento Automatizado**: Varre o vetor calculando o ganho individual de cada dia trabalhado e incrementa dinamicamente o totalizador geral de horas e dias letivos de trabalho.
* **Layout Alinhado**: Formatação cirúrgica com máscaras de exibição (`%02d`, `%-10.2f`) para estruturar uma tabela de contracheque organizada no console.

---


## 🛠️ Tecnologias e Compilação

Todos os códigos utilizam bibliotecas nativas do C (`<stdio.h>`, `<string.h>`).

```bash
# Como compilar o sistema de horas:
gcc controle_horas_euro.c -o controle_horas

# Como executar:
./controle_horas
