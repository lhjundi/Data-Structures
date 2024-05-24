## IFSP - BES - SCLESDD - Estrutura de Dados
## Trabalho Prático 03 - Quick Sort não recursivo

Lucas Jundi Hikazudani

João Pedro Piccino Marafiotti

## Pilhas e recursão 

Quando ocorre uma chamada de uma função, a execução vai para a chamada da função, executa a função e quando terminar retorna de onde foi chamada.

Por conta disto funções recursivas empilham chamadas na pilha de execução, onde além de empilhar as variáveis locais, é necessário armazenar a linha que devemos voltar a execução do código.

O registro de ativação de uma função é o conjunto formado por

    1. Variáveis locais
    2. Endereço de retorno após a chamada

A pilha de execução (ou pilha de chamadas) é a pilha dos registros de ativação das várias chamadas em execução em um programa.

## Recursão de Cauda

Uma recursão de cauda ocorre se o último passo de uma função f(x) é o retorno de f(y), possibilitando:

    - reiterar a função f(x) usando x = y
    - usando um laço de repetição
    - até chegar em uma das bases da recursão

Desta forma ao invés de usar a recursão, é possível usar um laço de repetição, onde os valores x e y são trocados

## Recursão geral

A recursão do Quick Sort Recursivo não apresenta o formato de uma recursão de cauda.

Recursões que não são de cauda também podem ser eliminadas
    - Porém é necessário utilizar uma pilha
    - E o processo é mais trabalhoso

## Recursão vs. Iteração

Algoritmos recursivos:
    - mais fáceis de entender e de criar
    - mais elegantes

Algoritmos iterativos
    - normalmente mais rápidos do que os recursivos
    - não precisamos empilhar registros a cada iteração


"We should forget about small efficiencies, say about 97% of the time: *premature optimization is the root of all evil*. Yet we should not pass up our opportunities in that critical 3%"
*Donald E. Knuth*

Devemos esquecer pequenas eficiências na maior parte do tempo, pois a otimização prematura é a raiz de todo mal, pensar em otimizar tudo desde o começo, não é uma boa escolha no geral, pois pode levar a erros, códigos mais complexos e a ganhos pequenos, "escovar bits" não vai fazer "um bom código", ele pode deixar um pouco mais rápido, mas talvez não suficientemente mais rápido.

Isso não significa dizer que não é necessário realizar otimizações, é preciso atentar-se às oportunidade dos 3% críticos
        se é possível fazer em O(n) ao invés de O(n)^2, será mais eficiente fazer em O(n), neste caso pode ser mais vantajoso dependendo da aplicação.