#include<stdio.h> 

main (void) 
{ 
int n,x,y; 
float e=1.0, fat=1; 

printf("Digite um numero que corresponde a N para obter o valor de E na equacao\nE = 1 + 1/1! + 1/2! + 1/3! + .... + 1/N!:"); 
scanf("%d", &n); 

for( x =1; x<= n ; x++) 
{ 
fat*=x; 
e = e + (1.0/ fat); 
} 

printf("O valor de 'E' e : %f", e); 

return 0; 
}
