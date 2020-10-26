#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Pilha_LE.h" // aqui pode ser usado a biblioteca Pilha_LE para efetuar a tradu��o das nota��es

void In2Pos(char expr[]);
int Prioridade(char c, char t);

void In2Pos(char expr[]){
	//declara��o de uma pilha com o nome: 'p' do tipo Pilha, parecido com a implementa��o de Pilha_LE onde � declarado um ponteiro do tipo no
	Pilha p;
	int i = 0;
	char c,t;
 
	//Fun��o que cria e inicializa a Pilha, parecido com a fun��o inicializa_Pilha()
	p = CriaPilha();
	//� atribuido o valor '(' a pilha p, parecido com a fun��o PUSH()
	Empilha(p, '(');
 
	do{
    	//c � um char que recebe o primeiro caractere da string expr[]
		c = expr[i];
    	i++;
    	//Se o caractere for uma letra, ele � impresso
		if(c >= 'a' && c <= 'z'){
      		printf("%c", c);
    	}
    	//Se ele for '(' , ele � implementado na Pilha p
    	else if(c == '('){
      		Empilha(p, '(');
    	}
    	//Se ele for ')' ou '\0', (que indica que a string j� foi toda percorrida) a pilha � desemplihada e o valor � atibuido ao caractere 't'
		//e � impresso os valores enquanto o item desemplihado (t) for diferente de '('
    	else if(c == ')' || c == '\0'){
      		do{
        		t = Desempilha(p);
        		if(t != '(')
          			printf("%c", t);
      		}while(t != '(');
    	}
    	//Se o caractere for um dos operadores b�sicos, � executada a fun��o que verifica a prioridade de cada operador
    	else if(c == '+' || c == '-' || 
            	c == '*' || c == '/' ||
            	c == '^' ){
      		//enquanto a condi��o for verdadeira, sempre entre no loop, ou seja, enquanto n�o for verificado todos os operadores dentro da Pilha,
      		//volte ao loop
			while(1){
        		t = Desempilha(p);
        		//Se a fun��o Prioridade() retornar 1, ou seja, verdadeiro, os caracteres 't' e 'c' s�o inseridos na Pilha e saimos do loop 
				if(Prioridade(c,t)){
		        	Empilha(p, t);
		        	Empilha(p, c);
		        	break;
        		}
        		//Sen�o � impresso o caractere do topo da Pilha
        		else{
         			printf("%c", t);
        		}
      		}
    	}
    //Entra no loop at� todos os elementos da Pilha, serem percorridos
	}while(c != '\0');
	printf("\n");
	//Limpa a Pilha, fun��o parecida com o free() onde limpamos a m�moria da Pilha
	LiberaPilha(p);
}

//Fun��o que verifica a prioridade entre os operadores da Pilha
int Prioridade(char c, char t){
	int pc,pt;
	
	//A multilica��o e a divis�o possuem prioridades iguais
	if(c == '*' || c == '/')
    	pc = 2;
    //A adi��o e a subtra��o possuem prioridades menores em rela��o a multiplica��o e a divis�o
  	else if(c == '+' || c == '-')
    	pc = 1;
    //O parentese possui maior prioridade de acordo com a l�gica da nota��o p�s-fixa
  	else if(c == '(')
    	pc = 3;

	//Aqui verificamos a prioridade dos mesmos operadores do item no topo da pilha em rela��o ao item que est� sendo verificado da express�o
  	if(t == '*' || t == '/')
    	pt = 2;
  	else if(t == '+' || t == '-')
    	pt = 1;
  	else if(t == '(')
    	pt = 0;
 
 	//Se a prioridade do caractere verificado for maior que a prioridade do caractere do topo, � retornado 1 ou verdadeiro, e os valores s�o adicionados
 	//a pilha, sen�o o valor � impresso
	return (pc > pt);
}

int main(){
	//� declarado uma string de tamanho 40
	char expr[40];
  
	//O usu�rio digita a express�o para ser traduzida
	printf("\n Digite a expressao a ser avaliada: ");
	scanf("%s", expr);
  
	//� executado a fun��o que traduz a express�o
	In2Pos(expr);
  
	return 0;
}
