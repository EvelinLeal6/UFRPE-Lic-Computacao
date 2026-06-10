# 🚔 Sistema de Estatísticas de Segurança (Recife)

Este programa foi desenvolvido em **C** como parte das atividades práticas da disciplina de Introdução à Programação. 

O objetivo principal é processar dados de ocorrências policiais na cidade de Recife e gerar métricas detalhadas de forma automatizada para auxiliar na análise de segurança pública.

## 📊 Funcionalidades e Métricas Geradas

O sistema roda em um laço contínuo de entrevistas e processa as seguintes informações:
* **Perfil das Vítimas**: Análise de idade, sexo e situações específicas (ex: ocorrências noturnas com mulheres).
* **Modus Operandi**: Estatísticas sobre o uso de armas de fogo/brancas e se a vítima estava sozinha no momento da abordagem.
* **Frequência por Período**: Contabilidade exata dos crimes divididos por turnos (Manhã, Tarde, Noite e Madrugada).
* **Balanço de Bens**: Percentual de itens roubados com foco em dispositivos celulares e veículos (carros).

## 🛠️ Tecnologias Utilizadas

* **Linguagem**: C (Padrão ANSI)
* **Estruturas aplicadas**: Loops de repetição (`while`), condicionais compostas (`if/else`), contadores e acumuladores matemáticos.

## 🚀 Como Executar o Projeto

Caso queira clonar este módulo e testar o executável localmente no terminal, utilize um compilador GCC:

```bash
# Compilar o arquivo
gcc sistema_seg_Recife_q1.c -o sistema_seguranca

# Executar o programa
./sistema_seguranca
