#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Define o tipo de dado no */
typedef struct NoTag {
	char info;
	struct NoTag *link;
}no;

void inicializa_Pilha(no **L) {
	/* atribui NULL ao ponteiro L */
	*L = NULL;
}

void imprime_Pilha(no **L) {
	no *P;
	P = *L; // P recebe o endereco do primeiro no da lista
	
	printf("\n Itens da Pilha (lista LIFO):");
	while(P != NULL) {
		printf("\n %d", P->info);
		P = P->link;
	}
}

void PUSH(no **L, char x) {
	/* declara um ponteiro denominado N */
	no *N;
	
	/* aloca memória para armazenar o novo nó e atribui o endereço da área reservada para N */
	N = (no *) malloc (sizeof(no));
	/* armazena a informação no novo nó */
	N->info = x;

	/* o link do novo nó recebe o endereço do nó apontado por L 
	   ou seja , o link do novo nó aponta para o antigo primeiro nó da lista*/
	N->link = *L;
	
	/* L recebe o endereço de N */
	*L = N;
}

void POP(no **L, char *n) {
	no *AUX;
	/* verifica se existe dados na pilha */
	if (*L != NULL) {
		/* faz a chamada recursiva da pilha */
		*n = (*L)->info;
		/* o ponteiro AUX recebe o próximo da pilha*/
		AUX = *L;
		/* aux recebe o próximo dado*/
		*L = (*L)->link;
		/* o valor é excluido (pop)*/
		free(AUX);
	}
}

int main(void){	
	no *L;
	char aux[10];
	int x, c;
	char choice[10];

	inicializa_Pilha(&L);
	
	do{
		printf("\n");
		printf("PILHA \n");
		printf("1 - PUSH\n");
		printf("2 - POP\n");
		printf("3 - Imprime Itens da PILHA\n");
		printf("4 - Sair\n");
		printf("\n Escolha: ");
		gets(choice);
		c = atoi(choice);
		
		switch(c){
			case 1:
				printf(" \nEntre com o item a ser inserido na PILHA: ");
				gets(aux);
				x = atoi(aux);
				PUSH(&L,x);
				break;
			case 2:
				POP(&L,&x);
				printf(" \nItem retirado da PILHA: %d", x);
				break;
			case 3:
				imprime_Pilha(&L);
				break;
			case 4:
				exit(0);
				break;
		};
	}while (c != 4);

	return 0;
}
