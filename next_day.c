#include <stdio.h>

// Recebe uma data dd/mm/aa e printa o dia seguinte.

int main(void){
	int bissexto;

	struct{
		int dia;
		int mes;
		int ano;
		
	} atual, proximo;

	printf("Insira a data (dd/mm/aa): ");
	scanf("%d/%d/%d", &atual.dia, &atual.mes, &atual.ano);

	if ((atual.ano%4 == 0 && atual.ano %100 != 0)||(atual.ano%4 ==0 && atual.ano%100 ==0 && atual.ano%400 == 0)){
		bissexto = 1;
		printf("É ano bissexto\n");
	}

// Atribui os valores de dia mes e ano atuais ao proximo acrescido de um dia

	proximo = atual;
	proximo.dia ++;

// Se é o ultimo dia de um mes que tenha 31 dias

	if ((atual.dia == 31 && atual.mes == 01) || (atual.dia == 31 && atual.mes == 3) || (atual.dia == 31 && atual.mes == 5)
	|| (atual.dia == 31 && atual.mes == 7) || (atual.dia == 31 && atual.mes == 8) || (atual.dia == 31 && atual.mes == 10)){

		proximo.dia = 01, proximo.mes ++;
	}

//se é o ultimo dia do ano

	else if(atual.dia == 31 && atual.mes == 12){

		proximo.dia = 01, proximo.mes = 01, proximo.ano ++;
	}

//se é fevereiro

	else if (atual.mes == 2){
		if (bissexto == 1){
			if(atual.dia == 29){
				proximo.dia = 1, proximo.mes ++;
			}
			
		}
		else{
			if (atual.dia == 28){
				proximo.dia = 1, proximo.mes ++;
			}
					}
		}
//se é um mes que tem 30 dias
	else{
		if (atual.dia == 30){
			proximo.dia = 01, proximo.mes ++;
		}

	}
	printf("%02d/%02d/%d\n", proximo.dia, proximo.mes, proximo.ano);

	return 0;

	}