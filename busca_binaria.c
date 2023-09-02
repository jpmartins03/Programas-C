//Buscabinária necessita de um vetor préviamente ordenado
#include <stdio.h>


int buscabinaria(int v[], int item, int primeiro, int ultimo){


	if(primeiro <= ultimo){
		int meio = (primeiro+ultimo)/2;
		if (v[meio] == item){
			return meio;
		}
		else if(item < v[meio]){
			return buscabinaria(v, item, primeiro, meio -1);
		}
		else{
			return buscabinaria(v, item, meio +1 , primeiro);
		}
	}
}	
int main(void){
	int item;
	scanf("%d", &item);
	int v[10] = {2, 4, 6, 8, 16, 32, 64, 128, 256, 512};
	int primeiro = 0;
	int ultimo = 10;
	int posicao = buscabinaria(v, item, primeiro, ultimo);
	printf("%d\n", posicao);
	return 0;
}