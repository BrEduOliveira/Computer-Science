#include <stdio.h>

int main (void)
{
	int i;
	int vet[2];
	
	for(i = 0; i < 2; i++){
		scanf("%d", &vet[i]);
	}
	printf("-----Os valores digitados foram-----\n");
	for(i = 1; i <= 2; i++){
		printf("%d\n", vet[i]);
	}

}

