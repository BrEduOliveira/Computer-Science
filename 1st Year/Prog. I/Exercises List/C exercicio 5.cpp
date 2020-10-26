#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int n = 0, quan, num, maior, menor;
	
	scanf("%d", quan);
	scanf("%d", &num);
	while(n < quan){
		if(n == 0 ){
			maior = menor;
			menor = maior;
		}
		if(maior < num){
			maior = num;
		}
		if(menor > num){
			menor = num;
		}
		n++;
		printf("Maior %d e o menor %d", maior, menor);
	}
	
	return 0;
}
