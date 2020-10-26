#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a = 90000, b = 50000, anos = 0;
    
    while(a > b){
		a = a + (a * 0.009);
    	b = b + (b * 0.015);
		anos++;
	}
	printf("%d", anos);
	
	return 0;
}
