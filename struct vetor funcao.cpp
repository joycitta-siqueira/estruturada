#include<stdio.h>

typedef struct pet {
	char nome[10], raca[10], cor[10];
	float peso;	
} pet;

int main(){
	
	pet dog[2], cat[2];
	int i;
	
	for(i=0;i<2;i++){
		printf("---- DOG ----\n");
		printf("Digite o nome: ");
		fgets(dog[i].nome, 10, stdin);
		fflush(stdin);
		printf("Digite o peso: ");
		scanf("%f", &dog[i].peso);
		printf("Digite a raca: ");
		fgets(dog[i].raca, 10, stdin);
		printf("Digite a cor: ");
		fgets(dog[i].cor, 10, stdin);
		fflush(stdin);

	}
	
	for(i=0;i<2;i++){
		printf("---- CAT ----\n");
		printf("Digite o nome: ");
		fgets(cat[i].nome, 10, stdin);
		fflush(stdin);
		printf("Digite o peso: ");
		scanf("%f", &cat[i].peso);
		printf("Digite a raca: ");
		fgets(cat[i].raca, 10, stdin);
		fflush(stdin);
		printf("Digite a cor: ");
		fflush(stdin);
		fgets(cat[i].cor, 10, stdin);
		fflush(stdin);

	}
	
	for(i=0;i<2;i++){
		printf("---- DOG ----\n");
		printf("%s - %s - %s - %.1f\n", dog[i].nome, dog[i].raca, dog[i].cor, dog[i].peso);
		printf("---- CAT ----\n");
		printf("%s - %s - %s - %.1f\n", cat[i].nome, cat[i].raca, cat[i].cor, cat[i].peso);
	}
	
}
