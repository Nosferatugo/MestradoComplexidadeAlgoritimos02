#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] , std::cout<<" - ";
}

int dividir(int vetor[],int esq, int dir){
    int aux; 
    int cont = esq;

    for(int i=esq+1 ; i<=dir ; i++){

        if( vetor[i] < vetor[esq] ){
            cont++;
            aux=vetor[i];
            vetor[i]=vetor[cont];
            vetor[cont]=aux;
        }
    }

    aux=vetor[esq];
    vetor[esq]=vetor[cont];
    vetor[cont]=aux;

    return cont;
}

void quick(int vetor[],int esq, int dir){
    int pos;
    if(esq < dir){
        pos = dividir(vetor,esq,dir);
        quick(vetor,esq,pos-1);
        quick(vetor,pos+1,dir);
    }
}




int main(){


int quantidade;
	printf("Digite a quantidade de elementos: ");
	scanf("%d",&quantidade);
	int numeros[quantidade];
	
	printf("Digite %d numeros (separados por ENTER ou a tecla ESPACO):\n",quantidade);
	for(int i = 0; i < quantidade; i++)
        scanf("%d", &numeros[i]);

    
    printf("\n");
	


	std::cout << "Antes da execucao do QuickSort :" ;
    printArray(numeros, quantidade);
    std::cout << std::endl;
    std::cout << std::endl;

    quick(numeros,0,quantidade);
	
	std::cout << "Apos da execucao do QuickSort :" ;
    printArray(numeros,quantidade);
    std::cout << std::endl;

    

    system("pause");
    return 0;
}
