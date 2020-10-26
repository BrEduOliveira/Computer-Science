#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Doubly linked list.h"

int main(void)
{
   no *P, *F;
   char aux[10];
   int x, c;
   char choice[10];
 
   inicializa_Pilha(&P);
   inicializa_Fila(&F);
   do 
   {
      printf("\n------------------------------------\n");
      printf("PILHA - LISTA DUPLAMENTE ENCADEADA \n");
      printf("1 - PUSH - INSERE ITEM NA PILHA\n");
      printf("2 - POP - REMOVE ITEM DA PILHA\n");
      printf("3 - Imprime Itens da PILHA");
      printf("\n------------------------------------\n");
      printf("FILA - LISTA DUPLAMENTE ENCADEADA \n");
      printf("4 - INSERE ITEM NA FILA\n");
      printf("5 - REMOVE ITEM DA FILA\n");
      printf("6 - Imprime Itens da FILA");
      printf("\n------------------------------------\n");
      printf("7 - SAIR\n");
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
  		    imprime_Pilha(&P);
 			break;
         case 4: 
			printf(" \nEntre com o item a ser inserido na FILA: ");
			gets(aux);
			x = atoi(aux);
			insere_Final_Fila(&F,x);
            break;
         case 5: 
		    remove_Inicio_Fila(&F,&x);
		    if (x != -1)
				printf(" \nItem retirado da PILHA: %d", x);
			break;
         case 6: 
            printf("\n");
  		    imprime_Fila(&F);
 			break;
		 case 7: 
		    exit(0);
            break;
      };
   } while (c != 7);
}
