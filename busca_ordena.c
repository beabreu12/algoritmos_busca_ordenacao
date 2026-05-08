#include <stdlib.h>
#include <stdio.h>
#include "busca_ordena.h"


int busca_linear (int elem, int tamanho, int* vet){

    int cont = 0;
    for(int i = 0; i < tamanho; i++){
        cont++;
        if (elem == vet[i]){
            printf("\n A BUSCA LINEAR LEVOU %d ETAPAS", cont);
            return i;   // RETORNA A POSIÇAO DO ELEMENTO ENCONTRADO
        }
    }
    return -1;
}


int busca_binaria(int elem, int tamanho, int* vet){

    int ini = 0;            // PRIMEIRA POSIÇAO DA PARTE ANALISADA DA ESTRUTUTA
    int fim = tamanho - 1;      // ULTIMA POSIÇAO DA PARTE ANALISADA DA ESTRUTURA
    int cont = 0;

    while( fim >= ini ){
        int meio = ((ini + fim) / 2);   // POSIÇAO CENTRAL DA PARTE ANALISADA DA ESTRUTURA
        cont++;

        if (elem > vet[meio]){  // VERIFICANDO SE O ELEMENTO DESEJADO É MAIOR QUE O CENTRAL
            
            // O ELEMENTO DESEJADO ESTA A DIREITA DO ELEMENTO CENTRAL
            ini = meio + 1;
        }
        else if(elem < vet[meio]){

            // O ELEMENTO DESEJADO ESTA A ESQUERDA DO ELEMENTO CENTRAL
            fim = meio - 1;
        }
        else{   // ELEMENTO CENTRAL EH O ELEMENTO DESEJADO
            printf("\n A BUSCA BINARIA LEVOU %d ETAPAS", cont);
            return meio;
        }
    }
    return -1;
}


void bubble_sort (int tamanho, int *vet){
    int i, j, aux;

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {  // VERIFICAÇAO PARA COLOCAR O MAIOR ELEMENTO NO FINAL

                aux = vet[j];         // TROCA DE ELEMENTOS
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

// QUICK SORT COM PIVÔ NO PRIMEIRO ELEMENTO
void quick_sort(int tamanho, int* vet) {
    if (tamanho > 1) {
        int pivo = vet[0];
        int a = 1;
        int b = tamanho - 1;

        do {
            while (a < tamanho && vet[a] <= pivo) a++;
            while (vet[b] > pivo) b--;
            
            if (a < b) {    // TROCA a COM b
                float aux = vet[a];
                vet[a] = vet[b];
                vet[b] = aux;
                a++;
                b--;
            }
        } while (a <= b);

        vet[0] = vet[b]; // TROCA O PIVO
        vet[b] = pivo;

        // CHAMADAS RECURSIVAS
        quick_sort(b, vet);
        quick_sort(tamanho - a, &vet[a]);
    }
}


int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // Ordem crescente
}
