#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void intercalar(int v[], int vetAux[], int ini1, int ini2, int fim2){
	int in1 = ini1, in2 = ini2, fim1 = in2-1, au = 0, i;
 
 	while(in1 <= fim1 && in2 <= fim2){
  		if(v[in1] < v[in2]){
   			vetAux[au++] = v[in1++];
  		}else{
   			vetAux[au++] = v[in2++];
 		}
	}
 	while(in1 <= fim1){
  		vetAux[au++] = v[in1++];
 	}
 	while(in2 <= fim2){
  		vetAux[au++] = v[in2++];
 	}
 	for(i=0;i<au;i++){
  		v[i+ini1] = vetAux[i];
 	}
}

void mergeSort(int v[], int vetAux[], int esq, int dir){
	int meio = 0;
	
	if(esq < dir){
  		meio = (esq+dir)/2;
  		mergeSort(v, vetAux, esq, meio);
  		mergeSort(v, vetAux, meio+1, dir);
  		intercalar(v, vetAux, esq, meio+1, dir);
 	}	
}

void imprime(int v[]){
	int i;
	
	for(i=0;i<7;i++){
		printf("%d", v[i]);
		printf("\n");
	}
}

int main(){
	int v[7] = {9,6,7,5,4,8,3}, vetAux[7] = {0};
	
	mergeSort(v,vetAux,0,6);
	imprime(v);
	
	return 0;
}
