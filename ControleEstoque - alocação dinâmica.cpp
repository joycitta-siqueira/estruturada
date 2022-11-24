#include<stdio.h>
#include<locale.h>
#include <cstdlib>
#include<string.h>

// estrutura para a criação da lista, formada por produtos.
typedef struct produto{
	int codigo, quantidade;
	char descricao[50];
	float valor;
	struct produto *proximo;//ponteiro do tipo produto
} Produto;

//declaração das funções
Produto* inicializar(); 
Produto* inserir(Produto*);
void relatorio(Produto*);
void consultarProduto(Produto*);
Produto* removerProduto(Produto*);
Produto* consultarVolume(Produto*);

main(){
//configuração do idioma
setlocale(LC_ALL,"Portuguese");
int menu;
//lista para a alocação de produtos
Produto* estoque; //cria a lista estoque, do tipo produto
estoque = inicializar(); //inicializa a lista vazia
//personalização de design
system("color fc");
    //menu
	do{
	//exibição e leitura de menu
	printf("\n---------------------------------------------------");
	printf("\n-------------Controle de Estoque-------------------");
	printf("\n---------------------------------------------------\n");
	printf("1- Cadastrar Produtos\n");
	printf("2- Consultar Produtos\n");
	printf("3- Relatório de Produtos\n");
	printf("4- Remover Produtos\n");
	printf("0- Sair\n");
	printf("\n---------------------------------------------------\n");
	printf("Digite a opção desejada:\n");
	scanf("%d",&menu);
	switch(menu){
		case 1: estoque=inserir(estoque); break;
		case 2: consultarProduto(estoque); break;
		case 3: relatorio(estoque); break;
	 	case 4: estoque=removerProduto(estoque); break;
		case 0: return 0; //finaliza o programa
		default: printf("\nOpção inválida!\n\n");
  	}
	printf("Deseja realizar outra operacao: qualquer valor diferente de zero\n");
	scanf("%d",&menu);
	}while (menu!=0);
	

	system("pause");
	system("cls");
return 0;
}

//função para inicialização da lista do tipo produto
Produto* inicializar(){
	return NULL; // a constante NULL é parte da biblioteca <stdlib.h> 
}

//função para inserção de novos produtos
Produto* inserir(Produto* estoque){
	
	Produto* novo = (Produto*) malloc(sizeof(Produto));
	printf("\n---------------------------------------------------");
	printf("\n-------------Cadastro de Produto-------------------");
	printf("\n---------------------------------------------------\n");
	printf("\n Digite o código de cadastro do produto:");
	scanf("%d",&novo->codigo);
	fflush(stdin);
	printf("\n Digite a descrição do produto:");
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

// função para listar os produtos cadastrados
void relatorio(Produto* estoque){
	Produto* auxiliar;
	int i;
	printf("\n---------------------------------------------------");
	printf("\n------------Relatório de Produtos------------------");
	printf("\n---------------------------------------------------\n");
	for(auxiliar=estoque,i=0;auxiliar!=NULL;auxiliar=auxiliar->proximo,i++){
		printf("\n---------------------------------------------------");
		printf("\n----------------Produto [%d]------------------------",i+1);
		printf("\n---------------------------------------------------\n");
		printf("\nCódigo do Produto: %d",auxiliar->codigo);
		printf("\nDescrição do Produto: %s",auxiliar->descricao);
		printf("\nQuantidade do Produto: %d",auxiliar->quantidade);
		printf("\nValor do Produto: R$ %.2f\n\n",auxiliar->valor);
	}
}

//função de busca dentre os produtos cadastrados
void consultarProduto(Produto* estoque){
    Produto *auxiliar;
	int codigo;
	printf("\n---------------------------------------------------");
	printf("\n------------Consulta de Produtos-------------------");
	printf("\n---------------------------------------------------\n");
	printf("Digite o código do produto:");
	scanf("%d",&codigo);

	for(auxiliar=estoque;auxiliar!=NULL;auxiliar=auxiliar->proximo){
	   if(auxiliar->codigo==codigo){
           relatorio(auxiliar);
           break;
       }
    }
    printf("\nProduto não cadastrado!\n\n");
}

//função para remoção de produtos do estoque

Produto* removerProduto(Produto *estoque){

	Produto* anterior;  //ponteiro que guarda a posição anterior
 	Produto* auxiliar; //lista auxiliar para busca do produto
	int codigo;

    printf("\n---------------------------------------------------");
	printf("\n------------Remoção de Produtos--------------------");
	printf("\n---------------------------------------------------\n");
	printf("Digite o código do produto:");
 	scanf("%d",&codigo);

	//procura o produto da lista e guarda referencia para o anterior
	for(anterior=NULL,auxiliar=estoque;auxiliar!=NULL&&auxiliar->codigo!=codigo;anterior=auxiliar,auxiliar=auxiliar->proximo){

	}

	//verifica se encontrou o produto
	if(auxiliar==NULL){
        printf("\nProduto não cadastrado!");
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


