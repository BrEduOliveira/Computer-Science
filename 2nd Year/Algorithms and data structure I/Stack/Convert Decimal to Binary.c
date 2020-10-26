#include <stdio.h>
#include <stdlib.h>
#include "Pilha_LE.h"

int main(void){
	no *L;
	int aux, x;
	int num, opcao;
	do{
		inicializa_Pilha(&L);
		system("cls");
		printf("\nCONVERTE DECIMAL EM BINARIO\n\n");
		printf("Entre com o numero decimal que voce deseja converter em binario:\n");
		scanf("%d", &num);
		aux=num;
		system("cls");
		printf("CONVERTE DECIMAL EM BINARIO USANDO PILHA\n\n");
		printf("NUMERO DECIMAL: \t%d\n", num);
		int resto;
		if(num == 1){
			printf("\nNUMERO BINARIO: \t%d", num);
		}else if (num > 1){
			printf("\nNUMERO BINARIO: \t");
			do{
				resto = num % 2;
				printf("\n DIVIDE %d POR 2 - INSERE %d na PILHA", num, resto);
				PUSH(&L, resto);				
				num = num/2;
			}while(num >= 1);
			printf("\n");
			imprime_Pilha(&L);
			printf("\nNUMERO DECIMAL %d EQUIVALE AO SEGUINTE NUMERO BINARIO ", aux);
			while(L != NULL){
				POP(&L, &x);
				printf("%d", x);
			}		
		}else
			printf("\nNao e possivel transformar este valor!\n");
		printf("\n\nVOCE DESEJA CONTINUAR:\n1. Sim.\t\t\t2.Nao.\n");
		scanf("%d", &opcao);
	}while(opcao == 1);

	return 0;
}
 

