#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printArray(int vet[], int tam){
	int i;
	
	for(i=0; i<tam; i++){
		printf("%d ", vet[i]);
	}
}

 void quick_sort(int vetor[],int left,int right){
	int i;
	
	if (right<= left) return;
	else {
		int pivot = vetor[left]; 
		int inicio=left;
		int fim=right;
		do {
			while (left <=right && vetor[left] <= pivot) left++;
			while (vetor[right] > pivot) right--;
			if (left < right) { /* faz troca */
				int temp = vetor[left];
				vetor[left] = vetor[right];
				vetor[right] = temp;
				left++; right--;
			}
		} while (left <= right);
		/* troca pivot */
		vetor[inicio] = vetor[right];
		vetor[right] = pivot; pivot=right;
		/* ordena sub-vetores restantes */
		if(inicio<pivot) quick_sort(vetor,inicio,pivot-1);
		if(pivot<fim) quick_sort(vetor,pivot+1,fim);
	}
}

int main(){
	int vet[10], aux[10] = {0};
	int left, right, i;
	
	printf("Digite o primeiro valor do vetor: ");
	scanf("%d", &vet[0]);
	left = vet[0];
	printf("\n\n");
	
	for(i=1; i<9; i++){
		scanf("%d", &vet[i]);	
	}
	
	printf("Digite o ultimo valor do vetor: ");
	scanf("%d", &vet[9]);
	right = vet[9];
	printf("\n\n");
	
	aux[10] = quick_sort(vet,left,right);
	
	printArray(aux, 10);

	return 0;
}
