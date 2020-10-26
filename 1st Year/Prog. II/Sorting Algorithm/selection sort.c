#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 9

void carrega(int v[N]){
	int i=0;

	for(i=0;i<N;i++){
		scanf("%d", &v[i]);
	}
}

void selection(int v[N]){
	int i=0, j=0, min=0, aux=0;

	for(i=0;i<N-1;i++){
		min=i;
		for(j=i+1;j<N;j++){
			if(v[j]<v[min]){
				min=j;
			}
			
		}
		if(i!=min){
			aux=v[i];
			v[i]=v[min];
			v[min]=aux;
		}
	}

}

void imprime(int v[N]){
	int i=0;

	for(i=0;i<N;i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(){
	int v[N] = {82,50,71,63,85,43,39,97,14};

	selection(v);
	imprime(v);

	return 0;
}
