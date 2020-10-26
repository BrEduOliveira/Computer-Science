#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define TAM 2

int main(void){
	int i=0, codigo=0, a=0, b=0, c=0, d=0, e=0, maior=0, menor=0;
	float peso=0, alt=0, imc[TAM], pa=0, pb=0, pc=0, pd=0, pe=0;
	char situacao[30], situacao2[30];
	strcpy(situacao, "Abaixo do peso"); 
	strcpy(situacao2, "Abaixo do peso"); 
	
	system("color 80");
	for(i=0;i<TAM;i++){
		scanf("%d %f %f", &codigo, &peso, &alt);
		imc[codigo] = peso / (alt*alt);
		if(imc[codigo]<20)
			a++;
		else if((imc[codigo]>=20) && (imc[codigo]<25))
			b++;
		else if((imc[codigo]>=25) && (imc[codigo]<30))
			c++;
		else if((imc[codigo]>=30) && (imc[codigo]<35))
			d++;
		else
			e++;
	}
	
	pa= (100*a) / TAM;
	pb= (100*b) / TAM;
	pc= (100*c) / TAM;
	pd= (100*d) / TAM;
	pe= (100*e) / TAM;
	
	printf("\n");
	printf("Percentual abaixo do peso = %.2f%%\n", pa);
	printf("Percentual normal = %.2f%%\n", pb);
	printf("Percentual excesso de peso = %.2f%%\n", pc);
	printf("Percentual obesidade = %.2f%%\n", pd);
	printf("Percentual obesidade morbida = %.2f%%\n\n", pe);
	
	
	maior=0;
	
	if(a>maior){
		maior=a;
		strcpy(situacao,"Abaixo do peso");
	}
	if(b>maior){
		maior=b;
		strcpy(situacao,"Normal");
	}
	if(c>maior){
		maior=c;
		strcpy(situacao,"Excesso de peso");
	}
	if(d>maior){
		maior=d;
		strcpy(situacao,"Obesidade");
	}
	if(e>maior){
		maior=e;
		strcpy(situacao,"Obesidade morbida");
	}
	
	menor=999;
	
	if((a<menor) && (a!=0)){
		menor=a;
		strcpy(situacao2, "Abaixo do peso");
	}
	if((b<menor) && (b!=0)){
		menor=b;
		strcpy(situacao2,"Normal");
	}
	if((c<menor) && (c!=0)){
		menor=c;
		strcpy(situacao2,"Excesso de peso");
	}
	if((d<menor) && (d!=0)){
		menor=d;
		strcpy(situacao2,"Obesidade");
	}
	if((e<menor) && (e!=0)){
		menor=e;
		strcpy(situacao2,"Obesidade morbida");
	}
	
	printf("Situacao %s possui a maior quantidade de individuos com %d individuos\n", situacao, maior);
	printf("Situacao %s possui a menor quantidade de individuos com %d individuos\n", situacao2, menor);
	
	for(i=1;i<=TAM;i++){
		if(imc[i]>30)
			printf("O paciente do codigo %d necessita de acompanhamento medico.\n", i);
		if(imc[i]<17)
			printf("O paciente do codigo %d esta com risco de morte.\n", i);
	}
	
	return 0;
}
