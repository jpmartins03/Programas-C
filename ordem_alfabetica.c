#include <stdio.h>
#include <string.h>


int i, j;


int main(void){

	struct{
		int num;
		char nome[50];
		float preco;
	}prod[3], ordem[3], aux;
/*____________________________________________________________________________________
Entradas*/

	for (i = 0; i < 3; i++){
		printf("\n");
		printf("Digite o nome do produto %d: ", i+1);
		scanf(" %[^\n]", prod[i].nome);
		printf("\n");
		printf("Digite o numero do produto %d: ", i+1);
		scanf("%d", &prod[i].num);
		printf("\n");
		printf("Digite o preço do produto %d: ", i+1);
		scanf("%f", &prod[i].preco);
		printf("\n%s %d %.2f\n", prod[i].nome, prod[i].num, prod[i].preco);
		
	}
	for (i = 0; i < 3; i++) {
	    strcpy(ordem[i].nome, prod[i].nome);
	    ordem[i].num = prod[i].num;
	    ordem[i].preco = prod[i].preco;
}
/*____________________________________________________________________________________
Loop que coloca os produtos em ordem crescente*/
	for(j = 0; j<3; j++){
		for (i = 2; i >=0; i--){
		    if (strcmp(ordem[i].nome, ordem[i-1].nome)<0){
		    	aux = ordem[i];
		    	ordem[i] = ordem[i-1];
		    	ordem[i-1] = aux;
				}
			}
		}
	i = 0;
	printf("\nEm ordem alfabética temos os produtos: \n");
	for (i=0; i<3; i++){
		fflush(stdin);
		printf("Nome: %s, Código: %d, Preço: R$%.2f\n", ordem[i].nome, ordem[i].num, ordem[i].preco);
	    }
	return 0;
}