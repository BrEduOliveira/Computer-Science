int remove_LO(no **L, int x) {
	no *P, *ANT;
	
	if (*L != NULL){
		P = *L;
		while((P != NULL) && (P->info != x)){
			ANT = P;
			P = P->link;
		}
		
		if(P == NULL){
			return (0);
		}
		else{
			if (P == *L) {
				*L = (*L)->link;
				free(P);
			}
			else {
				ANT->link = P->link;
				free(P);
			}
			return (1);
		}
	}
	else{
		return (0);
	}
}
