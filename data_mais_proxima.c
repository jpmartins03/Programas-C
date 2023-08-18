#include "dataparanumero.h"
#include <stdio.h>
#include <stdlib.h>

int X;
int i;
int prox_num;
//_____________________________________________________________________________________________
//Registro
struct{
	int dd;
	int mm;
	int aa;
	int num;	
}numero, datas[100], prox_data;

//____________________________________________________________________________________________
//Main
int main(void){
	printf("Digite uma data para servir de base no formato dd/mm/aa: ");
	scanf("%d/%d/%d", &numero.dd, &numero.mm, &numero.aa);

	numero.num = N(numero.dd, numero.mm, numero.aa);
	printf("Digite um valor X entre 0 e 100: ");
	scanf("%d", &X);

//____________________________________________________________________________________________
//Loop que converte todas as datas em valor numérico e armazena esses valores 

	for(i = 0; i < X; i++){
		printf("Digite a data %d no formato dd/mm/aa: ", i);
		scanf("%d/%d/%d", &datas[i].dd, &datas[i].mm, &datas[i].aa);
		datas[i].num = N(datas[i].dd, datas[i].mm, datas[i].aa);

	}

//____________________________________________________________________________________________
//loop que compara todos os valores numéricos e encontra a data mais proxima

	i = 0;
	prox_num = datas[0].num;
	prox_data = datas[0];

	for (i = 1; i < X; i++){
		if(abs(datas[i].num - numero.num) < abs(prox_num - numero.num)){
			prox_num = datas[i].num;
			prox_data = datas[i];
		}
	}
	printf("A data mais proxima é %02d/%02d/%02d\n", prox_data.dd, prox_data.mm, prox_data.aa);

	

	return 0;
}
