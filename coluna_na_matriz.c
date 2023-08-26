#include <stdio.h>

void F(double M[][12], char T, int C);

int main(void){
	double M[12][12];
	int i, j, C;
	char T;

	scanf("%d", &C);
	scanf(" %c", &T);


	for(i=0; i<12; i++){
		for(j=0; j<12; j++){
			scanf("%lf", &M[i][j]);
		}
	}

	F(M, T, C);


	return 0;
}

void F(double M[][12], char T, int C){
	double valor = 0.0;
	int i;
	for(i=0; i<12; i++){
		valor += M[i][C];
	}

	if (T == 'S'){
		printf("%.1lf\n", valor);
	}
	else if (T == 'M'){
		printf("%.1lf\n", valor/12.0);
	}
}