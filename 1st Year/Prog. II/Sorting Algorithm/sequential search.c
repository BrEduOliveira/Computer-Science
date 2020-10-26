#include<stdio.h>
#include<stdlib.h>
#define N 5

void leitura(int v[N]){
	int i;
	
	for(i=0;i<N;i++)
		scanf("%d", &v[i]);
}

int busca(int v[N]){
	int i, num=0;
	
	scanf("%d", &num);
	for(i=0;i<N;i++){
		if(v[i]==num){
			return 1;
		}
	}
	return 0;	
	
}

int main(){
	int v[N];
	
	leitura(v);
	printf("\n");
	printf("%d", busca(v));
	
	return 0;
}



