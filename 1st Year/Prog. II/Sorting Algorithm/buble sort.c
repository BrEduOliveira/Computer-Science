#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 9

void leitura(int v[N]){
	int i;
	
	for(i=0;i<N;i++)
		scanf("%d", &v[i]);
}

void bubble(int v[N]){
	int i, j, aux;
	
	for(i=0;i<N-1;i++){
		for(j=0;j<N-1-i;j++){
			if(v[j]<v[j+1]){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
}

void imprime(int v[N]){
	int i;
	
	for(i=0;i<N;i++)
		printf("%d ", v[i]);
}

int main(void){
	int v[N] = {82,50,71,63,85,43,39,97,14};
	
	bubble(v);
	printf("\n");
	imprime(v);
	
	return 0;
}
