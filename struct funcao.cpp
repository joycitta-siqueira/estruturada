#include<stdio.h>

typedef struct pet {
	char nome[10], raca[10], cor[10];
	float peso;	
} pet;

pet preencherDog(pet dog){
		printf("---- DOG ----\n");
		printf("Digite o nome: ");
		fgets(dog.nome, 10, stdin);
		printf("Digite o peso: ");
		scanf("%f", &dog.peso);
		printf("Digite a raca: ");
		fgets(dog.raca, 10, stdin);
		printf("Digite a cor: ");
		fgets(dog.cor, 10, stdin);
	return dog;
}

void imprimirDog(pet dog){
	printf("---- DOG ----\n");
	printf("%s - %s - %s - %.1f\n", dog.nome, dog.raca, dog.cor, dog.peso);
}

int main(){
	pet dog;
	dog = preencherDog(dog);
	imprimirDog(dog);
}
