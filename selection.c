#include <stdio.h>

/*ordenacao com selection
(busca o menor elemento da sequencia nao ordenada e concatena ele na sequencia ordenada)*/
void selection(int n, int vetor[]){
	int minimo;

	/*ao final de uma iteracao teremos o vetor da posicao i trocado pelo vetor da posicao minimo,
	e com isso, a parte a esquerda do indice i já está ordenada, e podemos ir para i+1,
	nao mexendo mais na parte ordenada.*/
	for(int i=0; i<n; i++){
		minimo = i;
		//sequencia nao ordenada, de 0 a i temos a ordenada, de i+1 a n, a nao ordenada
		for(int j=i+1; j<n; j++)
			//procurando o menor vetor
			if(vetor[j]<vetor[minimo])
				//no final da iteracao, tera o indice do menor vetor na sequencia nao ordenada guardado em 'minimo'
				minimo=j;

	//com o indice do menor em maos, fazemos a troca dos elementos, para adicionar mais um a sequencia ordenada
	if(minimo!=i)
		swap(vetor,i,minimo);
	}
}

void swap(int vetor, int i, int minimo){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[minimo];
	vetor[minimo] = aux;
}

int main(){

	int n;
	
	//ler o tamanho n que o vetor terá
	scanf("%d",&n);

	int vetor[n];

	//ler um vetor qualquer para ser ordenado
	for(int i=0; i<n; i++)
		scanf("%d",vetor[i]);

	selection(n, vetor);

	//imprimir o vetor ordenado
	for(int i=0; i<n; i++)
		printd("%d",vetor[i]);

	return 0;
}