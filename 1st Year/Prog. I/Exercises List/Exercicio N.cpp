#include <stdio.h>
#define NUM 20

int main(void){
	float vetorA[NUM], maior, menor, media;
	int soma;
	int i = 0;
	
	for(i = 0; i < NUM; i++){
		scanf("%d", &vetorA[i]);
	}
	maior = vetorA[0];
	for(i = 1; i < NUM; i++){
		if(vetorA[i] > maior){
			maior = vetorA[i];
		}
	}
	
	menor = vetorA[0];
	for(i = 1; i < NUM; i++){
		if(vetorA[i] < menor){
			menor = vetorA[i];
		}
	}
	
	soma = 0;
	for(i = 1; i < NUM; i++){
		soma = soma + vetorA[i];
	}
	media = soma / NUM;
	
	printf("%.2f\n%.2f\n%.2f\n", maior, menor, media);

}
