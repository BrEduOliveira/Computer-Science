void insere_LO_Decrescente(no **L, int x) {
	no *N, *P, *ANT;
	
	N = (no *) malloc (sizeof(no));
	N->info = x;
	
	if (*L == NULL){
		*L = N;
		N->link = NULL;
	}
	else {
		P = *L;
		
		while((P != NULL) && (x <= P->info)) {
			ANT = P;
			P = P->link;
		}
		if (P == *L) {
			N->link = *L;
			*L = N;
		}
		else {
			if (P == NULL) {
				ANT->link = N;
				N->link = NULL;
			}
			else {
				ANT->link = N;
				N->link = P;
			}
		}
	}
}
