#include <stdio.h>

//ordenacao com insertion
void insertion(int n, int vetor[]){
	
}

int main(){

	int n;
	
	//ler o tamanho n que o vetor terá
	scanf("%d",&n);

	int vetor[n];

	//ler um vetor qualquer para ser ordenado
	for(int i=0; i<n; i++)
		scanf("%d",vetor[i]);

	insertion(n, vetor);

	//imprimir o vetor ordenado
	for(int i=0; i<n; i++)
		printd("%d",vetor[i]);

	return 0;
}