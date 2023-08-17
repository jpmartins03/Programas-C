#include <stdio.h>
#include <stdlib.h>

int diferença;
int D;
//declarar função F

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


int main(void){

	struct{
		int dd;
		int mm;
		int aa;
		int N;

	}data1;

	printf("Insira uma data no formato dd/mm/aa: ");
	scanf("%d/%d/%d", &data1.dd, &data1.mm, &data1.aa);
	printf("\n");

	data1.N = ((1461 * F(data1.aa, data1.mm) )/4) + ((153 * G(data1.mm))/5) + (data1.dd);

	D = ((data1.N - 621049)%7);

	if (D == 0){
		printf("É domingo\n");
	}
	else if (D == 1){
		printf("É segunda\n");
	}
	else if (D == 2){
		printf("É terça\n");
	}
	else if (D == 3){
	printf("É quarta\n");
	}
	else if (D == 4){
		printf("É quinta\n");
	}
	else if (D == 5){
		printf("É sexta\n");
	}
	else{
		printf("É sabado\n");
	}
	return 0;
}