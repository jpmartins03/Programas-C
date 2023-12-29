
#include <stdio.h>
#include <stdlib.h>

//[==============================================================================================================================================]
//										        		   CRIAÇÃO DAS CELULAS

struct cel
{
	int chave;	  						   // espaço para armazenar dados.
	struct cel *prox; 			 		  // espaço para apontar para o proximo nó.
};

typedef struct cel celula; 	   		   // celula é o tipo, cells é o nome do tipo.



//[==============================================================================================================================================]

/*											OBS: NÃO DA PARA ALOCAR MEMORIA FORA DE ALGUMA FUNÇÃO.
											OS PROXIMOS TREXOS DE CODIGOS SAO EXEMPLOS E NAO FUN-
											CIONAM FORA DE FUNÇÕES OU JUNTOS EM UM MESMO CODIGO.
*/


//[==============================================================================================================================================]
//														LISTA VAZIA COM CABEÇA

celula c, *lista; 				 // cria uma variacel c do tipo celula e um ponteiro para esse mesmo tipo.
c.prox = NULL;					// faz o campo prox da variavel c apontar para NULL indicando que este é o ultimo nó, no caso o unico nó.
lista = &c;				       // faz o ponteiro lista receber o endereço da variavel celula c;

/* 
														O QUE ISSO FAZ A FINAL?
														
 1 - a variavel c é utilizada como a cabeça da lista, note que seu campo "chave" nem é preenchido pois ela nao tem conteudo.
 2 - exemplo de como ficou a celula: c = [NULL]
 3 - nesse caso por ser o unico elemento e portanto o ultimo, prox tambem aponta para NULL
 4 - caso nao fosse ele conteria o endereço da proxima celula.
 5 - o ponteiro lista recebe o endereço de c, que é a cabeça. Então o ponteiro aponta para o inicio da lista dado pela cabeça.
 6 -  Agora, se você desejar adicionar elementos à lista sem cabeça, precisará alocar dinamicamente novas células e ajustar os ponteiros conforme necessário.

*/
//															OU DINAMICAMENTE

celula *lista;										// cria um ponteiro chamado lista para um tipo celula
lista = (celula*)malloc(sizeof(celula));	       // aloca a memoria necesária para a cabeça da lista
lista -> prox = NULL;							  // faz com que o campo prox da celula cabeça aponte para NULL representando que a lista está vazia.

/* 
														O QUE ISSO FAZ A FINAL?

1 - o ponteiro *lista é criado para referenciar a cabeça da lista.
2 - na linha 2 fazemos com que lista receba como conteudo um ponteiro do tipo(celula*) apontando para o endereço de memória alocado.
3 - como todo tipo celula tem os campos "prox e chave", atribuimos NULL ao prox para representar que nao há proxima celula(nó).
4 - nao é preciso atribuir valor ao campo chave da cabeça pois ele é inicializado com um valor lixo e nao será considerado.

*/
//[==============================================================================================================================================]
//														LISTA VAZIA SEM CABEÇA

celula *lista;				// cria um ponteiro do tipo celula.
lista = NULL;			   // faz o ponteiro apontar para NULL indicando que 

/* 
														O QUE ISSO FAZ?
 1 - O ponteiro lista é um ponteiro para célula, mas neste momento não está apontando para nenhum nó pois a lista está vazia.
 2 - Ao atribuir NULL a lista, você está indicando que a lista está vazia, pois não há nenhum nó para apontar.
 3 - Neste momento, lista não aponta para nenhum lugar válido na memória.
 4 - // Agora, se você desejar adicionar elementos à lista sem cabeça, precisará alocar dinamicamente novas células e ajustar os ponteiros conforme necessário.
*/

//[==============================================================================================================================================]


int main(void)
{
	celula *p = NULL; 						 			 // cria um ponteiro do tipo cells e inicializando ele com NULL.
	celula *head = (celula *)malloc(sizeof(celula)); 	// aloca memoria para a cabeça da lista.
	head->prox = NULL; 							  	   // faz o prox da cabeça apontar para NULL.
	p = head;								    	  // faz o ponteiro da lista apontar para a cabeça.

	printf("O conteudo da cabeça é: %d\n", PTlist->chave);      // printa o conteudo do nó atual através do ponteiro.
	printf("O proximo da cabeça é: %p\n", PTlist->prox);		// printa o endereço do proximo nó, porem aqui ele é nulo.


	return 0;
}

