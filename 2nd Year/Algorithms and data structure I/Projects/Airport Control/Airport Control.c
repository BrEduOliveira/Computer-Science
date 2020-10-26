#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#include<locale.h>
#include<windows.h>
#include<time.h>
#include "Special Functions.h"

int main(void){
	no *F, *FP;
	int ut, num, numVoo, prior, i;
	//indica qual empresa é responsavel pelo voo
	char empresa;
	int continua = 1;
	
	setlocale(LC_ALL, "Portuguese");
	
	//SIGLA DAS EMPRESAS AEREAS
	
	//G - GOL
	//A - AZUL
	//T - TAM
	//E - EMIRATES
	//Q - QATAR
	
	inicializa(&F);
	inicializa(&FP);
	insere_Fila(&F, 2310, 2, 'G');
	insere_Fila(&F, 1222, 1, 'T');
	insere_Fila(&F, 3430, 3, 'A');
	insere_Fila(&F, 2558, 2, 'G');
	insere_Fila(&F, 3312, 3, 'E');
	insere_Fila(&F, 2400, 2, 'Q');
	insere_Fila(&F, 2880, 2, 'T');
	insere_Fila(&F, 3224, 3, 'A');
	insere_Fila(&F, 1200, 1, 'Q');
	insere_Fila(&F, 2482, 2, 'G');
	insere_Fila(&F, 3320, 3, 'E');
	insere_Fila(&F, 2578, 2, 'A');
	insere_Fila(&F, 3240, 3, 'Q');
	insere_Fila(&F, 3180, 3, 'T');
	insere_Fila(&F, 1134, 1, 'G');
	
	//layout
	printf("  `7MM'''Mq.       db      `7MM''''Mq.  MMP''MM''YMM `7MMF'`7MM''Yb.         db       .M''''bgd        AW \n");
	printf("    MM   `MM.     ;MM:       MM   `MM.  P'  MM   `7   MM    MM    `Yb.      ;MM:     ,MI    'Y        ,M' \n");
	printf("    MM   ,M9     ,V^MM.      MM   ,M9       MM        MM    MM     `Mb     ,V^MM.    `MMb.            MV  \n");
	printf("    MMmmdM9     ,M  `MM      MMmmdM9        MM        MM    MM      MM    ,M  `MM      `YMMNq.       AW   \n");
	printf("    MM          AbmmmqMA     MM  YM.        MM        MM    MM     ,MP    AbmmmqMA   .     `MM      ,M'   \n");
	printf("    MM         A'     VML    MM   `Mb.      MM        MM    MM    ,dP'   A'     VML  Mb     dM      MV    \n");
	printf("  .JMML.     .AMA.   .AMMA..JMML. .JMM.   .JMML.    .JMML..JMMmmmdP'   .AMA.   .AMMA.P'Ybmmd'      AW     \n\n");
	
	printf(" `7MM''''Yb.  `7MM''YMM  `7MM''''Mq.    db      `7MM''Mq.  MMP''MM''YMM `7MMF'  `7MF'`7MM''''Mq. `7MM''YMM   .M''bgd \n");
	printf("   MM    `Yb.  MM    `7    MM   `MM.   ;MM:      MM   `MM. P'   MM   `7   MM      M    MM   `MM.  MM    `7  ,MI    'Y \n");
	printf("   MM     `Mb  MM   d      MM   ,M9   ,V^MM.     MM   ,M9       MM        MM      M    MM   ,M9   MM   d    `MMb.     \n");
	printf("   MM      MM  MMmmMM      MMmmdM9   ,M  `MM     MMmmdM9        MM        MM      M    MMmmdM9    MMmmMM    ` YMMNq. \n");
	printf("   MM     ,MP  MM   Y  ,   MM        AbmmmqMA    MM  YM.        MM        MM      M    MM  YM.    MM   Y  ,      `MM \n");
	printf("   MM    ,dP'  MM     ,M   MM       A'     VML   MM   `Mb.      MM        YM.    ,M    MM   `Mb.  MM     ,M Mb    dM \n");
	printf(" .JMMmmmdP'  .JMMmmmmMMM .JMML.   .AMA.   .AMMA.JMML. .JMM.   .JMML.       `bmmmd''  .JMML. .JMM.JMMmmmmMMMP''Ybmmd'  \n\n");
	
	printf("\tNÚMERO DO VOO\t\tCIA\t\tSITUAÇÃO\n\n");

	//função criada em especial para o layout
	exibe_Fila_Inicio(&F);
	printf("\n\n---------------------------------------------------------------------------------\n\n");
	system("pause");

	//realiza todos os voos (3 voo por vez)
	for(ut=1; continua; ut++) {
		printf("\n-------------------------------------------------------------------------------------------\n");
		printf("\nTEMPO:\t %d:00:00\n", ut);
		
		for (num=1; num<=3; num++) {
			if (F != NULL) {
				remove_FP(&F, &numVoo, &prior, &empresa);
				insere_FP(&FP, numVoo, prior, empresa);
			}
		}
		printf("\nFILA DE VOOS EM ESPERA: "); 
		exibe_Fila(&FP);
		printf("\n");
		
		//verifica até todas as pistas serem ocupadas
		if ((ut%2)&&(continua)) {
			for (i=1; i<=2; i++) {
				if (FP != NULL) {
					remove_FP(&FP, &numVoo, &prior, &empresa);
					//se o voo for de pouso de emergencia
					if((numVoo >= 1000) && (numVoo <= 1999)){
						printf("\nPISTA \tVOO\n");
						printf("%d\t%c%d", i, empresa, numVoo);
						textcolor(15,4);
						printf("\n\nATENÇÃO!\n\n");
						printf("POUSO DE EMERGÊNCIA\n\n");
						system("pause");
						textcolor(15,0);
					}
					//se o voo for um pouso normal
					else if((numVoo >= 2000) && (numVoo <= 2999)){
						printf("\nPISTA \nVOO\n");
						printf("%d\t%c%d\n", i, empresa, numVoo);
						printf("POUSO NORMAL\n");
					}
					//se o voo for decolagem
					else{
						printf("\nPISTA \tVOO\n");
						printf("%d\t%c%d\n", i, empresa, numVoo);
						printf("\nDECOLAGEM\n");
					}
				}
				//quando todas os voos forem realizados, juntamente com o total de unidades de tempo
				else {
					continua = 0; 
					printf("\n\nTODOS OS VOOS FORAM REALIZADOS\nPISTAS VAZIAS");
					printf("\n------------------------------------------------------------------------------------------------\n");
					printf("\nTEMPO TOTAL: %d UNIDADES.", ut);
				}
			}
		}
		//quando as duas pistas forem ocupadas
		else {
			printf("\nATENÇÃO\n\nPISTAS OCUPADAS!");
		}
	}
}
