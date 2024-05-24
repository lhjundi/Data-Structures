#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

/*

"A estratégia iterativa do algoritmo Quicksort oferece uma vantagem ao estabelecer limites para o
 tamanho da pilha. Em contraste com a abordagem recursiva, que insere duas partições na pilha de
 execução em ordem arbitrária, a versão iterativa verifica os tamanhos das partições antes de
 adicionar à pilha. Além disso, ao adotar uma política que prioriza a inserção dos índices da partição
 maior do vetor antes dos índices da partição menor, permite que o lado menor seja processado antes
 do lado maior. Como resultado, o tamanho da pilha é da ordem de O(log(n))."

 A estratégia apresentada é coerente e foi implementada através do uso do TAD Pilha e da adoção da 
 política de adicionar na pilha primeiro o maior lado do vetor e depois o lado menor, desta forma
 o lado maior será processado depois do menor, por conta desta política o tamanho da pilha nunca ultrapassa 
 log(n).
 
 Segundo Sedgewick(2002),  através do uso do quick sort recursivo,  para um arquivo aleatório o tamanho máximo da pilha 
 é proporcional à log(n), mas a pilha pode crescer até o tamanho proporcional n para um caso degenerado, ou seja
 em um caso degenerado em um arquivo demasiadamente grande, pode causar a interrupção do programa por falta 
 de memória.
 
 Desta forma através do uso da implementação iterativa, a ordem de processamento é alterada, ocasionando uma
 economia em custo de espaço sem afetar os custos de tempo
 
 */

int main() {
    int numberOfElements = getNumberOfElements();
    int *array = (int*) malloc(sizeof(int)*numberOfElements);
    hasAllocationError(array);
    fillArrayWithUserInput(array, numberOfElements);
    quickSortIterative(array, 0, numberOfElements - 1);
    showSortedArray(array, numberOfElements);
    free(array);
    return 0;
}