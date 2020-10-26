#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#define TAM 5

void ler(int v[TAM]){
	int i;
	
	for(i=0;i<TAM;i++){
		scanf("%d", &v[i]);
	}
}

int buscabin(int v[], int x){
	int inicio=0, fim = TAM - 1, meio;
	
	while(inicio<=fim){
		meio = ((inicio+fim) / 2);
		if(x==v[meio]){
			return 1;
		}else if(x<v[meio]){
			fim=meio-1;
		}else{
			inicio=meio+1;	
		}
	}
	return 0;
}

int main(void){
	int v[TAM], x;
	
	// antes de fazer a busca linear diz apenas se achou ou n�o
	//antes de fazer a busca bin�ria, pergunta qual m�todo de ordena��o deseja
	setlocale(LC_ALL, "Portuguese");
	ler(v);
	printf("\nDigite o n�mero que deseja procurar: ");
	scanf("%d", &x);
	if(buscabin(v,x)){
		printf("\nAchou");	
	}else{
		printf("\nN�o achou");
	}
	
	
	return 0;
}
