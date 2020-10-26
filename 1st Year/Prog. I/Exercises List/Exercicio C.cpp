#include <stdio.h>
#define TAM 20

int main(void){
	float vetA[TAM], vetB[TAM], vetC[TAM]; 
	int i = 0;

	for(i = 0; i < TAM; i++){
		scanf("%f", &vetA[i]);
		scanf("%f", &vetB[i]);
		vetC[i] = vetA[i] - vetB[i];
 	}
	
	printf("\n");
	
	for(i = 0; i < TAM; i++){
		printf("%.2f\n", vetC[i]);
	}
	
}
