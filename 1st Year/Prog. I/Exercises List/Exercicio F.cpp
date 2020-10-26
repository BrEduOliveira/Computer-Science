#include <stdio.h> 
#include <stdlib.h>
#define TAM 15

int main() { 
	int vetA[TAM], vetB[TAM], vetC[30], i;

	for(i = 0; i < TAM; i++){
		scanf("%d", &vetA[i]);
	}
	
	for(i = 0; i < TAM; i++){
		scanf("%d", &vetB[i]);
	}
	
	for(i = 0; i < TAM; i++){
		vetC[i] = vetA[i];
	}
	
	for(i = 15; i < 30; i++){
		vetC[i] = vetB[i-15];
	}
	
	printf("\n");
	for(i = 0; i < 30; i++){
		printf("%d\n", vetC[i]);
	}
   
   return 0; 
} 

