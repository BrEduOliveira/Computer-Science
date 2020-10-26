// biblioteca da aula do dia 03-07 mas um pouco modificada em especial para esse trabalho

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//uma serie de funções da biblioteca windows.h para poder modificar as cores e outras coisas

/*             0     1    2     3   4      5      6      7         8  */
typedef enum{BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,   /* nome das cores */
LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE} COLORS;
/*  9         10         11        12        13         14    15 */

static int __BACKGROUND = 1/*BLACK*/;/*pode ser o numero ou o nome da cor*/
static int __FOREGROUND = LIGHTGRAY;

void textcolor (int letras, int fundo){/*para mudar a cor de fundo mude o background*/
    __FOREGROUND = letras;
    __BACKGROUND = fundo;
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letras + (__BACKGROUND << 4));
}

typedef struct node {
    int info;
    int prior;
    char cod;
    struct node *link;
} no;

void inicializa(no **L)
{
    *L = NULL;
}

void insere_FP(no **L, int valor, int prior, char empresa)
{
    no *N, *P, *ANT;

    N = (no *) malloc(sizeof(no));
    N->info = valor;
    N->cod = empresa;
    N->prior = prior;

    if (*L == NULL) {
        *L = N;
        N->link = NULL;
    }
    else {
        P = *L;

        while ((P != NULL) && (prior >= P->prior)) {
            ANT = P;
            P = P->link;
        }
        if (P == *L) {
            N->link = *L;
            *L = N;
        }
        else {
            ANT->link = N;
            N->link = P;
        }
    }
}

void remove_FP(no **L, int *d, int *p, char *e) {
	no *AUX;

	if (*L != NULL) {
		*d = (*L)->info;
		*p = (*L)->prior;
		*e = (*L)->cod;
		AUX = *L;
		*L = (*L)->link;
		free(AUX);
	}
}

// função que insere item no final da Fila
void insere_Fila(no **L, int data, int prior, char empresa) {
	no *P, *N;

	N = (no *) malloc (sizeof(no)); 
	N->info = data; 
	N->prior = prior; 
	N->cod = empresa;
	N->link = NULL; 
	 
	if (*L == NULL){ 
		*L = N;
	}
	else { 
		P = *L;	
	
		while(P->link != NULL) {
			P = P->link;
		}
		P->link = N;
	} 
}


void exibe_FP(no **L)
{
    no *P = *L;

    while (P != NULL) {
        printf("P %d - %c-%d \n", P->prior, P->cod, P->info);
        P = P->link;
    }
}

void exibe_Fila(no **L)
{
    no *P = *L;

    while (P != NULL) {
		printf("%c%d-%d   ", P->cod, P->info, P->prior);
        P = P->link;
    }
}

void exibe_Fila_Inicio(no **L)
{
    no *P = *L;

	//escolha das empresas e prioridades
	// Beep - um som curto
	//Sleep - delay no código

    while (P != NULL) {		
		//                GOL
		if((P->cod == 'G') && (P->prior == 1)){
			textcolor(15,4);
			printf("\t%c%d\t\t\tGOL\t\tPOUSO DE EMERGÊNCIA\n", P->cod, P->info);
        	P = P->link;
        	Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
    	}else if((P->cod == 'G') && (P->prior == 2)){
			textcolor(15,1);
			printf("\t%c%d\t\t\tGOL\t\tPOUSO\n", P->cod, P->info);
        	P = P->link;
        	Beep(2000, 150);
			Sleep(500);
    	}else if((P->cod == 'G') && (P->prior == 3)){
			textcolor(15,2);
			printf("\t%c%d\t\t\tGOL\t\tDECOLAGEM\n", P->cod, P->info);
        	P = P->link;
			Beep(3000, 150);
			Sleep(500);
		
		//             TAM
		}else if((P->cod == 'T') && (P->prior == 1)){
			textcolor(15,4);
			printf("\t%c%d\t\t\tTAM\t\tPOUSO DE EMERGÊNCIA\n", P->cod, P->info);
        	P = P->link;
    		Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
		}else if((P->cod == 'T') && (P->prior == 2)){
			textcolor(15,1);
			printf("\t%c%d\t\t\tTAM\t\tPOUSO\n", P->cod, P->info);
        	P = P->link;
        	Beep(2000, 150);
			Sleep(500);
    	}else if((P->cod == 'T') && (P->prior == 3)){
			textcolor(15,2);
			printf("\t%c%d\t\t\tTAM\t\tDECOLAGEM\n", P->cod, P->info);
        	P = P->link;
			Beep(3000, 150);
			Sleep(500);
		
		//             AZUL
		}else if((P->cod == 'A') && (P->prior == 1)){
			textcolor(15,4);
			printf("\t%c%d\t\t\tAZUL\t\tPOUSO DE EMERGÊNCIA\n", P->cod, P->info);
        	P = P->link;
        	Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
    	}else if((P->cod == 'A') && (P->prior == 2)){
			textcolor(15,1);
			printf("\t%c%d\t\t\tAZUL\t\tPOUSO\n", P->cod, P->info);
        	P = P->link;
        	Beep(2000, 150);
			Sleep(500);
    	}else if((P->cod == 'A') && (P->prior == 3)){
			textcolor(15,2);
			printf("\t%c%d\t\t\tAZUL\t\tDECOLAGEM\n", P->cod, P->info);
        	P = P->link;
        	Beep(3000, 150);
			Sleep(500);
		
		//             EMIRATES
		}else if((P->cod == 'E') && (P->prior == 1)){
			textcolor(15,4);
			printf("\t%c%d\t\t\tEMIRATES\t\tPOUSO DE EMERGÊNCIA\n", P->cod, P->info);
        	P = P->link;
        	Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
    	}else if((P->cod == 'E') && (P->prior == 2)){
			textcolor(15,1);
			printf("\t%c%d\t\t\tEMIRATES\t\tPOUSO\n", P->cod, P->info);
        	P = P->link;
        	Beep(2000, 150);
			Sleep(500);
    	}else if((P->cod == 'E') && (P->prior == 3)){
			textcolor(15,2);
			printf("\t%c%d\t\t\tEMIRATES\tDECOLAGEM\n", P->cod, P->info);
        	P = P->link;
			Beep(3000, 150);
			Sleep(500);

		//             QATAR
		}else if((P->cod == 'Q') && (P->prior == 1)){
			textcolor(15,4);
			printf("\t%c%d\t\t\tQATAR\t\tPOUSO DE EMERGÊNCIA\n", P->cod, P->info);
        	P = P->link;
        	Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
			Beep(1000, 150);
			Sleep(100);
    	}else if((P->cod == 'Q') && (P->prior == 2)){
			textcolor(15,1);
			printf("\t%c%d\t\t\tQATAR\t\tPOUSO\n", P->cod, P->info);
        	P = P->link;
        	Beep(2000, 150);
			Sleep(500);
    	}else if((P->cod == 'Q') && (P->prior == 3)){
			textcolor(15,2);
			printf("\t%c%d\t\t\tQATAR\t\tDECOLAGEM\n", P->cod, P->info);
        	P = P->link;
        	Beep(3000, 150);
			Sleep(500);
		}else{
			printf("%c%d-%d   ", P->cod, P->info, P->prior);
    		P = P->link;
		}
    }
    textcolor(15,0);
}
