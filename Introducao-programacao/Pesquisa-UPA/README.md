# 🏥 Sistema de Cadastro e Pesquisa de Pacientes (UPA)

Este projeto consiste em um sistema de processamento de dados desenvolvido em **C** para a primeira avaliação da disciplina de Introdução à Programação na **UFRPE**.

O objetivo do programa é cadastrar o fluxo de pacientes de uma Unidade de Pronto Atendimento (UPA) e extrair métricas estatísticas detalhadas sobre os atendimentos de forma automatizada.

## 📊 Métricas e Relatórios Gerados

O sistema coleta dados contínuos de triagem e, ao encerrar o loop, gera os seguintes indicadores:
* **Pediatria/Triagem**: Contagem exata de pacientes menores de 12 anos.
* **Exames por Perfil**: Quantidade de pacientes do sexo feminino que realizaram exames médicos.
* **Média Cardiologia**: Média de idade dos homens atendidos pela especialidade de Cardiologia.
* **Demanda de Ortopedia**: Percentual geral de pacientes que buscaram o Ortopedista em relação ao total de atendimentos.
* **Grupo de Risco Feminino**: Percentual de mulheres acima de 50 anos atendidas na unidade.

## 🛠️ Recursos Técnicos Aplicados

* **Validação de Entrada (Data Cleansing)**: Mecanismos com estruturas de controle (`if` e `continue`) que impedem a inserção de dados inválidos para sexo, exames e especialidades.
* **Controle de Fluxo**: Laço infinito condicional (`while(1)`) com critério de parada (`break`) acionado por flag de idade negativa (`-1`).
* **Precisão Matemática**: Aplicação de *type casting* `(float)` para garantir cálculos exatos de médias e percentuais, evitando truncamento de inteiros.

## 🚀 Como Executar

```bash
# Compilar o programa
gcc pesquisa_pacientes_upa_q1.c -o pesquisa_upa

# Executar o sistema
./pesquisa_upa
