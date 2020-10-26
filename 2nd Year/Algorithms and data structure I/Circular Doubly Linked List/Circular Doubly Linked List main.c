#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Lista_Duplamente_Encadeada_Circular.h"

int main(void){
   no *P;
   char aux[10];
   int x, c;
   char choice[10];
 
   inicializa_Pilha(&P);
   
	do{
	    printf("\n------------------------------------\n");
	    printf("PILHA - LISTA DUPLAMENTE ENCADEADA CIRCULAR\n");
	    printf("1 - PUSH - INSERE ITEM NA PILHA\n");
	    printf("2 - POP - REMOVE ITEM DA PILHA\n");
	    printf("3 - Imprime Itens da PILHA\n");
	    printf("4 - Primeiro e ultimo\n");
	    printf("5 - SAIR\n");
	    printf("\n Escolha: ");
	
	    gets(choice);     
	    c = atoi(choice);
	
	    switch (c) {
	    	case 1: 
				printf(" \nEntre com o item a ser inserido na PILHA: ");
				gets(aux);
				x = atoi(aux);
				PUSH(&P,x);
	            break;
	        case 2: 
			    POP(&P,&x);
			    if (x != -1)
					printf(" \nItem retirado da PILHA: %d", x);
				break;
			case 3: 
	            printf("\n");
	  		   // imprime_Pilha(&P);
	  		    imprime_LDEC(&P);
	 			break;
			case 4:  
			    exit(0);
	            break;
	    }
	} while (c != 4);
}
