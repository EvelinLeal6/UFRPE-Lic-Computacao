# 🐎 Sistema de Precificação de Equinos - Cálculo Preço Cavalo

Este software foi desenvolvido em **C** como a resolução da **Questão 2** da primeira avaliação prática da disciplina de Introdução à Programação na **UFRPE**.

O objetivo do sistema é automatizar a avaliação financeira e precificação de cavalos com base em critérios cruzados de raça, idade cronológica e aptidão/finalidade de uso.

## ⚙️ Regras de Negócio e Matriz de Preços

O algoritmo determina o valor de mercado do animal utilizando duas etapas de cálculo:

### 1. Preço Inicial (Tabela Raça x Idade)
* **Quarto de Milha (Opção 1)**:
  * Até 2 anos: R$ 7.000,00
  * Mais de 2 anos: R$ 5.500,00
* **Mangalarga Marchador (Opção 2)**:
  * Até 2 anos: R$ 9.000,00
  * Mais de 2 anos: R$ 6.000,00
* **Árabe (Opção 3)**:
  * Até 2 anos: R$ 18.000,00
  * Mais de 2 anos: R$ 15.000,00

### 2. Adicionais por Finalidade
Sobre o preço inicial determinado acima, aplica-se um acréscimo baseado no objetivo comercial do animal:
* **Esporte (Opção 1)**: +15% de acréscimo.
* **Trabalho (Opção 2)**: +20% de acréscimo.
* **Reprodução (Opção 3)**: +30% de acréscimo.

## 🛠️ Conceitos e Técnicas de Programação

* **Condicionais Aninhadas**: Uso de blocos `if/else` internos para realizar o cruzamento de dados de duas variáveis distintas (Raça e Idade).
* **Estrutura de Repetição Controlada**: Uso do laço `while` associado a múltiplos critérios de saída, permitindo que o usuário encerre o programa tanto digitando uma idade negativa quanto escolhendo a opção "Sair (2)" no menu final.
* **Filtro de Exceções**: Proteção contra entradas inválidas no teclado por meio de desvios condicionais com a instrução `continue`.

## 🚀 Como Executar

```bash
# Compilar o arquivo de código
gcc calculo_preco_cavalo_q2.c -o preco_cavalo

# Rodar o programa compilado
./preco_cavalo
