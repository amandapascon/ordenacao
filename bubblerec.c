//Amanda Carnio Pascon

#include <stdio.h>

void swap(int vetor[], int i, int j){
    int aux;
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}


//Funcao Bubble recursivo
void bubbleSort(int vetor[], int n) 
{ 
    // Caso de saida
    if (n == 1) 
        return; 
  
    //depois de uma passo movemos o maior elemento pro final 
    for (int i=0; i<n-1; i++) 
        if (vetor[i] > vetor[i+1]) 
            swap(vetor, i, i+1); 
  
    // Temos o maior, entao "diminuimos 1" no tamanho do vetor nao ordenado
    // Pq ja temos mais um elemento ordenado
    // Chamamos entao a funcao pro que resta do vetor (n-1)
    bubbleSort(vetor, n-1); 
} 

int main(){

    int n;
    
    //ler o tamanho n que o vetor terá
    scanf("%d",&n);

    int vetor[n];

    //ler um vetor qualquer para ser ordenado
    for(int i=0; i<n; i++)
        scanf("%d",&vetor[i]);

    bubbleSort(n, vetor, 0);

    //imprimir o vetor ordenado
    for(int i=0; i<n; i++)
        printf("%d ",vetor[i]);

    return 0;
}