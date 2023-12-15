//ALUNO: João Pedro Martins Montera. RGA: 202319070734.

// REQUISITOS --------------------> LISTAS LINEARES
/*
Sejam S1 e S2 dois conjuntos disjuntos de números inteiros.
Suponha que S1 e S2 estão implementados em duas listas
lineares em alocação encadeada. Escreva uma função uniao
que receba as listas representando os conjuntos S1 e S2 e devolva
uma lista resultante que representa a união dos conjuntos, isto é,
uma lista linear encadeada que representa o conjunto S = S1 ∪ S2.
Considere os casos em que as listas lineares encadeadas são
com cabeça e sem cabeça.
*/

#include <stdio.h>
#include <stdlib.h>

//[==================================================================================================================================================]
//															  DEFINIR TIPO CELULA

struct cel
{
	int chave;
	struct cel *prox;
};

typedef struct cel celula;

//[==================================================================================================================================================]
//														  FUNÇAO QUE LIBERA A MEMÓRIA

void Ffree(celula *lista)
{
    celula *p;
    celula *trash;
    p = lista;

    while(p != NULL)
    {
        trash = p;
        p = p -> prox;
        free(trash);
    }
    printf("Todas as celulas foram desalocadas.\n");
}

//[==================================================================================================================================================]
//														  FUNÇAO QUE PRINTA A LISTA

void Fprint(celula * lst, int qtd)
{
    celula *pcel;                                                               // cria um ponteiro do tipo celula para apontar para a lista.
    int i = 0;

    for(pcel = lst; pcel != NULL; pcel = pcel -> prox, i++)                  // atribui ao ponteiro pcel o pontiero para a lista. enquanto este
    {                                                                       // ponteiro nao apontar para NULL o loop continua. A cada iteração o
        printf("Conteudo da célula %d = %d\n", i, pcel -> chave);          // pcel recebe o ponteiro para a proxima celula(nó).
    }
}



//[==================================================================================================================================================]
//														  FUNÇAO QUE UNE AS LISTAS

celula * uniao(celula *S1, celula *S2)
{
     if (S1 == NULL)
    {
        return S2;
    }
    else if (S2 == NULL)
    {
        return S1;
    }
    celula *p1, *p2;
    p1 = S1;
    p2 = NULL;

    while(p1 != NULL)
    {
        p2 = p1;
        p1 = p1 -> prox;
    }

    p2 -> prox = S2;

    celula *U = S1;
    printf("Celulas unidas.\n");
    return U;
}

//[==================================================================================================================================================]
//																	MAIN
int main(void)
{
    int qtd1, qtd2, key;
    celula *S1 = NULL;
    celula *S2 = NULL;
    celula *S1head = NULL;
    celula *S2head = NULL;
    celula *Uhead = NULL;
    int hashead;
    printf("Deseja que as listas possuam cabeça?\n");
    printf("Digite 1 para sim e 0 para nao: ");
    scanf("%d", &hashead);
    if(hashead == 1)
    {
        S1head = (celula*)malloc(sizeof(celula));
        S1head -> chave = -1;
        S1head -> prox = NULL;

        
        S2head = (celula*)malloc(sizeof(celula));
        S2head -> chave = -1;
        S2head -> prox = NULL;

        
        Uhead = (celula*)malloc(sizeof(celula));
        Uhead -> chave = -1;
        Uhead -> prox = NULL;
    }

//{-------------------------------------------------------------------------------------------------------------------------------------------------}
//												loop para alocar e atribuir valor às celulas

//			para S1
    printf("Digite a quantidade de células a serem adicionadas em S1: ");
    scanf("%d", &qtd1);
    for (int i = 0; i < qtd1; i++) {
        printf("Digite o valor da célula %d de S1: ", i);
        scanf("%d", &key);
        celula *novaCelula = (celula *)malloc(sizeof(celula));
        novaCelula->chave = key;
        novaCelula->prox = NULL;  // Inicializa a nova célula com NULL

        // Se a lista não estiver vazia, encontra o último elemento e adiciona o novo após ele
        if (S1 != NULL) {
            celula *ultimo = S1;
            while (ultimo->prox != NULL) {
                ultimo = ultimo->prox;
            }
            ultimo->prox = novaCelula;
        } else {
            // Se a lista estiver vazia, o novo elemento se torna o primeiro
            S1 = novaCelula;
        }

        if (hashead == 1) {
            if (i == 0) {
                S1head->prox = S1;
            }
        }
    }
    printf("Células de S1 alocadas.\n");

    //                  para s2
    printf("Digite a quantidade de células a serem adicionadas em S2: ");
    scanf("%d", &qtd2);

    for (int i = 0; i < qtd2; i++) {
        printf("Digite o valor da célula %d de S2: ", i);
        scanf("%d", &key);
        celula *novaCelula = (celula *)malloc(sizeof(celula));
        novaCelula->chave = key;
        novaCelula->prox = NULL;                            

        if (S2 != NULL)                                     // Se a lista não estiver vazia, encontra o último elemento e adiciona o novo após ele
            {   
            celula *ultimo = S2;
            while (ultimo->prox != NULL)
            {
                ultimo = ultimo->prox;
            }
            ultimo->prox = novaCelula;

        }
        else                                                // Se a lista estiver vazia, o novo elemento se torna o primeiro
        {     

            S2 = novaCelula;
        }

        if (hashead == 1)
        {
            if (i == 0)
            {
                S2head->prox = S2;
            }
        }
    }
    printf("Células de S2 alocadas.\n");


//{-------------------------------------------------------------------------------------------------------------------------------------------------}
//																printa as listas antes da uniao
        printf("S1:\n");
        Fprint(S1, qtd1);
        printf("S2:\n");
        Fprint(S2, qtd2);

//{-------------------------------------------------------------------------------------------------------------------------------------------------}
//														chama a funcao que une e printa a lista resultante

        celula *uniaoResultante = uniao(S1, S2);
        if(hashead == 1)
        {
            Uhead = uniaoResultante;
            free(S1head);
            free(S2head);
        }
        printf("União: \n");
        Fprint(uniaoResultante, (qtd1+ qtd2));

//{-------------------------------------------------------------------------------------------------------------------------------------------------}
//																libera a memória alocada

        Ffree(uniaoResultante);


	return 0;
}

//[==================================================================================================================================================]
