#ifndef DATAPARANUMERO_H
#define DATAPARANUMERO_H
#include <stdio.h>


//declara a função F

int F(int aa, int mm){
	if (mm <= 2){
		return aa-1;
	}
	else{
		return aa;
	}
}

//declara função G

int G(int mm){
	if(mm <= 2){
		return mm + 13;
	}
	else{
		return mm +1;
	}
}

//função que transforma os dias em um valor numérico

int N(int dd, int mm, int aa){
	int numero = ((1461 * F(aa, mm) )/4) + ((153 * G(mm))/5) + (dd);
	return numero;
}

#endif