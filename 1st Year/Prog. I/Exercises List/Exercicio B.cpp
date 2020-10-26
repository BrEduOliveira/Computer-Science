#include <stdio.h>
#define TAM 8

int main(void)
{
	int vetA[TAM], vetB[TAM], vetC[TAM];
	int i = 0;

	for(i = 0; i < TAM; i++){
		scanf("%d", &vetA[i]);
		vetB[i] = vetA[i] * 3;
	}
	printf("\n");
	for(i = 0; i < TAM; i++){
		printf("%d\n", vetB[i]);
	}

}
