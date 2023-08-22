#include<stdio.h>
#include<string.h>
/*========================================================================================
Declarações*/
int i, j, n;

struct torneio{
	char name[50];
	int points;
};
struct torneio aux;


void ordena(struct torneio equipes[]);
/*========================================================================================
Main*/

int main(void){
	printf("Digite a quantidade de equipes que participaram do torneio: ");
	scanf("%d", &n);
	struct torneio equipes[n];
	for (i=0; i<n; i++){
		printf("Digite o nome da equipe %d: ", i+1);
		scanf(" %[^\n]", equipes[i].name);
		printf("Digite a pontuação da equipe %d: ", i+1);
		scanf("%d", &equipes[i].points);

	}
	ordena(equipes);
	for(i=0; i<n-i; i++){
		for(j=0; j<n-i; j++){
			if ((equipes[i].points == equipes[i+1].points)&&(strcmp(equipes[i].name, equipes[i+1].name)>0)){
				aux = equipes[i];
				equipes[i] = equipes[i+1];
				equipes[i+1] = aux;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d°Lugar, equipe %s com %d ponto(s).\n", i+1, equipes[i].name, equipes[i].points);
	}
	return 0;
}
void ordena(struct torneio equipes[]){
	for(i=0; i<n; i++){
		for(j=n; j>0+i; j--){
			if(equipes[j].points > equipes[j-1].points){
				aux = equipes[j];
				equipes[j] = equipes[j-1];
				equipes[j-1] = aux;
			}
		}
	}
	printf("\n");
}