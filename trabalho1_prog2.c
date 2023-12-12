
//todos os algoritmos de ordenação devem ser recursivos e ordenar de forma decrescente
//perguntar se o usuário deseja imprimir apenas o vetor ordenado ou apenas o tempo de processamento de cada algoritmo

#include <stdio.h>  //para entradas e saidas
#include <stdlib.h>  //para usar srand
#include <time.h> //para usar time e clock

#define MAX 1000000
 int V[MAX];    // Tamanho máximo do vetor
 int VAUX[MAX]; // Tamanho máximo do vetor auxiliar
/*===============================================================================================
GERADOR DE NUMEROS*/
int gerador(int min, int max){
	return min + rand()%(max - min + 1);
}
void geranum(int V[], int qtd){
	int min;
	int max;
	srand(time(NULL));

	printf("Digite o valor mínimo e o valor maximo dos numeros que serao gerados (min max): ");
	scanf("%d %d", &min, &max);
	printf("\n");

	for(int i=0; i<qtd; i++){
		int num = gerador(min, max);
		V[i] = num;
	}
}
/*===============================================================================================
ALGORITMO SELECTION SORT*/
void selection_sort(int V[], int n){
	int i, j;
	int min, aux;

	for(i=0; i<n; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(v[j]<v[min]){
				min = j;	
			}
		}
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}
}
/*===============================================================================================
ALGORITMO INSERTION SORT*/
void insertion_sort(int *V, int n){
	int i, j, aux;
	for(i=1; i<n; i++){ //percorre o vetor a partir do primeiro item até o penultimo
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
/*===============================================================================================
ALGORITMO MERGE SORT*/
void merge_sort(int V[], int VAUX[], int inicio, int fim){
	int meio, i, j, k;
	if(inicio < fim){
		meio = (inicio+fim)/2;
		merge_sort(V, VAUX, inicio, meio);//divide a primeira metade do vetor
		merge_sort(V, VAUX, meio+1, fim);// divide a segunda metade do vetor
		//intercalação ----------------> Depois de dividir todos vetores até que fiquem de tamanho 1, os compara e insere no vetor auxiliar
		i = inicio;
		k = inicio; //k é a posição do vetor auxiliar a ser preenxida.
		j = meio+1;
		while((i<=meio)&&(j<=fim)){ //equanto a primeira metade do vetor e a segunda metade nao terminarem(caso uma das duas terminem o laço para)
			if(V[i]<V[j]){VAUX[k]=V[i]; i++;} //se o elemento da primeira metade foi menor ele entra primeiro no vetor aux e o contador do a prmeira metade aumenta
			else		 {VAUX[k]=V[j]; j++;} //se o elemento da segunda que for ele que entra no aux e seu contador aumenta.

			k++;	
		}

		while(i<=meio){VAUX[k]=V[i]; i++; k++;} //se o ultimo loop for quebrado e ainda sobrarem elementos eles tabem devem ser considerados
		while(j<=fim){VAUX[k]=V[j]; j++; k++;}
		for(k=inicio; k<=fim; k++){ //coloca os valores agora ordenados no novo vetor
			V[k] = VAUX[k];
		}
	}
}
/*===============================================================================================
ALGORITMO QUICK SORT*/
void quick_sort(int V[], int esquerda, int direita){
		
	int pivo = V[esquerda];
	int l = esquerda; //contador da barra da esqurda
	int r = direita; // contador da barra da direita

	while(l<=r){ //enquanto a barra nao ultrapassar a outra

		while (V[l]<pivo) l++; //enquanto a barra da esqudda for menor do que o pivo, ela anda uma posição para frente
		while(V[r]>pivo) r--; //esnquanto a barra da direita for maior que o pivo ela anda uma posição para tras
			
		if (l<=r){
			int temp = V[l];
			V[l] = V[r];
			V[r] = temp;
			l++;
			r--;

		}
	}
	if(esquerda < r) quick_sort(V, esquerda, r);
	if(l < direita)  quick_sort(V, l, direita);
}
/*===============================================================================================
MAIN*/
int main(void){
	int n;
	printf("Digite o valor de N (tamanho do vetor): ");
	scanf("%d", &n);
	if (n > MAX) {
       printf("Tamanho do vetor excede o limite. Por favor, escolha um tamanho menor.\n");
       return 1; // Saída com erro
    }

	clock_t inicio, fim;
	double tempo_decorrido;
/*===============================================================================================
SELECTION SORT*/
	geranum(V, n);
	inicio = clock();

	selection_sort(n, V);

	fim = clock();

	tempo_decorrido = (double)(fim-inicio)/CLOCKS_PER_SEC;
	printf("O tempo decorrido no selection sort foi de: %f segundos\n", tempo_decorrido);
	printf("\n");	
/*===============================================================================================
INSERTION SORT*/
	geranum(V, n);
	inicio = clock();

	insertion_sort(V, n);

	fim = clock();

	tempo_decorrido = (double)(fim-inicio)/CLOCKS_PER_SEC;
	printf("O tempo decorrido no insertion sortfoi de: %f segundos\n", tempo_decorrido);	
	printf("\n");	
/*===============================================================================================
MERGE SORT*/
	geranum(V, n);
	inicio = clock();

	merge_sort(V, VAUX, 0, n-1);

	fim = clock();

	tempo_decorrido = (double)(fim-inicio)/CLOCKS_PER_SEC;
	printf("O tempo decorridono merge sort foi de: %f segundos\n", tempo_decorrido);
	printf("\n");	
/*===============================================================================================
QUICK SORT*/
	geranum(V, n);
	inicio = clock();

	quick_sort(V, 0, n-1);

	fim = clock();

	tempo_decorrido = (double)(fim-inicio)/CLOCKS_PER_SEC;
	printf("O tempo decorrido no quick sort foi de: %f segundos\n", tempo_decorrido);
	printf("\n");	
/*===============================================================================================
*/

	return 0;
}

//ler valor n (tamanho do vetor)

//gerar n valores aleatóriamente

//random (falta implementar sem ser uma header)

//clock (falta descobrir um jeito de rodar a função clock em cada algoritmo no mesmo codigo fonte)

//testar com entradas de tamanho 10⁶, 10⁷, 10⁸. 

