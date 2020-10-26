/*
 * LISTA DUPLAMENTE ENCADEADA
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

void imprime_Pilha(no **L) {
	no *P;
	P = *L;
	
	printf("\n Itens da Pilha (lista LIFO):");	
	while(P != NULL) {
		printf("\n %d", P->info);	
		P = P->prox;
	}
	printf("\n");
}

void PUSH(no **L, int x) {
	no *N;

	N = (no *) malloc (sizeof(no));
	N->info = x;

	N->prev = NULL;
	N->prox = *L;
	if (*L != NULL)
		(*L)->prev = N;
	*L = N;
}


void POP(no **L, int *n) {
	no *AUX;

	if (*L != NULL) {
		*n = (*L)->info;
		AUX = *L;
		*L = (*L)->prox;
		if (*L != NULL)
			(*L)->prev = NULL;
		free(AUX);
	}
	else{
		*n = -1;
	}
}

/***** FILA *****/
void inicializa_Fila(no **L) {
	*L = NULL;
}

void imprime_Fila(no **L) {
	no *P;
	P = *L;
	
	printf("\n Itens da Fila (lista FIFO):");	
	while(P != NULL) {
		printf("\n %d", P->info);	
		P = P->prox;
	}
	printf("\n");
}

void insere_Final_Fila(no **L, int x) {
	no *N, *P;

	N = (no *) malloc (sizeof(no));
	N->info = x;

	N->prev = NULL;
	N->prox = *L;
	if (*L == NULL){
		N->prev = NULL;
		N->prox = NULL;
		*L = N;
	}
	else{
		P = *L;
		while (P->prox!=NULL){
			P = P->prox;
		}
		P->prox = N;
		N->prev = P;
		N->prox = NULL;
	}
}

void remove_Inicio_Fila(no **L, int *n) {
	no *AUX;

	if (*L != NULL) {
		*n = (*L)->info;
		AUX = *L;
		*L = (*L)->prox;
		if (*L != NULL)
			(*L)->prev = NULL;
		free(AUX);
	}
	else{
		*n = -1;
	}
}

 

