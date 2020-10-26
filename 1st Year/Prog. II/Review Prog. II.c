/*
  Este c�digo � um resumo de alguns conceitos b�sicos em C
  Portanto ele n�o foi criado para ser compilado e executado
*/

//Fun��o void
void soma (void) {
 int n1, n2, soma;
 printf("Insira os numeros: ");
 scanf("%d%d",&n1, &n2);
 soma = n1 + n2;
 printf("Soma de %d + %d = %d", n1, n2, soma);
}
//Ex de fun��o com retorno
int Fatorial(int n);

int Fatorial(int n){
	int i, fat = 1;
	for (i = 1; i <= n; i++)
		fat = fat * i;
	return fat;
}
int main(void) {
	int num;
	scanf("%d",&num);
	printf("Fatorial de %d = %d ", num, Fatorial(num));
	return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------
//Recurs�o
int Fatorial(int n){
	
	if(n<=1)
		return 1;
	else
		return n * Fatorial(n-1);
}
int main(void) {
	int num;
	
	scanf("%d",&num);
	printf("Fatorial de %d = %d ", num, Fatorial(num));
	return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------
//Struct usual
struct Conta {
    int num_conta;
    char tipo_conta;
    char nome[80]; 
    float saldo; 
}clienteNovo, clienteAntigo;

struct Conta clienteNovo={10,'A',"Bruno",500.00};

//Struct usando ponteiro (valor por refer�ncia):
struct registro {
   char *nome;
   int num_conta;
   char tipo_conta;
   float saldo;
};
void ajuste(struct registro *pt);
void imprime(struct registro *pt);

int main(void) {
     struct registro cliente = { "Silva", 3333, 'C', 33.33};
     imprime(cliente);
     ajuste(&cliente);
     imprime(cliente);
     return 0;
}

void imprime(struct registro *pt){
     printf("\n\nNome: %s\n", pt.nome);
     printf("Conta:  %d\n", pt.num_conta);
     printf("Tipo conta: %c\n", pt.tipo_conta);
     printf("Saldo: %.2f\n\n", pt.saldo);
 }
void ajuste(struct registro *pt){
        pt->nome = "Jonas";
        pt->num_conta = 999;
        pt->tipo_conta = 'R';
        pt->saldo = 99.99;
}

//Struct usando typedef
typedef struct{
    int num_conta;
    char tipo_conta;
    char nome[80]; 
    float saldo; 
}Cliente;

Cliente novo_cliente={10,'A',"Bruno",500.00};
--------------------------------------------------------------------------------------------------------------
/*C oferece 4 classes de armazenamento, indicadas pelos
especificadores de classes de armazenamento:
	
--------------Armazenamento autom�tico:----------------------------------------------------

- auto: As vari�veis locais possuem dura��o de armazenamento autom�tico como padr�o.
		palavra-chave auto raramente � usada.

- register: pode ser colocado antes de uma declara��o de vari�vel autom�tica para
			sugerir que o compilador mantenha a vari�vel em um dos
			registradores de hardware de alta velocidade do computador.
	
-------------Armazenamento estatico:----------------------------------------------------
			
- extern: Vari�veis globais e nomes de fun��es s�o da classe de
		armazenamento extern, como padr�o. Vari�veis globais s�o
		criadas a partir da coloca��o das declara��es de vari�vel fora de
		qualquer defini��o de fun��o, e elas reter�o seu valor durante
		toda a execu��o do programa.
		
- static: resulta em dura��o de armazenamento est�tico.
		 esse tipo de vari�vel tem uma loca��o de armazenamento
		 permanente
         seu valor � retido durante toda a execu��o do programa.*/
Exemplo:
void fun(int y);
	int main(void){
 	fun(10);
 	fun(20);
 	fun(30);
 	return 0;}
void fun(int y){
	static int x;
 	x += y;
 	printf("x = %d\n",x);
	x++;
}

-----------------------------------------------------------------------------------------------------------------
//Ponteiro: Um ponteiro � uma vari�vel que armazena um endere�o de mem�ria de um objeto.
//Ex 1:
int main (void) {
	int *px, *py;
	int a[5] = {7, 9, 1, 10, 15};
 	px = &a[0];
 	py = &a[4];
	printf("\npx = %d py = %d", px, py);
	printf("\npy � px = %d", py � px);
 	printf("\n%d %d ", *px,*py);
 	return 0;
}
/* A diferen�a py � px � = 4 (linha 8), pois a[4] � o
quinto elemento do vetor a. Assim, a[4] � armazenado em
um endere�o 16 bytes al�m do endere�o de a[0], pois uma
vari�vel do tipo int ocupa 4 bytes de mem�ria. Desse
modo a diferen�a entre py e px � igual 4, pois 16/4=4.
*/

//Ex 2 usando sizeof (Retorna o n�mero de bytes de um tipo de variavel):
#include <stdio.h>
int main(void) {
 char letra[5] = {'a','e','i','o','u'};
 int contador, nr[5] = {30,12,67,13,41};
 char *ptr_letra;
 int *ptr_nr;
 ptr_letra = letra;
 ptr_nr = nr;
 printf("Visualizando como funciona a aritm�tica de ponteiros\n");
 printf("\nmatriz letra = a, e, i, o, u\n");
 printf("matriz nr = 30,12,67,13,41\n");
 printf("\nVerificando o tamanho dos tipos de dados\n");
 printf("tamanho do tipo de dado char = %d\n",sizeof(char));
 printf("tamanho do tipo de dado int = %d\n",sizeof(int));
 printf("\nPonteiro para letra aponta para %c no endereco %x\n",*ptr_letra,ptr_letra);
 printf("Ponteiro para nr aponta para %d no endereco %x\n",*ptr_nr,ptr_nr);
 printf("\nIncrementando os ponteiros\n"); printf("ptr_letra + 3, ptr_nr + 2\n");
 ptr_letra += 3; ptr_nr += 2;
 printf("\nPonteiro para letra agora aponta para %c no endereco %x\n",*ptr_letra,ptr_letra);
 printf("Ponteiro para nr agora aponta para %d no endereco %x\n",*ptr_nr,ptr_nr);
 return(0);
}
---------------------------------------------------------------------------------------------------------------------------
//Metodos de ordena��o: facilita uma opera��o em um conjunto grande de dados
//Bubble Sort:
void bubble(int v[], int n){
	int i, j, aux;
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(v[j]>v[j+1]){
				aux=v[j];
				v[j]=v=[j+1];
				v[j+1]=aux;
			}
		}
	}
}
//Selection
void selection(int v[], int n){
	int i, j, aux;
	
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(v[j]<v[min]){
				min=j;
			}
		}
		if(i!=min){
				aux=v[i];
				v[i]=v[min];
				v[min]=aux;
		}
	}
}
//Insertion
void insertion(int v[N]){
	int i, j, temp;

	for(i=1;i<N;i++){
		temp=v[i];
		j=i-1;
		while(j>=0 && v[j]>temp){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=temp;
	}
}
------------------------------------------------------------
//Busca Sequencial
int busca(int v[N], int num){
	int i;
	
	for(i=0;i<N;i++){
		if(v[i]==num){
			return 1;
		}
	}
	return 0;
}
------------------------------------------------------------
//Busca Bin�ria
//OBS: O vetor precisa estar ordenado antes de fazer a busca bin�ria
int buscabin(int v[], int x){
	int inicio=0, fim = TAM - 1, meio;
	
	while(inicio<=fim){
		meio = ((inicio+fim) / 2);
		if(x==v[meio]){
			return 1;
		}else if(x<v[meio]){
			fim=meio-1;
		}else{
			inicio=meio+1;	
		}
	}
	return 0;
}
-----------------------------------------------------------------
//Aloca��o Dinamica: habilidade de alocar mem�ria durante a execu��o do programa.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, n;
	float max, *p;
	
	printf("Quantidade de numeros:");
	scanf("%d", &n);
	p = malloc (n * sizeof(float));
	if (!p) {
		printf("Memoria insuficiente");
		exit(1);
	}
	printf("Digite numeros: ");
	for (i = 0;i < n;i++)
		scanf("%f", (p+i));
	max = *p;
	for (i = 1;i < n;i++)
		if(*(p+i) > max)
			max = *(p+i);
	printf("Maior = %.2f", max);
	free(p);
	p = NULL;
	return 0;
}
