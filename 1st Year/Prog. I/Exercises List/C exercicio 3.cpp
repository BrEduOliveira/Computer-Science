#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main (){
   float pol = 1, result;
   int m;

    printf("Digite o numero maximo da tabela: \n");
    scanf("%d", &m);
    while(pol <= m){
        result = (float) pol * 2.54;
        printf("%0.2f\n", result);
        pol += 1;
    }







return 0;
}
