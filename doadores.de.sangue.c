#include <stdio.h>
#include <string.h>

int i, j, aux_num;

struct Doador{
	int code;
	char name[50];
	char type[3];
};

struct Doador aux;

/*_________________________________________________________________________________
Declara a função de ordenação crescente*/
int I(struct Doador doadores[], int n);
/*_________________________________________________________________________________
Declara a função de ordenação alfabética de nomes*/
int II(struct Doador doadores[], int n);
/*_________________________________________________________________________________
Declara a função de ordenação alfabética de tipo sanguineo + RH*/
int III(struct Doador doadores[], int n);
//_________________________________________________________________________________
int main(void){
	int n;
	printf("Digite a quantidade de doadores de 1 a 100: ");
	scanf("%d", &n);
	struct Doador doadores[n];
//preenchimento dos dados dos doadores
	for (i=0; i<n; i++){
		printf("Doador %d:\n", i+1);
		printf("Código: ");
		scanf("%d", &doadores[i].code);
		printf("Nome: ");
		scanf(" %[^\n]", doadores[i].name);
		printf("Tipo sanguíneo e RH: ");
		scanf("%s", doadores[i].type);
	}
//seleção do tipo de lista
	int opcao;
	printf("Selecione o formato da lista de doadores que deseja:\n");
	printf("1. Ordem crescente de códigos\n");
	printf("2. Ordem alfabética de nommes\n");
	printf("3. Ordem alfabética de tipo sanguíneo\n");
	printf("Digite a opçao desejada: ");
	scanf("%d", &opcao);
	printf("\n");
	switch(opcao){
		case 1:
			I(doadores, n);
		break;
		case 2:
			
			II(doadores, n);
		break;
		case 3:
			III(doadores, n);
		break;
	default:
		printf("Opção inválida.\n");
		break;
	}
	return 0;
}
/*_____________________________________________________________________________
Definição das funções*/
int I(struct Doador doadores[], int n){

	printf("Você selecionou listagem por ordem crescente de códigos.\n");

	for (i=0; i<n; i++){
		for(j=n-1; j>=0; j--){
			if(doadores[j].code < doadores[j-1].code){
				aux = doadores[j-1];
				doadores[j-1] = doadores[j];
				doadores[j] = aux;
			}
		}
	}

	for(i=0; i<n; i++){
		printf("Nome: %s, Código: %d, Tipo sanguíneo: %s\n", doadores[i].name, doadores[i].code, doadores[i].type);
	}
	return 1;
}
int II(struct Doador doadores[], int n){

	printf("Você selecionou listagem por ordem alfabética de nomes.\n");

	for(i=0; i<n; i++){
		for(j=n-1; j>=0; j--){
			if(strcmp(doadores[j].name, doadores[j-1].name)<0){
				aux = doadores[j-1];
				doadores[j-1] = doadores[j];
				doadores[j] = aux;
			}
		}
	}

	for(i=0; i<n; i++){
		printf("Nome: %s, Código: %d, Tipo sanguíneo: %s\n", doadores[i].name, doadores[i].code, doadores[i].type);
	}
	return 1;
}
int III(struct Doador doadores[], int n){

	printf("Você selecionou listagem por ordem alfabética de tipo sanguíneo + RH.\n");

	for(i=0; i<n; i++){
		for(j=n-1; j>=1; j--){
			if(strcmp(doadores[j].type, doadores[j-1].type)<0){
				aux = doadores[j-1];
				doadores[j-1] = doadores[j];
				doadores[j] = aux;
			}
		}
	}
	
	for(i=0; i<n; i++){
		printf("Nome: %s, Código: %d, Tipo sanguíneo: %s\n", doadores[i].name, doadores[i].code, doadores[i].type);
	}
	return 1;
}