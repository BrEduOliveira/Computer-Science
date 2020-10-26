//Este é um jogo criado para o projeto fnal da matéria de Programação de Computadores I

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<unistd.h>
#include<DOS.h>
#define M 6 // Número 6 usado várias vezes no decorrer do código 

int qtdJog, maxjogadas, i=0, j=0, k, aux=0, jogadas=0, vez=0, maior=0, inicio, jogPontos[4], mapa[M][M], mg[M][M], jogador[M][M], cores[M][M];
char nomeJog[4][30];

// limpa a tela quando requisitado
void limpaTela(){
	system("cls");
}

// Colore os jogadores entre outras coisas
void corJogadores(int i){
	
	textbackground(i);
}

// Volta a cor padrão
void limpaCores(){
	
	textbackground(0);
}

// Interface inicial do jogo
void iniciando(){
	
	printf("\n\n");
	printf("\t##     ##    ###    ########     ###       ########     ###       ##     ## #### ##    ##    ###    \n");
	printf("\t###   ###   ## ##   ##     ##   ## ##      ##     ##   ## ##      ###   ###  ##  ###   ##   ## ##   \n");
	printf("\t#### ####  ##   ##  ##     ##  ##   ##     ##     ##  ##   ##     #### ####  ##  ####  ##  ##   ##  \n");
	printf("\t## ### ## ##     ## ########  ##     ##    ##     ## ##     ##    ## ### ##  ##  ## ## ## ##     ## \n");
	printf("\t##     ## ######### ##        #########    ##     ## #########    ##     ##  ##  ##  #### ######### \n");
	printf("\t##     ## ##     ## ##        ##     ##    ##     ## ##     ##    ##     ##  ##  ##   ### ##     ## \n");
	printf("\t##     ## ##     ## ##        ##     ##    ########  ##     ##    ##     ## #### ##    ## ##     ##\n\n");
	gotoxy(40,12);
	printf("Inicio (Digite 1):");
	gotoxy(40,14);
	printf("Sobre (Digite 2):\n");
	gotoxy(50,15);
	scanf("%d", &inicio);
	if(inicio == 2){
		limpaTela();
		gotoxy(40,5);
		printf("O JOGO:\n\n");
		printf("\t\t\tOs jogadores deverão encontrar os diamantes mais\n");
		printf("\t\t\tpreciosos no mapa de uma mina. Na mina, há diamantes\n");
		printf("\t\t\tde quilates variados (de 1 até 10). O vencedor é quem\n");
		printf("\t\t\tobtiver a maior soma de quilates.\n\n");
		printf("\t\t\tDesenvolvido por: Bruno Eduardo\n");
		printf("\t\t\tFeito para obtenção da nota parcial\n");
		printf("\t\t\tda matéria de Ciência da Computação\n\n");
		printf("\t\t\tAgradecimento para o professor Sandro Rautenberg\n\n\n");
		system("pause");

	}else if(inicio == 1){
		
	}else{
		limpaTela();
		gotoxy(40,10);
		printf("Inicio (Digite 1):");
		gotoxy(40,12);
		printf("Sobre (Digite 2):");
		gotoxy(40,14);
		printf("Número inválido!");
		scanf("%d", &inicio);
	}
}

// Inicializa a qtd de Jogadores e o nome de cada um deles
void inicializaJogadores(){

	gotoxy(40,10);
	printf("Digite quantos jogadores (2 a 4): ");
	scanf("%d", &qtdJog);
	while((qtdJog < 2) || (qtdJog > 4)){
		limpaTela();
		gotoxy(40,10);
		printf("Número de jogadores inválido!\n\t\t\t\t\t       Digite novamente: ");
		scanf("%d", &qtdJog);
		limpaTela();
	}
	limpaTela();
	for(i=0;i<qtdJog;i++){
		gotoxy(40,10);
		printf("Digite o nome do jogador %d: ", i+1);
		corJogadores(i+1);
		scanf("%s", nomeJog[i]);
		limpaCores();
		limpaTela();
	}	
}

// Printa o nome dos jogadores
void mostraJogadores(){
	
	for(i=0;i<qtdJog;i++){
		printf("Jogador %d: %s", i+1, nomeJog[i]);
		printf("\n");
	}
}

// Inicializa o mapa com os valores aleatorios de quilates
void inicializaMapa(){
	
	srand(time(NULL));
	for(i=0;i<M;i++){
		for(j=0;j<M;j++){
			mapa[i][j] = (rand()%10)+1;
			mg[i][j] = -1;
			jogador[i][j] = -1;
		}
	}
}

// Inicializa as magias no mapa
void inicializaMagias(){
	
	for(aux=0;aux<2;aux++){
		i = rand() % 6;
		j = rand() % 6;
		if(mg[i][j] == -1){
			mg[i][j] = 'O';
			mapa[i][j] = 'O';
		}
	}
	for(aux=0;aux<2;aux++){
		i = rand() % 6;
		j = rand() % 6;
		if(mg[i][j] == -1){
			mg[i][j] = '+';
			mapa[i][j] = '+';
		}
	}
	for(aux=0;aux<2;aux++){
		i = rand() % 6;
		j = rand() % 6;
		if(mg[i][j] == -1){
			mg[i][j] = '-';
			mapa[i][j] = '-';
		}
	}
	for(aux=0;aux<2;aux++){
		i = rand() % 6;
		j = rand() % 6;
		if(mg[i][j] == -1){
			mg[i][j] = '=';
			mapa[i][j] = '=';
		}
	}
	for(aux=0;aux<2;aux++){
		i = rand() % 6;
		j = rand() % 6;
		if(mg[i][j] == -1){
			mg[i][j] = '!';
			mapa[i][j] = '!';
		}
	}
}

// Printa o mapa com as magias
void mostraMapaMagias(){
	
	for(i=0;i<M;i++){
		for(j=0;j<M;j++){
			if(mapa[i][j] == 10){
				printf(" |%d|", mapa[i][j]);
			}
			else if(mapa[i][j] > 10){
				printf(" |%c |", mapa[i][j]);
				}else{
					printf(" |%d |", mapa[i][j]);
				}
		}
		printf("\n");
	}	
}

// Printa o placar por cada rodada
void placar(int vez){
	
	gotoxy(42,3);
	printf("########## PLACAR ###########");
	for(k=0;k<qtdJog;k++){
		gotoxy(42,k+5);
		corJogadores(k+1);
		printf("Jogador %d: %s tem %d ponto(s).\n", k+1, nomeJog[k], jogPontos[k]);
		limpaCores();
	}
}

// Printa o placar final
void placarFinal(){
	
	limpaTela();
	gotoxy(40,8);
	printf("########## PLACAR FINAL ###########");
	for(k=0;k<qtdJog;k++){
		gotoxy(40,k+10);
		corJogadores(k+1);
		printf("Jogador %d: %s fez %d ponto(s).\n", k+1, nomeJog[k], jogPontos[k]);
		limpaCores();
	}
}

// Printa o mapa que será feito as jogadas
void mostraMapaJogadores(){
	
	printf("\n");
	printf("      0     1     2     3     4     5");
	printf("\n\n");
	for(i=0;i<M;i++){
		printf(" %d  ", i);
		for(j=0;j<M;j++){
			if(jogador[i][j] == 10){
				corJogadores(cores[i][j]);
				printf(" |%d| ", jogador[i][j]);
				limpaCores();
			}else if(jogador[i][j] > 10){
				corJogadores(cores[i][j]);
				printf(" |%c | ", jogador[i][j]);
				limpaCores();
				}else if(jogador[i][j] == -1){
					printf(" |X | ", jogador[i][j]);
					limpaCores();
				}else{
					corJogadores(cores[i][j]);
					printf(" |%d | ", jogador[i][j]);
					limpaCores();
				}
		}
		printf("\n\n");
	}	
}

// Soma os pontos de cada jogador por jogada
void pontos(int i, int j, int vez){
	
	if(jogador[i][j] <= 10){
		jogPontos[vez] += jogador[i][j];
		gotoxy(0,0);
		corJogadores(2);
		printf(" O Jogador %d ganhou %d quilates.", vez+1, jogador[i][j]);
		limpaCores();
	}else if(jogador[i][j] == 'O'){
		jogPontos[vez] -= 10;
		gotoxy(0,0);
		corJogadores(4);
		printf(" O Jogador %d caiu no buraco e perdeu 10 quilates.", vez+1, jogador[i][j]);
		limpaCores();
	}else if(jogador[i][j] == '+'){
		jogPontos[vez] += 10;
		gotoxy(0,0);
		corJogadores(2);
		printf(" O Jogador %d achou a Magia Plus (%c) e ganhou 10 quilates.", vez+1, jogador[i][j]);
		limpaCores();
	}else if(jogador[i][j] == '-'){
		gotoxy(0,0);
		corJogadores(4);
		printf(" O Jogador %d achou a Magia Off (%c) e retirou 5 quilates de seus oponentes.", vez+1, jogador[i][j]);
		limpaCores();
		for(k=0;k<qtdJog;k++){
			if(k != vez){
				jogPontos[k] -= 5;
			}
		}
	}else if(jogador[i][j] == '='){
		jogPontos[vez] += i+j;
		gotoxy(0,0);
		corJogadores(1);
		printf(" O Jogador %d achou a Magia Posição PLus (%c) ", vez+1, jogador[i][j]);
		limpaCores();
	}else{
		jogPontos[vez] -= i+j;
		gotoxy(0,0);
		corJogadores(1);
		printf(" O Jogador %d achou a Magia Posição Off (%c) ", vez+1, jogador[i][j]);
		limpaCores();
	}
}

// O jogo em si
void fazJogadas(){

	for(jogadas=0;jogadas<(36/qtdJog);jogadas++){
		for(vez=0;vez<qtdJog;vez++){
			printf("\n");
			gotoxy(1,17);
			corJogadores(vez+1);
			printf("Jogador %d escolha a linha:", vez+1);
			limpaCores();
			scanf("%d", &i);
			corJogadores(vez+1);
			printf(" Agora escolha a coluna:");
			limpaCores();
			scanf("%d", &j);
			if((jogador[i][j] != -1) || ((i>6 || i<0) || (j>6 || j<0))){
				while((jogador[i][j] != -1) || ((i>6 || i<0) || (j>6 || j<0))){
					printf("\n");
					printf(" Jogada inválida!\n Tente novamente:");
					scanf("%d %d", &i, &j);
				}
			}
			jogador[i][j] = mapa[i][j];
			cores[i][j] = vez + 1;
			limpaTela();
			pontos(i, j, vez);
			printf("\n");
			mostraMapaJogadores();
			printf("\n");
			placar(vez);
		}
	}
}

// Funçao principal que requisita as outras funções
int main(void){
	
	setlocale(LC_ALL, "Portuguese");

	iniciando();
	limpaTela();
	inicializaJogadores();
	inicializaMapa();
	inicializaMagias();
	printf("\n");
	mostraMapaJogadores();
	placar(vez);
	fazJogadas();
	placarFinal();
	printf("\n\n\n\n\n\n\n\n\n");
	return 0;
}
