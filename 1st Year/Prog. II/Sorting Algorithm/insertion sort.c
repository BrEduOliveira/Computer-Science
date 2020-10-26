#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 9

void leitura(int v[N]){
	int i;
	
	for(i=0;i<N;i++)
		scanf("%d", &v[i]);
}

void insertion(int v[N]){
	int i, p=0, j, temp;

	for(i=1;i<N;i++){
		temp=v[i];
		j=i-1;
		while(j>=0 && v[j]>temp){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=temp;
		p++;
	}
}

void imprime(int v[N]){
	int i;
	
	for(i=0;i<N;i++)
		printf("%d ", v[i]);
}

int main(void){
	int v[N]= {82,50,71,63,85,43,39,97,14};

	insertion(v);
	imprime(v);
	
	return 0;
}
