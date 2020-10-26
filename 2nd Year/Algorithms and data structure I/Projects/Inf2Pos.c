#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Pilha_LE.h" // aqui pode ser usado a biblioteca Pilha_LE para efetuar a tradução das notações

void In2Pos(char expr[]);
int Prioridade(char c, char t);

void In2Pos(char expr[]){
	//declaração de uma pilha com o nome: 'p' do tipo Pilha, parecido com a implementação de Pilha_LE onde é declarado um ponteiro do tipo no
	Pilha p;
	int i = 0;
	char c,t;
 
	//Função que cria e inicializa a Pilha, parecido com a função inicializa_Pilha()
	p = CriaPilha();
	//É atribuido o valor '(' a pilha p, parecido com a função PUSH()
	Empilha(p, '(');
 
	do{
    	//c é um char que recebe o primeiro caractere da string expr[]
		c = expr[i];
    	i++;
    	//Se o caractere for uma letra, ele é impresso
		if(c >= 'a' && c <= 'z'){
      		printf("%c", c);
    	}
    	//Se ele for '(' , ele é implementado na Pilha p
    	else if(c == '('){
      		Empilha(p, '(');
    	}
    	//Se ele for ')' ou '\0', (que indica que a string já foi toda percorrida) a pilha é desemplihada e o valor é atibuido ao caractere 't'
		//e é impresso os valores enquanto o item desemplihado (t) for diferente de '('
    	else if(c == ')' || c == '\0'){
      		do{
        		t = Desempilha(p);
        		if(t != '(')
          			printf("%c", t);
      		}while(t != '(');
    	}
    	//Se o caractere for um dos operadores básicos, é executada a função que verifica a prioridade de cada operador
    	else if(c == '+' || c == '-' || 
            	c == '*' || c == '/' ||
            	c == '^' ){
      		//enquanto a condição for verdadeira, sempre entre no loop, ou seja, enquanto não for verificado todos os operadores dentro da Pilha,
      		//volte ao loop
			while(1){
        		t = Desempilha(p);
        		//Se a função Prioridade() retornar 1, ou seja, verdadeiro, os caracteres 't' e 'c' são inseridos na Pilha e saimos do loop 
				if(Prioridade(c,t)){
		        	Empilha(p, t);
		        	Empilha(p, c);
		        	break;
        		}
        		//Senão é impresso o caractere do topo da Pilha
        		else{
         			printf("%c", t);
        		}
      		}
    	}
    //Entra no loop até todos os elementos da Pilha, serem percorridos
	}while(c != '\0');
	printf("\n");
	//Limpa a Pilha, função parecida com o free() onde limpamos a mémoria da Pilha
	LiberaPilha(p);
}

//Função que verifica a prioridade entre os operadores da Pilha
int Prioridade(char c, char t){
	int pc,pt;
	
	//A multilicação e a divisão possuem prioridades iguais
	if(c == '*' || c == '/')
    	pc = 2;
    //A adição e a subtração possuem prioridades menores em relação a multiplicação e a divisão
  	else if(c == '+' || c == '-')
    	pc = 1;
    //O parentese possui maior prioridade de acordo com a lógica da notação pós-fixa
  	else if(c == '(')
    	pc = 3;

	//Aqui verificamos a prioridade dos mesmos operadores do item no topo da pilha em relação ao item que está sendo verificado da expressão
  	if(t == '*' || t == '/')
    	pt = 2;
  	else if(t == '+' || t == '-')
    	pt = 1;
  	else if(t == '(')
    	pt = 0;
 
 	//Se a prioridade do caractere verificado for maior que a prioridade do caractere do topo, é retornado 1 ou verdadeiro, e os valores são adicionados
 	//a pilha, senão o valor é impresso
	return (pc > pt);
}

int main(){
	//É declarado uma string de tamanho 40
	char expr[40];
  
	//O usuário digita a expressão para ser traduzida
	printf("\n Digite a expressao a ser avaliada: ");
	scanf("%s", expr);
  
	//É executado a função que traduz a expressão
	In2Pos(expr);
  
	return 0;
}
