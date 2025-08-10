# Eliminação de Gauss em C

O projeto implementa o método da eliminação de Gauss para resolver sistemas lineares utilizando a linguagem C.

## Descrição

O programa realiza os passos:

- Seleciona o elemento pivô em cada coluna usando pivoteamento parcial (escolhendo o maior valor em módulo).
- Troca as linhas para colocar o pivô na posição correta.
- Elimina os valores abaixo do pivô para formar uma matriz triangular superior.
- Imprime a matriz resultante.


## Estrutura do código
- `modulo()` — calcula o valor absoluto de um número.

- `swapRows()` — troca duas linhas da matriz.

- `selectPartialPivot()` — encontra a linha do pivô na coluna atual.

- `eliminateBelowPivot()` — zera os elementos abaixo do pivô.

- `main()` — executa o processo de eliminação e imprime a matriz.
