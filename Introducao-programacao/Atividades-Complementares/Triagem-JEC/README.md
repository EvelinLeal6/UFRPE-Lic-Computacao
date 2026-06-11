# Simulador de Triagem Processual (JEC vs. Justiça Comum)

Este é um sistema interativo desenvolvido em linguagem C para automatizar a triagem de competência de ações judiciais, com base nos critérios de valor da causa e obrigatoriedade de capacidade postulatória (advogado), conforme as regras da **Lei nº 9.099/95 (Juizados Especiais Cíveis)**.

## ⚖️ Regras de Negócio (Base Legal)
O sistema calcula os limites processuais de forma dinâmica utilizando o valor do salário mínimo vigente (configurado para o ano de 2026 em R$ 1.518,00):
* **Até 20 salários mínimos:** Competência do JEC. O peticionamento por advogado ou defensor público é **opcional** (jus postulandi).
* **Entre 20 e 40 salários mínimos:** Competência do JEC. A presença de advogado é **obrigatória**.
* **Acima de 40 salários mínimos:** O JEC é **incompetente** em razão do valor. A ação deve ser distribuída na **Justiça Comum (Vara Cível)**.

## 🛠️ Recursos Técnicos Utilizados
* **Modularização:** Uso de função do tipo `void` (`fazerTriagemJEC`) para isolar as regras de tomada de decisão jurídica do fluxo principal do programa.
* **Estruturas Condicionais:** Uso de encadeamento `if`, `else if` e `else` com operadores lógicos (`&&`) para avaliar as faixas de valores de forma precisa.
* **Laço de Repetição Contínuo:** Implementação de uma estrutura `while(1)` (loop infinito) que mantém o sistema ativo, permitindo que o usuário consulte múltiplos valores de causa consecutivamente sem que o programa encerre.
* **Critério de Parada:** Uso do comando `break` condicionado à digitação do valor `0`, permitindo o encerramento limpo e controlado do sistema.

## 🚀 Como Executar o Projeto
1. Clone o repositório.
2. Compile o arquivo `.c` no seu terminal:
   ```bash
   gcc triagem_jec.c -o triagem_jec
