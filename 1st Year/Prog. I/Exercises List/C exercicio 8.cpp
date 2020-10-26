#include<stdio.h>
#include<stdlib.h>

int main(){
	float i,p,med1,med2,med3,med4,soma1,soma2,soma3,soma4 = 0,y1,y2,y3,y4;
	int x;
	soma1=0;
	soma2=0;
	soma3=0;
	y1=0;
	y2=0;
	y3=0;
	y3=0;
	y4=0;
	
	for(x=1;x<=20;x++){
        printf("\nDigite a idade da %d pessoa: ",x);
        scanf("%f",&i);
        printf("Digite o peso da %d pessoa: ",x);
        scanf("%f",&p);
        printf("\n_____________________________________________\n");
        if(i>=1&&i<=10){
            y1=y1+1;
            soma1=soma1+p;
            med1=soma1/y1;
        }
        if(i>=11&&i<=20){
            y2=y2+1;
            soma2=soma2+p;
            med2=soma2/y2;
        }
       - if(i>=21&&i<=30){
            y3=y3+1;
            soma3=soma3+p;
            med3=soma3/y3;
        }
        if(i>30){
            y4=y4+1;
            soma4=soma4+p;
            med4=soma4/y4;
        }
	}
	printf("\nA media dos pesos das pessoas entre 1 e 10 anos   = %.2f\n",med1);
	printf("\nA media dos pesos das pessoas entre 11 e 20 anos  = %.2f\n",med2);	
	printf("\nA media dos pesos das pessoas entre 21 e 30 anos  = %.2f\n",med3);
	printf("\nA media dos pesos das pessoas maiores que 30 anos = %.2f\n",med4);

	return 0;
}
