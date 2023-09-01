#include <stdio.h>


int main(void){

	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	int v[n];
	int x, i;
	for(i=0; i<n; i++){
		printf("Digite o valor %d: ", i);
		scanf("%d", &v[i]);
	}
	printf("Digite o valor que será procurado: ");
	scanf("%d", &x);

	for(i=0; i < n && v[i] != x; i++)
	;
	printf("O numero está na posição %d\n", i);

	return 0;
}