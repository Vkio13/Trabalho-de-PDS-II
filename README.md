# KAPEMGGA 
    SISTEMA DE GERENCIAMENTO DE FINANÇAS PESSOAIS

# Equipe
- Gabriel Caldeira Bicalho;
- Gustavo Lopes Cupertino;
- Kaique Vinicius Santos Silva;
- Mateus Bastos Soares;
- Pedro Alonso Araujo Silva;

# O Projeto
O "Kapemgga" é um sistema de gerenciamento de finanças pessoais com uma proposta simples: ajudar o usuário a administrar seu dinheiro em meio aos percalços do dia-a-dia, seja separando cada tipo de gasto que terá ao longo de seu mês, com um orçamento dedicado unicamente a ele, ou ainda organizando os boletos em uma lista que irá avisar quando um deles irá vencer e, se for o caso, se um boleto já venceu; tudo isso de uma forma intuitiva e eficiente, que facilite a vida do usuário.

# Diagrama de Classes
![Modelar bancos de dados (1)](https://user-images.githubusercontent.com/111925541/205712483-91a5e72a-0817-4b77-8f59-ad581a99026b.jpeg)

# Critérios de Aceitação e User Stories
1. Como usuário eu quero adicionar novas categorias de gastos para organizar as
minhas futuras despesas.
- Visualização das categorias já adicionadas;
- Possibilidade de edição e deleção de uma categoria já existente;
- Bloqueio de sobreposição, para não haver repetição de uma categoria já existente.

2. Como usuário eu quero adicionar novas despesas, separando-as por categoria.
- Definição do pagamento da despesa, podendo inserir descrições e detalhes sobre determinada despesa;
- Adicionar gastos e editá-los dentro de uma categoria, se necessário.
- Possibilidade de exclusão de um gasto específico.

3. Como usuário eu quero poder, além de gastar meu dinheiro, adicionar uma quantia
quando necessário.
- Visualizar o valor disponível em conta;
- Definir a fonte desse dinheiro (exemplo: presente, pagamento, etc);
- Adicionar ou editar uma adição;
- Excluir uma adição.

4. Como usuário eu quero visualizar um relatório de despesas, categorias e boletos, para entender os meus
gastos.
- Devem haver relatórios mensais, indicando os gastos de cada mês;
- O relatório deve separar as despesas por categoria, indicando os valores e
porcentagem do total;
- Através de um relatório geral, o usuário deve poder visualizar o histórico mensal de
cada categoria e total, indicando a evolução conforme o tempo de cada despesa.
- Por meio de um relatório de uma categoria específica, o usuário pode visualizar os gastos e fundos de uma categoria específica;
- Por meio de um polimorfismo do relatório de categoria, o boleto também terá um relatório próprio, semelhante ao relatório de categoria.

5. Como usuário gostaria de ter conhecimento de possíveis problemas.
- Ao requerer um relatório, caso as despesas atinjam um limite (definido pelo usuário), gostaria de ser avisado
sobre;
- Ao requerer um relatório, caso o boletos estejam perto do vencimento, gostaria de receber a data desse venciomento;
- Ao requerer um relatório, caso o valor em caixa esteja muito baixo quero ser informado sobre.
