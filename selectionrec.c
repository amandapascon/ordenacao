#include <stdio.h>

void swap(int vetor[], int i, int minimo){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[minimo];
	vetor[minimo] = aux;
}

int menorElem(int vetor[], int i, int j){
	int x;

	if(i == j) return i;

	int k = menorElem(vetor, i+1, j); 

	if(vetor[i]<vetor[k])
		x=i;
	else
		x=k;

	return x; 
}

/*ordenacao com selection
(busca o menor elemento da sequencia nao ordenada e concatena ele na sequencia ordenada)*/
void selectionrec(int n, int vetor[], int indice){

	//retorna quando indice for igual ao n
	if(indice == n) return;

	//chama a funcao pra achar o menor elemento
	int k = menorElem(vetor, indice, n-1);

	//com o indice do menor em maos, fazemos a troca dos elementos, para adicionar mais um a sequencia ordenada
	if(k!=indice)
		swap(vetor,indice,k);

	selectionrec(n, vetor, indice+1);
	
}

int main(){
    
	int n;
	
	//ler o tamanho n que o vetor terá
	scanf("%d",&n);

	int vetor[n];

	//ler um vetor qualquer para ser ordenado
	for(int i=0; i<n; i++)
		scanf("%d",&vetor[i]);

	selectionrec(n, vetor, 0);

	//imprimir o vetor ordenado
	for(int i=0; i<n; i++)
		printf("%d ",vetor[i]);

	return 0;
}