#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define NUM 6
#define VET 12
int main(){
	int a[NUM], b[NUM], c[VET], i = 0, j;
	srand(time(NULL));
	while(i < NUM){
		a[i] = rand()%100;
		if(a[i]%2 == 0){
			i++;
		}
	}
	i = 0;
	while(i < NUM){
		b[i] = rand()%100;		
		if(b[i]%2 != 0){
			i++;		
		}
	}
	
	for(j = 0; j < NUM; j++){
		c[j] = a[i];
	}
	
	i = 0;
	for(j = NUM; j < VET; j++){
		c[j] = b[i];
		i++;
	}
	for(j = 0; j < VET; j++){
		printf("%d\n", c[j]);
	}
	
	return 0;
}


