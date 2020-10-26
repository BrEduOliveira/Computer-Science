#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include "Pilha_LE.h" 		

void avalia(char exp[], no **L); 		        
int compara(char c, char d);    

void main()
{
	no *L; 		      
	char exp[40];			

	inicializa_Pilha(&L); 	      

	printf("\n Digite a expressao a ser avaliada: ");
	scanf("%s", exp);

	// Chama a fun??o avalia, para avaliar se express?o est? CORRETA
	avalia(exp, &L);
}


int compara(char c, char d)
{
	if ((d ==  ')' ) && (c != '(' ))
		return(0);
	if ((d ==  ']' ) && (c != '[' ))
		return(0);
	if ((d ==  '}' ) && (c != '{' ))
		return(0);
	return(1);
}


void avalia(char exp[], no **L) {			            
	int n, i;
	char d;
	int caractere;
	n = strlen(exp); 	     

	for( i=0 ;  i < n ;  i++ ) {
		d = exp[i];
		// se d for um iniciador de escopo, d ? colocado na pilha
		if (d ==  '(' || d ==  '[' || d ==  '{' ) {
				PUSH(L,d);
		}	// fim if	
		// se d for um finalizador de escopo 
		else {
			if (d == ')' || d ==  ']' || d ==  '}' ) {
				 // se pilha estiver vazia
				 if (*L == NULL) {
					    // n?o h? uma abertura de escopo.
						printf("\n NAO existe uma abertura de escopo! Expressao INCORRETA \n");
						return;
				 } // fim if
				 POP(L, &caractere);
				 if (!compara(caractere,d)) {
						// tipos diferentes de delimitadores.
						printf("\n Uso de tipos diferentes de delimitadores! Expressao INCORRETA \n");
						return;
				 } // fi  if
			} // fim if
		}  // fim else
	} // fim for

	if ( *L != NULL) {
		// Algum escopo ficou aberto 
		printf("\n Algum escopo ficou aberto! Expressao INCORRETA \n");
		 return;
	}
	else {
		 printf("\n Expressao CORRETA \n");
		 return;
	}
}
