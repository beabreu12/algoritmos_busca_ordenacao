#include <stdlib.h>
#include <stdio.h>
#include "busca_ordena.h"

void main(){


    int vet[]={37, 25, 44, 33, 64, 86, 18, 12, 92, 48};
    int tamanho = (sizeof(vet)/sizeof(vet[0]));
    int elem = 6;
    int pos;

    // ORDENANDO O VETOR
    quick_sort(tamanho, vet);

    for(int i = 0; i < tamanho; i++){
        printf("\t %d", vet[i]);
    };

    printf("\n \n");
    system("pause");


    // BUSCANDO ELEMENTO
    //pos = busca_linear(elem, tamanho, vet);
    //pos = busca_binaria(elem, tamanho, vet);

    printf("\n ELEMENTO %d ENCONTRADO NA POSICAO %d \n \n", pos, vet[pos]);


}



// gcc main.c busca_ordena.c -o programa.exe
