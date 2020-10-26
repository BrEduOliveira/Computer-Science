#include <stdio.h>
#include <stdlib.h>

int main()
{
	float vetA[20], vetB[20];
	int i;
	
	for(i = 0; i < 20; i++){
		scanf("%f", &vetA[i]);
		for(i = 20; i > 0; i--){
			vetB[i-20] = vetA[i];
		}
	}
	for(i = 0; i < 20; i++){
		printf("%.2f\n", vetB[i]);
	}
    
    return 0;
}



