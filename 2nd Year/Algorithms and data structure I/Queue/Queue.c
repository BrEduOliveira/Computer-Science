/*
 ***** FILA_LE.h
 ***** FILA IMPLEMENTADA COMO LISTA ENCADEADA
*/

typedef struct NoTag {
	int info;
	struct NoTag *link;
} no;

// inicializa Fila
void inicializa_Fila(no **L) {
	*L = NULL;
}

void exibe_Fila(no **L) {
	no *P;
	P = *L;	// P recebe o endereco do primeiro no da lista
	
	printf("\n Imprime itens da FILA \n");	
	while(P != NULL) { // enquanto P apontar para um n� da Fila
		printf("%d ", P->info);	// exibe o valor do n�
		P = P->link;	// P recebe o endere?o do pr?ximo n� da Fila
	}
}

// fun��o que insere item no final da Fila
void insere_Fila(no **L, int x) {
	no *P, *N;

	// aloca mem�ria para armazenar o novo n� e atribui o endere�o alocado para N
	N = (no *) malloc (sizeof(no)); 
	N->info = x; // Insere o valor no novo n?
	N->link = NULL; // como ser� inserido no final da Fila, link do novo n� recebe NULL
	 
	// se a Fila estiver vazia, o novo n� ser� o primeiro da Fila
	if (*L == NULL){ // verifica se Fila vazia
		*L = N;
	}
	else { // se a Fila n�o estiver vazia, � preciso encontrar o final da Fila para inserir o novo item
		P = *L;	// P recebe o endereco do primeiro no da lista
	
		while(P->link != NULL) {
			P = P->link;
		}
		// o while � interrompido quando P apontar para o �ltimo n� da Fila
		P->link = N; 	// o link do n� apontado por P recebe o endere�o do novo n�
	} 
}

// fun��o que remove o item do in�cio da Fila
void remove_Fila(no **L, int *n) {
	no *AUX;

	// verifica se Fila n�o est� vazia
	if (*L != NULL) {
		// *n guarda o valor do n� que ser� exclu�do
		*n = (*L)->info;
		// um ponteiro auxiliar recebe o endere�o do primeiro n� da Fila
		AUX = *L;
		// *l aponta para o pr�ximo n� da Fila
		*L = (*L)->link;
		// Libera a ?rea de mem�ria do n� exclu?do da Fila
		free(AUX);
	}
}

// fun��o que verifica se Fila Vazia
int verificaSeVazia_Fila(no **L) {
	if (*L == NULL)
		return 1;
	else
		return 0;
}
