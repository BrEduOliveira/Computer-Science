#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<conio.h>
#include<locale.h>

void inicio(){
	int begin;
	
	printf("\n\n");
	printf("\t #######  ########  ########  ######## ##    ##    ###     ######     ###     #######   \n");
	printf("\t##     ## ##     ## ##     ## ##       ###   ##   ## ##   ##    ##   ## ##   ##     ## \n");
	printf("\t##     ## ##     ## ##     ## ##       ####  ##  ##   ##  ##        ##   ##  ##     ##  \n");
	printf("\t##     ## ########  ##     ## ######   ## ## ## ##     ## ##       ##     ## ##     ## \n");
	printf("\t##     ## ##   ##   ##     ## ##       ##  #### ######### ##       ######### ##     ##  \n");
	printf("\t##     ## ##    ##  ##     ## ##       ##   ### ##     ## ##    ## ##     ## ##     ##  \n");
	printf("\t #######  ##     ## ########  ######## ##    ## ##     ##  ######  ##     ##  #######  \n\n");
	gotoxy(40,12);
	printf("Inicio (Digite 1):");
	gotoxy(40,14);
	printf("Sobre (Digite 2):\n");
	gotoxy(50,15);
	scanf("%d", &begin);
	while(begin<1 || begin>2){
		system("cls");
		printf("Opção inválida!");
		printf("\n\n");
		printf("\t #######  ########  ########  ######## ##    ##    ###     ######     ###     #######   \n");
		printf("\t##     ## ##     ## ##     ## ##       ###   ##   ## ##   ##    ##   ## ##   ##     ## \n");
		printf("\t##     ## ##     ## ##     ## ##       ####  ##  ##   ##  ##        ##   ##  ##     ##  \n");
		printf("\t##     ## ########  ##     ## ######   ## ## ## ##     ## ##       ##     ## ##     ## \n");
		printf("\t##     ## ##   ##   ##     ## ##       ##  #### ######### ##       ######### ##     ##  \n");
		printf("\t##     ## ##    ##  ##     ## ##       ##   ### ##     ## ##    ## ##     ## ##     ##  \n");
		printf("\t #######  ##     ## ########  ######## ##    ## ##     ##  ######  ##     ##  #######  \n\n");
		gotoxy(40,12);
		printf("Inicio (Digite 1):");
		gotoxy(40,14);
		printf("Sobre (Digite 2):\n");
		gotoxy(50,15);
		scanf("%d", &begin);
	}
	if(begin == 2){
		system("cls");
		gotoxy(40,5);
		printf("MÉTODOS DE ORDENAÇÃO:\n\n");
		printf("\t\t\tNeste programa, o usuário fornece um vetor\n");
		printf("\t\t\te o seu tamanho. Após isso, ele escolhe um dos\n");
		printf("\t\t\tmétodos de ordenação e se prefere uma ordenação\n");
		printf("\t\t\tcrescente ou decrescente. Depois do nosso processamento\n");
		printf("\t\t\to usuário tem a opção de fazer uma busca de algum elemento.\n\n");
		printf("\t\t\tDesenvolvido por: Bruno Eduardo\n");
		printf("\t\t\tFeito para obtenção da nota parcial\n");
		printf("\t\t\tda matéria de Progamação de Computadores II\n\n");
		printf("\t\t\tdo curso de Ciência da Computação\n\n");
		printf("\t\t\tAgradecimento para a professora Lúcelia\n\n\n");
		system("pause");
	}
}

void gotoxy(int x, int y){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void alocacao(int t, int *vq, int *v){
	int i;
	
	vq = malloc(t * sizeof(int));
	for(i=0;i<t;i++){
		*(vq+i) = *(v+i);
	}
	
	
}

void leitura(int *v, int t){
	int i;
	
	
	printf("Digite os elementos: ");
	for(i=0;i<t;i++){
		scanf("%d", (v+i));
	}
}

void bubble_c(int *v, int t){
	int i, j, aux, k=0, *vq;
	
	alocacao(t,vq,v);
	
	for(i=0;i<t-1;i++){
		for(j=0;j<t-1-i;j++){
			if(*(vq+j) > *(vq+j+1)){
				aux = *(vq+j);
				*(vq+j) = *(vq+j+1);
				*(vq+j+1) = aux;
				k++;
			}
		}
	}
	printf("%d trocas feitas\n", k);
	system("pause");
}

void bubble_d(int *v, int t){
	int i, j, aux, k=0, *vq;
	
	alocacao(t,vq,v);
	
	for(i=0;i<t-1;i++){
		for(j=0;j<t-1-i;j++){
			if(*(vq+j) < *(vq+j+1)){
				aux = *(vq+j);
				*(vq+j) = *(vq+j+1);
				*(vq+j+1) = aux;
				k++;
			}
		}
	}
	printf("%d trocas feitas\n", k);
	system("pause");
}

void insertion_c(int *v, int t){
	int i, p=0, j, temp, k=0, *vq;

	alocacao(t,vq,v);

	for(i=1;i<t;i++){
		temp= *(v+i);
		j=i-1;
		while(j>=0 && *(v+j) > temp){
			*(v+j+1) = *(v+j);
			j--;
			k++;
		}
		*(v+j+1) = temp;
		p++;
	}
	printf("%d trocas feitas\n", k);
	system("pause");
}

void insertion_d(int *v, int t){
	int i, p=0, j, temp, k=0, *vq;

	alocacao(t,vq,v);

	for(i=1;i<t;i++){
		temp= *(v+i);
		j=i-1;
		while(j>=0 && *(v+j) < temp){
			*(v+j+1) = *(v+j);
			j--;
			k++;
		}
		*(v+j+1) = temp;
		p++;
	}
	printf("%d trocas feitas\n", k);
	system("pause");
}

void selection_c(int *v, int t){
	int i=0, j=0, min=0, aux=0, k=0, *vq;

 	alocacao(t,vq,v);

	for(i=0;i<t-1;i++){
		min=i;
		for(j=i+1;j<t;j++){
			if(*(vq+j) < *(vq+min)){
				min=j;
			}
			
		}
		if(i!=min){
			aux = *(vq+i);
			*(vq+i) = *(vq+min);
			*(vq+min) = aux;
			k++;
		}
	}
	printf("%d trocas feitas\n", k);
	system("pause");
}

void selection_d(int *v, int t){
	int i=0, j=0, min=0, aux=0, k=0, *vq;

 	alocacao(t,vq,v);

	for(i=0;i<t-1;i++){
		min=i;
		for(j=i+1;j<t;j++){
			if(*(vq+j) > *(vq+min)){
				min=j;
			}
			
		}
		if(i!=min){
			aux = *(vq+i);
			*(vq+i) = *(vq+min);
			*(vq+min) = aux;
			k++;
		}
	}
	printf("%d trocas feitas\n", k);
	system("pause");
}

void intercalar(int *v, int *vetAux, int ini1, int ini2, int fim2){
	int in1 = ini1, in2 = ini2, fim1 = in2-1, au = 0, i;
 
 	while(in1 <= fim1 && in2 <= fim2){
  		if(*(v+in1) < *(v+in2)){
   			*(vetAux+au++) = *(v+in1++);
  		}else{
   			*(vetAux+au++) = *(v+in2++);
 		}
	}
 	while(in1 <= fim1){
  		*(vetAux+au++) = *(v+in1++);
 	}
 	while(in2 <= fim2){
  		*(vetAux+au++) = *(v+in2++);
 	}
 	for(i=0;i<au;i++){
  		*(v+i+in1) = *(vetAux+i);
 	}
}

void mergeSort(int *v, int *vetAux, int esq, int dir){
	int meio = 0;
	
	if(esq < dir){
  		meio = (esq+dir)/2;
  		mergeSort(v, vetAux, esq, meio);
  		mergeSort(v, vetAux, meio+1, dir);
  		intercalar(v, vetAux, esq, meio+1, dir);
 	}	

}

int busca_s(int *v, int t, int num){
	int i;
	
	for(i=0;i<t;i++){
		if(*(v+i) == num){
			return 1;
		}
	}
	return 0;	
	
}

int busca_bin(int *v, int t, int num){
	int inicio=0, fim = t - 1, meio;
	
	while(inicio<=fim){
		meio = ((inicio+fim) / 2);
		if(num == *(v+meio)){
			return 1;
		}else if(num < *(v+meio)){
			fim=meio-1;
		}else{
			inicio=meio+1;	
		}
	}
	return 0;
}

void escolha(int *v, int t, int *vetAux, int esq, int dir){
	int s, b, a, c, num;
	
	printf("----- Métodos de Ordenação ------\n\n\nBubble - 1\nInsertion - 2\nSelection - 3\nMerge - 4\n\nQual método de ordenação deseja: ");
	scanf("%d", &s);
	while(s<1 || s>4){
		system("cls");
		printf("Escolha inválida!\n\nBubble - 1\nInsertion - 2\nSelection - 3\nMerge - 4\n\nDigite novamente: ");
		scanf("%d", &s);
	}
	system("cls");
	switch(s){
		case 1:
			printf("------ Bubble -----\n\n1 - Crescente\n2 - Decrescente\n\nDeseja fazer qual ordenação: ");
			scanf("%d", &b);
			while(b<1 || b>2){
				system("cls");
				printf("Escolha inválida!\n\nBubble Crescente - 1\nBubble Decresente - 2\n\nDigite novamente: ");
				scanf("%d", &b);	
			}
			if(b == 1){
				bubble_c(v,t);
				system("cls");
				imprime(v,t);
				printf("Entrou buc");
			}else{
				bubble_d(v,t);
				system("cls");
				imprime(v,t);
				printf("Entrou bud");
			}
			break;
		case 2:
			printf("------ Insertion -----\n\n1 - Crescente\n2 - Decrescente\n\nDeseja fazer qual ordenação: ");
			scanf("%d", &b);
			while(b<1 || b>2){
				system("cls");
				printf("Escolha inválida!\n\nInsertion Crescente - 1\nInsertion Decresente - 2\n\nDigite novamente: ");
				scanf("%d", &b);	
			}
			if(b == 1){
				insertion_c(v,t);
				system("cls");
				imprime(v,t);
				printf("Entrou inc");
			}else{
				insertion_d(v,t);
				system("pause");
				system("cls");
				imprime(v,t);
			}
			break;
		case 3:
			printf("------ Selection -----\n\n1 - Crescente\n2 - Decrescente\n\nDeseja fazer qual ordenação: ");
			scanf("%d", &b);
			while(b<1 || b>2){
				system("cls");
				printf("Escolha inválida!\n\nSelection Crescente - 1\nSelection Decresente - 2\n\nDigite novamente: ");
				scanf("%d", &b);	
			}
			if(b == 1){
				selection_c(v,t);
				system("cls");
				imprime(v,t);
			}else{
				selection_d(v,t);
				system("cls");
				imprime(v,t);
				
			}
			break;
		case 4:
			printf("------ Merge -----\n\n");
			mergeSort(v,vetAux,esq,dir);
			imprime(v,t);
			break;
	}
	system("pause");
	printf("\nDeseja fazer uma busca de um elemento?\n\nSim - 1\nNão - 2\n\n");
	scanf("%d", &a);
	while(a==1){
		while(a<1 || a>2){
			system("cls");
			printf("Escolha inválida!\n\nFazer busca - 1\nNão fazer busca - 2\n\nDigite novamente: ");
			scanf("%d", &a);
		}
		system("cls");
		if(a == 1){
			printf("------- Busca -------\n\nBusca Sequencial - 1\nBusca Binária - 2\n\nQual busca deseja fazer: ");
			scanf("%d", &c);
			while(c<1 || c>2){
				system("cls");
				printf("Escolha inválida!\n\nFazer busca sequencial - 1\nFazer busca binária - 2\n\nDigite novamente: ");
				scanf("%d", &c);
			}
			system("cls");
			imprime(v,t);
			printf("Qual elemento deseja procurar: ");
			scanf("%d", &num);
			if(c==1){
				if(busca_s(v,t,num) == 1)
					printf("Achou!\n\n");
				else
					printf("Não achou!\n\n");
			}else{
				if(busca_bin(v,t,num) == 1){
					printf("Achou!\n\n");
				}else{
					printf("Não achou!\n\n");
				}
			}
		}
		system("pause");
		system("cls");
		printf("Deseja fazer outra busca?\n\nSim - 1\nNão - 2\n\n");
		scanf("%d", &a);
	}
	
}

void imprime(int *v, int t){
	int i;
	
	for(i=0;i<t;i++)
		printf("%d ", *(v+i));
	printf("\n");
}

//Melhor dos casos: v[N] = {14, 39, 43, 50, 63, 71, 82, 85, 97};
//Caso médio: v[N] = {82,50,71,63,85,43,39,97,14};
//Pior dos casos: v[N] = {97, 85, 82, 71, 63, 50, 43, 39, 14};

int main(void){
	int *v, *vetAux = 0, esq=0, dir, t=0;
	
	setlocale(LC_ALL, "Portuguese");
	system("color F4");

	inicio();
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &t);
	dir=t;
	leitura(v,t);
	system("cls");
	escolha(v,t,vetAux,esq,dir);
	system("cls");
	
	free(v);
	v = NULL;
	 
	return 0;
}
