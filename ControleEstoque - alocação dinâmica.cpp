#include<stdio.h>
#include<locale.h>
#include <cstdlib>
#include<string.h>

// estrutura para a cria��o da lista, formada por produtos.
typedef struct produto{
	int codigo, quantidade;
	char descricao[50];
	float valor;
	struct produto *proximo;//ponteiro do tipo produto
} Produto;

//declara��o das fun��es
Produto* inicializar(); 
Produto* inserir(Produto*);
void relatorio(Produto*);
void consultarProduto(Produto*);
Produto* removerProduto(Produto*);
Produto* consultarVolume(Produto*);

main(){
//configura��o do idioma
setlocale(LC_ALL,"Portuguese");
int menu;
//lista para a aloca��o de produtos
Produto* estoque; //cria a lista estoque, do tipo produto
estoque = inicializar(); //inicializa a lista vazia
//personaliza��o de design
system("color fc");
    //menu
	do{
	//exibi��o e leitura de menu
	printf("\n---------------------------------------------------");
	printf("\n-------------Controle de Estoque-------------------");
	printf("\n---------------------------------------------------\n");
	printf("1- Cadastrar Produtos\n");
	printf("2- Consultar Produtos\n");
	printf("3- Relat�rio de Produtos\n");
	printf("4- Remover Produtos\n");
	printf("0- Sair\n");
	printf("\n---------------------------------------------------\n");
	printf("Digite a op��o desejada:\n");
	scanf("%d",&menu);
	switch(menu){
		case 1: estoque=inserir(estoque); break;
		case 2: consultarProduto(estoque); break;
		case 3: relatorio(estoque); break;
	 	case 4: estoque=removerProduto(estoque); break;
		case 0: return 0; //finaliza o programa
		default: printf("\nOp��o inv�lida!\n\n");
  	}
	printf("Deseja realizar outra operacao: qualquer valor diferente de zero\n");
	scanf("%d",&menu);
	}while (menu!=0);
	

	system("pause");
	system("cls");
return 0;
}

//fun��o para inicializa��o da lista do tipo produto
Produto* inicializar(){
	return NULL; // a constante NULL � parte da biblioteca <stdlib.h> 
}

//fun��o para inser��o de novos produtos
Produto* inserir(Produto* estoque){
	
	Produto* novo = (Produto*) malloc(sizeof(Produto));
	printf("\n---------------------------------------------------");
	printf("\n-------------Cadastro de Produto-------------------");
	printf("\n---------------------------------------------------\n");
	printf("\n Digite o c�digo de cadastro do produto:");
	scanf("%d",&novo->codigo);
	fflush(stdin);
	printf("\n Digite a descri��o do produto:");
	gets(novo->descricao);
	fflush(stdin);
	printf("\n Digite a quantidade do produto:");
	scanf("%d",&novo->quantidade);
	fflush(stdin);
	printf("\n Digite o valor do produto:");
	scanf("%f",&novo->valor);
	fflush(stdin);
	printf("\n\n");
	novo->proximo=estoque;
	return novo;
}

// fun��o para listar os produtos cadastrados
void relatorio(Produto* estoque){
	Produto* auxiliar;
	int i;
	printf("\n---------------------------------------------------");
	printf("\n------------Relat�rio de Produtos------------------");
	printf("\n---------------------------------------------------\n");
	for(auxiliar=estoque,i=0;auxiliar!=NULL;auxiliar=auxiliar->proximo,i++){
		printf("\n---------------------------------------------------");
		printf("\n----------------Produto [%d]------------------------",i+1);
		printf("\n---------------------------------------------------\n");
		printf("\nC�digo do Produto: %d",auxiliar->codigo);
		printf("\nDescri��o do Produto: %s",auxiliar->descricao);
		printf("\nQuantidade do Produto: %d",auxiliar->quantidade);
		printf("\nValor do Produto: R$ %.2f\n\n",auxiliar->valor);
	}
}

//fun��o de busca dentre os produtos cadastrados
void consultarProduto(Produto* estoque){
    Produto *auxiliar;
	int codigo;
	printf("\n---------------------------------------------------");
	printf("\n------------Consulta de Produtos-------------------");
	printf("\n---------------------------------------------------\n");
	printf("Digite o c�digo do produto:");
	scanf("%d",&codigo);

	for(auxiliar=estoque;auxiliar!=NULL;auxiliar=auxiliar->proximo){
	   if(auxiliar->codigo==codigo){
           relatorio(auxiliar);
           break;
       }
    }
    printf("\nProduto n�o cadastrado!\n\n");
}

//fun��o para remo��o de produtos do estoque

Produto* removerProduto(Produto *estoque){

	Produto* anterior;  //ponteiro que guarda a posi��o anterior
 	Produto* auxiliar; //lista auxiliar para busca do produto
	int codigo;

    printf("\n---------------------------------------------------");
	printf("\n------------Remo��o de Produtos--------------------");
	printf("\n---------------------------------------------------\n");
	printf("Digite o c�digo do produto:");
 	scanf("%d",&codigo);

	//procura o produto da lista e guarda referencia para o anterior
	for(anterior=NULL,auxiliar=estoque;auxiliar!=NULL&&auxiliar->codigo!=codigo;anterior=auxiliar,auxiliar=auxiliar->proximo){

	}

	//verifica se encontrou o produto
	if(auxiliar==NULL){
        printf("\nProduto n�o cadastrado!");
		return estoque;
	}

	//retira elemento do inicio da lista
	if(anterior==NULL){
		estoque=auxiliar->proximo;
	}
	
	//retira elemento do meio da lista
	else{
		anterior->proximo=auxiliar->proximo;
	}

	printf("\nProduto removido!\n");

	return estoque;
}


