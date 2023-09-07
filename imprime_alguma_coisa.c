#include <stdio.h>
int n;
void imprime_alguma_coisa(int n);

int main(){
	printf("Digite um número:");
	scanf("%d", &n);
	if(n!=0){
	imprime_alguma_coisa(n);
	}
	else{
		printf("0\n");
	}
	printf(" é o equivalente em binário do decimal %d.", n);
	printf("\n");
}
void imprime_alguma_coisa(int n){
	if (n != 0) {						//Se n chegar a 0 é pq ja se contaram todos os bits
	imprime_alguma_coisa(n / 2);	   //chama a função denovo mas para o resultado da divisao inteira de n/2
	printf("%d",n % 2);				  //o print só será realizado quando n chegar a 0, e os print virão acontescendo
	}								 //de trás para frente com os valores de n respectivos de cada								
}