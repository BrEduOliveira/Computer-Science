#include <stdlib.h>
#include <stdio.h>

int main(){
    
	char nome[20], sexo;
    int i = 0, idade;
    
	while(i < 20){
		printf("Insira o seu nome: ");
    	fflush(stdin);
		gets(nome);
		printf("Insira sua idade: ");
    	scanf("%d", &idade);
		printf("Insira o seu sexo (M para masculino e F para feminino): ");
    	fflush(stdin);
		scanf("%c", &sexo);
		if((sexo == 'M') && (idade > 21)){
       		printf("%s\n\n", nome);
    	}else{
        	printf("Invalido\n\n");
		}
		i++;
	}
	

    return 0;
}
