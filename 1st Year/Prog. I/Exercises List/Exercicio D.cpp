#include <stdio.h>
#define TAM 15

int main(void){
	int i, vetA[TAM], vetB[TAM];
	
	i = 0;
	while(i < TAM){
		scanf("%d", &vetA[i]);
		vetB[i] = vetA[i] * vetA[i];
		i++;
	}
	printf("--VETOR A---\n");
	i = 0;
	while(i < TAM){
		printf("%d\n", vetA[i]);
		i++;
	}
	printf("---VETOR B--\n");
	i = 0;
	while(i < TAM){
		printf("%d\n", vetB[i]);
		i++;
	}
}
