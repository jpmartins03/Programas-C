#include <stdio.h>
#define MAX 10

void insertion_sort(int *V){
	int i, j, aux;
	for(i=0; i<MAX-1; i++){ //percorre o vetor a partir do primeiro item até o penultimo
		if(V[i]>V[i+1]){
			aux = V[i+1];
			V[i+1] = V[i]; V[i] = aux;
			j = i-1; //j armazena o indice do item anterior para iniciar o laço interno comparando o aux com os itens anteriores
			while (j>=0){
				if(aux<V[j]){
					V[j+1] = V[j]; V[j] = aux;
				}
				else{
					break;
				}
				j--;
			}
		}

	}
}
int main(void){
	int V[MAX];
	int i;
	for(i=0; i<MAX; i++){
		printf("Digite o valor %d: ", i);
		scanf("%d", &V[i]);
	}
	printf("Vetor inicial\n");
	for(i=0; i<MAX; i++){
		printf("%d ", V[i]);
		printf("\n");
	}
	insertion_sort(V);
	printf("Vetor ordenado\n");
	for(i=0; i<MAX; i++){
		printf("%d ", V[i]);
		printf("\n");
	}
	return 0;
}