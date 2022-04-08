#include <stdio.h>

void Merge(int elem[], int auxiliar[], int minimo, int medio, int maximo){
	int i, k;
	i = minimo;
	k = medio+1;

	//funcao que faz a ordenacao num vetorzao, das duas metades ordenadas de vetorzinhos
	for(int j=minimo; j<=maximo; j++)
		auxiliar[j]=elem[j];

	for(int j= minimo; j<=maximo; j++)
		//as duas primeiras condicoes tratam de quando as posicoes de um vetor acaba e do outro nao, fazem continuar a atribuicao
		if(i > medio)
			elem[j]=auxiliar[k++];
		else if(k>maximo)
			elem[j]=auxiliar[i++];
		//essas condicoes fazem a concatenacao ordenando os vetores ordenados
		else if(auxiliar[k] < auxiliar[i])
			elem[j]=auxiliar[k++];
		else
			elem[j]=auxiliar[i++];	
}

void mergeSort(int elem[], int auxiliar[], int minimo, int maximo){
	//aqui já chegou no tam minimo de vetor para ordenar, no caso um vetor com um elemento	
	if(maximo <= minimo)
		return;
	
	int medio = minimo + ((maximo - minimo)/2);
	//ordena a primeira metade
	mergeSort(elem, auxiliar, minimo, medio);
	//ordena a segunda metade
	mergeSort(elem, auxiliar, medio+1, maximo);
	//ordena as duas metades ordenadas
	Merge(elem, auxiliar, minimo, medio, maximo);
}

int main(){

	int n;
	
	//ler o tamanho n que o vetor terá
	scanf("%d",&n);

	int vetor[n];
	int aux[n];

	//ler um vetor qualquer para ser ordenado
	for(int i=0; i<n; i++)
		scanf("%d",&vetor[i]);

	mergeSort(vetor, aux, 0, n-1);

	//imprimir o vetor ordenado
	for(int i=0; i<n; i++)
		printf("%d",vetor[i]);

	return 0;
}