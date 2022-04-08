#include <stdio.h>

//troca de valores entre variaveis
void swap(int vetor[], int i, int j){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}

//funcao respondavel por retornar a posicao do pivo
int acharPivo(int vetor[], int indmin, int indmax){

	//inicialmente o pivo é o primeiro item do vetor
	int i = indmin;
	int j = indmax+1;

	while(1){

		//incrementando i
		while(vetor[++i]<vetor[indmin])
			if(i==indmax) break;

		//decrementando j, ate que i e j sejam iguais, que é a condicao de saida da while maior
		while(vetor[indmin]<vetor[--j])
			if(j==indmin) break;

		//condicao de parada e saída do while
		if(i >= j) break;

		/*troco a posicao do vetor na posicao i e na posicao j
		aqui terei um certo i e um certo j, de acordo com QUANDO eles sairam dos mini While
		por isso, ao trocar, teremos o elemento da esquerda definitivamente MENOR que o pivo,
		e o elemento a direita, MAIOR que o pivo, gracas as suas condicoes de parada nos whiles
		correspondentes*/
		swap(vetor,i,j);		
	}

	//aqui portanto trocamos TERMINAR ISSO
	if(j!=indmin)
		swap(vetor,indmin,j);

	/*retorna a posicao final do pivo, e temos elementos menores que ele a esquerda,
	e maiores a sua direita*/
	//j é o indice do pivo
	return j;
}

/*ordenacao com quicksort
(apos escolher um PIVÔ, teremos a parte MENOR que o pivo, e a parte MAIOR que o pivo
logo, o pivo já esta na posicao certa dele no vetor)*/
void quicksort(int vetor[], int indmin, int indmax){
	//significa que ja chegou no caso de um vetor de 1 elemento, onde ele mesmo é o pivo
	if(indmax <= indmin)
		return;

	//chama a funcao para achar o pivo do vetor
	int posPivo = acharPivo(vetor, indmin, indmax);

	//recursao para ordenar a parte do vetor com elementos MENORES que o PIVO
	quicksort(vetor, indmin, posPivo-1);
	//recursao para ordenar a parte do vetor com elementos MAIORES que o PIVO
	quicksort(vetor, posPivo+1, indmax);	
}

int main(){

	int n;
	
	//ler o tamanho n que o vetor terá
	scanf("%d",&n);

	int vetor[n];

	//ler um vetor qualquer para ser ordenado
	for(int i=0; i<n; i++)
		scanf("%d",&vetor[i]);

	quicksort(vetor, 0, n-1);

	//imprimir o vetor ordenado
	for(int i=0; i<n; i++)
		printf("%d ",vetor[i]);

	return 0;
}