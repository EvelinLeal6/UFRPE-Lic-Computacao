# 🏗️ Sistema de Cálculo Salarial - Construtora Legal

Este programa foi desenvolvido em **C** como a resolução da **Questão 2** da disciplina de Introdução à Programação na **UFRPE**.

O objetivo do software é automatizar o cálculo da folha de pagamento de operários com base em sua especialidade técnica, tempo de serviço na área e um abono de idade para profissionais veteranos.

## ⚙️ Regras de Negócio e Cálculos

O sistema processa as informações em um laço de repetição contínuo baseado nas seguintes premissas:

1. **Salário-Base por Especialidade**:
   * Pedreiro (Opção 1): R$ 1.100,00
   * Pintor (Opção 2): R$ 1.250,00
   * Hidráulica (Opção 3): R$ 1.300,00
   * Eletricista (Opção 4 / Outros): R$ 1.400,00

2. **Adicional por Experiência**: 
   * Acréscimo fixo de **R$ 70,00 por cada ano** de experiência comprovada.

3. **Bônus por Idade**:
   * Caso o colaborador possua **mais de 45 anos**, é aplicado um adicional de **8%** sobre a soma do (Salário-Base + Adicional de Experiência).

## 🛠️ Conceitos de Programação Aplicados

* Estrutura de repetição pós-testada (`do-while`) para permitir o cadastro de múltiplos funcionários em sequência.
* Condicionais encadeadas (`if / else if / else`) para determinação do salário-base.
* Manipulação de strings e variáveis de precisão flutuante (`float`).

## 🚀 Como Executar

```bash
# Compilar o arquivo
gcc construtora_legal_q2.c -o construtora

# Executar o programa
./construtora
