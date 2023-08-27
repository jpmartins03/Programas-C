#include <stdio.h>

void F(double M[][12], char T);

int main(void){
	double M[12][12];
	int i, j;
	char T;

	scanf(" %c", &T);


	for(i=0; i<12; i++){	
		for(j=0; j<12; j++){
			scanf("%lf", &M[i][j]);
		}
	}

	F(M, T);


	return 0;
}

void F(double M[][12], char T){
	double valor = 0.0;
	int i, j;

	for(i=1; i<12; i++){
		for(j=0; j<i; j++){
			valor += M[i][j];
		}
	
	}

	if (T == 'S'){
		printf("%.1lf\n", valor);
	}
	else if (T == 'M'){
		printf("%.1lf\n", valor/66.0);
	}
}