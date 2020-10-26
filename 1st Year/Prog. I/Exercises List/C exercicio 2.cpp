#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main (){
   float media, metade;
   int x;

    setlocale(LC_ALL, "Portuguese");
    for(int num = 1; num <= 10; num++){
        scanf("%d", &x);
        metade = (float)x / 2;
        printf("A metade de %d é %0.1f\n", x, metade);
        media += x;
    }
    media = media / 10;
    printf("\nA media é %0.2f", media);



return 0;
}
