#include <stdio.h>

struct Galpao{
	int codigo;
	char desc[20];
	float qtd;
};

int main(void){
	int i, j, k, l;
//Declaração de uma matriz de struct.
	struct Galpao materiais[10][10];

	for (i=0; i<2; i++){
	 	for(j=0; j<2; j++){
	 		printf("\n");
	 		printf("Digite o Codigo e a Descrição do material para a opisção (%d, %d): ", i, j);
	 		scanf("%d: %s", &materiais[i][j].codigo, materiais[i][j].desc);
	 		printf("\nDigite a quantidade desse material nessa posição:");
	 		scanf("%f", &materiais[i][j].qtd);
	 		

		}
	}

//Laço para percorrer e somar a quantidade de cada elemento igual na matriz

	for(i=0; i<2; i++){
	 	for(j=0; j<2; j++){
	 		int codigo_atual = materiais[i][j].codigo;
	 		float totalqtd = materiais[i][j].qtd;
	//Percorro a matriz novamente procurando elementos cujo codigo são iguais
	 		for (k=0; k<2; k++){
	 			for(l=0; l<2; l++){
	 				if(materiais[k][l].codigo == codigo_atual){
	 					totalqtd += materiais[k][l].qtd;
	 					materiais[k][l].qtd = 0; //Zero a posição que ja somei
	 				}
	 			}
	 		}
	 	if (totalqtd > 0){
	 		printf("Material código: %d, nome: %s\n", materiais[i][j].codigo, materiais[i][j].desc);
	 		printf("Quantidade: %.2f\n",totalqtd);
	 	}
	}
}

	return 0;
}