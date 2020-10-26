/*
 * LISTA DUPLAMENTE ENCADEADA CIRCULAR
 */

/* Define o tipo de dado no */
typedef struct NoTag {
	int info;
	struct NoTag *prox;
	struct NoTag *prev;
} no;

/***** PILHA *****/
void inicializa_Pilha(no **L) {
	*L = NULL;
}

void imprime_LDLC(no **L){
	no *P;
	P = *L;
	if(*L != NULL){
		printf("\n Itens da Lista:");
		do{
			printf("\n %d", P->info);
			P = P->prox; 
		}while(P != *L);
	}
}

void imprime_Pilha(no **L) {
	no *P, *AUX;
	P = *L;
	AUX = *L;
	
	printf("\n Itens da Pilha (lista LIFO):");	
	while(P != AUX) {
		printf("\n %d", P->info);	
		P = P->prox;
	}
	printf("\n");
}
//Retirado dos slides da aula de 26/08
void imprime_LDEC(no **L) {
	no *P;
	P = *L;
	if (*L != NULL){
		printf("\n Itens da Lista:");
		do{
			if(P->info % 2 == 1){
				printf("\n %d", P->info);
			}
			P = P->prox;
		}while(P != *L);
	}
}

void PUSH(no **L, int x) {
	no *N, *ULT;
	N = (no *) malloc (sizeof(no));
	N->info = x;
	
	if(*L == NULL){
		N->prev = N;
		N->prox = N;
	}
	else{
		ULT = (*L)->prev;
		N->prev = ULT;
		(*L)->prev = N;
		N->prox = *L;
		ULT->prox = N;
	}
	*L = N;
}


void POP(no **L, int *n) {
	no *AUX, *ULT;

	if (*L != NULL) {
		AUX = *L;
		*n = (*L)->info;
		
		if (*L == (*L)->prev){
			*L = NULL;
		}
		else{
			*L = (*L)->prox;
			ULT = AUX->prev;
			(*L)->prev = ULT;
			ULT->prox = *L;
		}
		free(AUX);
	}
	else{
		*n = -1;
	}
}
