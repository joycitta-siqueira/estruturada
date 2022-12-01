#include<stdio.h>
#include<stdlib.h>

typedef struct agenda{
	int codigo;
	char nome[50], telefone[20];
	struct agenda *ponteiro; 
} Agenda;

int main(){
	
	Agenda* pessoa; //cria a lista pessoa, do tipo Agenda
	
	pessoa = NULL; 
	
	if (pessoa == NULL)
		printf("lista vazia!\n");

	Agenda* novo = (Agenda*) malloc(sizeof(Agenda));
	printf("\n Digite o codigo:");
	scanf("%d",&novo->codigo);
	fflush(stdin);
	printf("\n Digite o nome:");
	gets(novo->nome);
	fflush(stdin);
	printf("\n Digite o telefone:");
	scanf("%s",&novo->telefone);
	fflush(stdin);
	novo->ponteiro=pessoa;
	
	pessoa = novo;
	
	novo = (struct agenda*) malloc (sizeof(pessoa));
	
	printf("Digite o id");
	scanf("%d", &novo->codigo);
	
	printf("Digite o nome");
	scanf("%s", &novo->nome);
	fflush(stdin);

	printf("Digite o telefone");
	scanf("%s", &novo->telefone);
	fflush(stdin);
	
	novo->ponteiro = pessoa;
	
	pessoa = novo;
	
	for (pessoa;pessoa!=NULL;pessoa=pessoa->ponteiro){
		printf("Codigo: %d\t", pessoa->codigo);
		printf("Nome: %s\t", pessoa->nome);
		printf("Telefone: %s\t", pessoa->telefone);
		printf("Ponteiro: %d\n", pessoa->ponteiro);
		}
	

}


