#include <stdio.h>


#define N 10

int main(void){
	int v[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *p = &v[0], *q = &v[N - 1], temp;			
	while (p < q) {
		temp = *p; //----------------------------> temp guarda a posição que p aponta.
		*p++ = *q;//-----------------------------> trocamos p pelo valor da posição apontada por q e incrementamos uma posição no ponteiro p.
		*q-- = temp;//---------------------------> trocamos o valor da posição q com o valor de temp (prosiçao inicial de q), e derementamos a posição de q.
	}

	for(int i=0; i<N; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}

/*
	Qual o conteúdo do vetor v após a execução do seguinte trecho
de código?

R = Ele inverte a ordem dos elementos.

*/