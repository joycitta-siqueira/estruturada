#include<stdio.h>
#include <cstdlib>

// estrutura para a criação da lista, formada por Agendas.
typedef struct agenda{
	int codigo;
	char nome[50], telefone[20];
	struct agenda *ponteiro; //ponteiro do tipo Agenda
} Agenda;

//declaração das funções
Agenda* inicializar(); 
Agenda* inserir(Agenda*);
void relatorio(Agenda*);
void menu();


int main(){

	int menuEscolha;
	Agenda* pessoa; //cria a lista pessoa, do tipo Agenda
	
	pessoa = inicializar(); //inicializa a lista vazia

	do{
	menu();
	scanf("%d",&menuEscolha);
	switch(menuEscolha){
		case 1: pessoa=inserir(pessoa); break;
		case 2: relatorio(pessoa); break;
		case 0: return 0; //finaliza o programa
		default: printf("\nOpção inválida!\n\n");
  	}
	printf("Deseja realizar outra operacao: qualquer valor diferente de zero\n");
	scanf("%d",&menuEscolha);
	}while (menuEscolha!=0);
	
	system("cls");
	return 0;
}

//função para inicialização da lista do tipo Agenda
Agenda* inicializar(){
	return NULL; // a constante NULL é parte da biblioteca <stdlib.h> 
}

//função para inserção de novos Agendas
Agenda* inserir(Agenda* pessoa){
	
	Agenda* novo = (Agenda*) malloc(sizeof(Agenda));
	printf("\n---------------------------------------------------");
	printf("\n-------------Cadastro de Agenda-------------------");
	printf("\n---------------------------------------------------\n");
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
	
	return novo;
}

// função para listar os Agendas cadastrados
void relatorio(Agenda* pessoa){
	Agenda* auxiliar;
	int i;
	printf("\n---------------------------------------------------");
	printf("\n------------Relatorio de Agendas------------------");
	printf("\n---------------------------------------------------\n");
	for(auxiliar=pessoa,i=0;auxiliar!=NULL;auxiliar=auxiliar->ponteiro,i++){
		printf("\n---------------------------------------------------");
		printf("\n----------------Agenda [%d]------------------------",i+1);
		printf("\n---------------------------------------------------\n");
		printf("\nCodigo: %d",auxiliar->codigo);
		printf("\nNome: %s",auxiliar->nome);
		printf("\nTelefone: %s",auxiliar->telefone);
		printf("\nPonteiro: %d\n\n",auxiliar->ponteiro);
	}
}

void menu(){
	//exibição e leitura de menu
	printf("\n---------------------------------------------------");
	printf("\n-------------Controle de pessoas-------------------");
	printf("\n---------------------------------------------------\n");
	printf("1- Cadastrar pessoa\n");
	printf("2- Relatório de Agendas\n");
	printf("0- Sair\n");
	printf("\n---------------------------------------------------\n");
	printf("Digite a opcao desejada:\n");
}


