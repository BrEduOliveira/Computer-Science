#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>

/* Define o tipo de dado no */
typedef struct NoTag {
	int info;
	struct NoTag *link;
}no;

void inicializa_Pilha(no **L) {
	/* atribui NULL ao ponteiro L */
	*L = NULL;
}

void imprime_Pilha(no **L) {
	no *P;
	P = *L; // P recebe o endereco do primeiro no da lista
	
	printf("\n Itens da Pilha (lista LIFO):\n");
	while(P != NULL) {
		printf("\n %d", P->info);
		P = P->link;
	}
}

void PUSH(no **L, int x) {
	/* declara um ponteiro denominado N */
	no *N;
	
	/* aloca mem�ria para armazenar o novo n� e atribui o endere�o da �rea reservada para N */
	N = (no *) malloc (sizeof(no));
	/* armazena a informa��o no novo n� */
	N->info = x;

	/* o link do novo n� recebe o endere�o do n� apontado por L 
	   ou seja , o link do novo n� aponta para o antigo primeiro n� da lista*/
	N->link = *L;
	
	/* L recebe o endere�o de N */
	*L = N;
}

void POP(no **L, int *n) {
	no *AUX;
	/* verifica se existe dados na pilha */
	if (*L != NULL) {
		/* faz a chamada recursiva da pilha */
		*n = (*L)->info;
		/* o ponteiro AUX recebe o pr�ximo da pilha*/
		AUX = *L;
		/* aux recebe o pr�ximo dado*/
		*L = (*L)->link;
		/* o valor � excluido (pop)*/
		free(AUX);
	}
}

int main(void){	
	no *L;
	char aux[10], inversa[10];
	int x, c, valor;
	char choice[10];


	setlocale(LC_ALL, "Portuguese");
	inicializa_Pilha(&L);
	
	do{
		printf("\n");
		printf("PILHA \n\n");
		printf("1 - PUSH\n");
		printf("2 - POP\n");
		printf("3 - Imprime o inverso do ultimo item da PILHA\n");
		printf("4 - Sair\n");
		printf("\n Escolha: ");
		gets(choice);
		c = atoi(choice);
		
		switch(c){
			case 1:
				printf(" \nEntre com o item a ser inserido na PILHA: ");
				gets(aux);
				x = atoi(aux);
				strcpy(inversa,aux);
				strrev(inversa);
				valor = strcmp(aux, inversa);
				PUSH(&L,x);
				if (valor == 0)
   					printf("\nA palavra %s � pal�ndroma\n", aux);
				else
   					printf("\nA palavra %s n�o � pal�ndroma\n", aux);
   				system("pause");
				system("cls");
				break;
			case 2:
				POP(&L,&x);
				printf(" \nItem retirado da PILHA: %d", x);
				break;
			case 3:
				printf("\n\n");
				printf("O inverso do �ltimo item inserido �: %s\n", inversa);
				break;
			case 4:
				exit(0);
				break;
		};
	}while (c != 4);

	return 0;
}
