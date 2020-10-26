#include <stdio.h> 
#define TAM 15

int main() { 
	int vetA[TAM], vetB[TAM], i, fat;

	for(i = 0; i < TAM; i++){
		scanf("%d", &vetA[i]);
		for(fat = 1; vetA[i] > 1; vetA[i]--){
			fat = fat * vetA[i];
			vetB[i] = fat;
		}
	}
	for(i = 0; i < TAM; i++){
		printf("\n%d", vetB[i]);
	}

   return 0; 
} 

