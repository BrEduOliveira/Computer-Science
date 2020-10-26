#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int cod, tipo;
 	float kwCon=0, custoTotal=0, totTipo1=0, totCon1=0, totTipo2=0, totCon2=0, totTipo3=0;   
 
	printf("Informe o codigo: ");
	scanf("%d", &cod);   
	while(cod != 0){
		printf("Informe quamtos kw consumidos: ");
		scanf("%d", &kwCon); 
		printf("Informe qual e o tipo: ");
		scanf("%d", &tipo); 	
    	if(tipo == 1){
    		custoTotal = kwCon * 0.3;
			totTipo1 += custoTotal;
			totCon1++;	
		}else
    		if(tipo == 2){
    			custoTotal = kwCon * 0.5;
				totTipo2 += custoTotal;
				totCon2++;
		}else{
			custoTotal = kwCon * 0.7;
			totTipo3 += custoTotal;	
		}
		printf("O valor consumido foi de %f", custoTotal);
		printf("\nO valor total consumido pelo grupo 1 foi de %f", totTipo1);
		printf("\nO valor total consumido pelo grupo 2 foi de %f", totTipo2);
		printf("\nO valor total consumido pelo grupo 3 foi de %f", totTipo3);
		printf("\nO valor medio de consumo do grupo 1 foi de %f", totTipo1 / totCon1);
		printf("\nO valor medio de consumo do grupo 2 foi de %f", totTipo2 / totCon2);
	}
	
	return 0;
}
