# 📑 Sistema de Controle de Entrada - Festa Leal

Este é um sistema interativo desenvolvido em **Linguagem C** para gerenciamento de portaria, controle de fluxo e análise estatística de eventos via terminal (CLI). O software opera com um menu circular que permite alternar livremente entre as funções de cadastro, listagem e auditoria demográfica sem interromper a execução do programa.

---

## 📊 Indicadores Estatísticos 

O sistema analisa a matriz de dados dos participantes em tempo real e gera um relatório demográfico completo contendo os seguintes indicadores:

* **Volume Geral:** Quantidade total de participantes cadastrados no evento.
* **Média de Idade:** Média aritmética exata das idades de todo o público presente.
* **Distribuição por Gênero (Quantitativa e Percentual):**
  * Total absoluto e percentual de pessoas do gênero Feminino.
  * Total absoluto e percentual de pessoas do gênero Masculino.
  * Total absoluto e percentual de pessoas registradas em Outros.
* **Análise de Perfil Avançada (Cruzamento de Dados):**
  * **Mulheres abaixo de 40 anos:** Quantidade e impacto percentual sobre o público total.
  * **Homens acima de 40 anos:** Quantidade e impacto percentual sobre o público total.
  * **Crianças (Menores de 12 anos):** Quantidade e impacto percentual sobre o público total.

---

## 🚀 Funcionalidades do Sistema

* **Menu Interativo Permanente:** Painel estruturado em molduras de texto com 4 opções de controle (Cadastrar, Listar, Relatório e Sair).
* **Padronização de Dados:** Conversão automática de strings de nome para caracteres **MAIÚSCULOS** via função customizada utilizando `toupper`.
* **Tratamento de Interface:** Sistema inteligente de limpeza de tela (`system`), tratamento de quebras de linha residuais (`fgets`) e controle de buffer do teclado (`stdin`).
* **Estabilização de Visualização:** Mecanismo de travamento de tela que aguarda a ação do usuário antes de retornar ao painel principal, garantindo tempo ágil para leitura de listas e relatórios.

---

## 🛠️ Conceitos Computacionais Aplicados

* **Linguagem:** C (Padrão C99/C11).
* **Estruturas de Dados:** Registro Personalizado (`typedef struct`) e Vetores (`Arrays`).
* **Bibliotecas Utilizadas:** `<stdio.h>`, `<stdlib.h>`, `<string.h>` e `<ctype.h>`.

---

## 🔧 Como Executar

1. Compile o arquivo fonte:
   ```bash
   gcc main.c -o festa_leal
