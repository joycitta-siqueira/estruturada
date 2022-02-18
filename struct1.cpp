//Q6 - Struct
#include<stdio.h>
#include<string.h>
typedef struct  {
	char rua[10], bairro[10], cidade[10], estado[10], cep[10];
} endereco;
typedef struct {
	char nome[10], estadoCivil, identidade[10], cpf[11], telefone[10], sexo[3];
	double salario;
	int idade;
    endereco end;
} cadastro;
int cadastrarClientes(cadastro *clientes, int indice);
void imprimirClientes(cadastro *clientes, int indice);
void clienteMaiorIdade(cadastro *clientes, int indice);
void imprimirSexoMasculino(cadastro *clientes, int indice);
int main (){
	int indice = 0, opcao;
	cadastro clientes[5];
	do{
	indice = cadastrarClientes(clientes, indice);
	printf("Deseja cadastrar mais clientes? 1 - sim");
	scanf("%d", &opcao);
	if (indice>=5)
	 printf("Nao e possivel novos cadastros!");
    }while(opcao==1 && indice<5);
    
    imprimirClientes(clientes, indice);
    clienteMaiorIdade(clientes, indice);
    imprimirSexoMasculino(clientes, indice);
	
	
}

int cadastrarClientes(cadastro *clientes, int indice){
	fflush(stdin);
	printf("Digite nome: ");
	fgets(clientes[indice].nome, 10, stdin);
	fflush(stdin);
	printf("Digite idade: ");
	scanf("%d", &clientes[indice].idade);
	fflush(stdin);
	printf("Digite sexo: ");
	fgets(clientes[indice].sexo, 3, stdin);
	fflush(stdin);
	printf("Digite a cidade: ");
	fgets(clientes[indice].end.cidade, 10, stdin);
	fflush(stdin);
	indice++;
	return indice;	
}

void imprimirClientes(cadastro *clientes, int indice){
	int i;
	for (i=0;i<indice;i++)
		printf("Nome: %s\tCidade: %s\n", clientes[i].nome, clientes[i].end.cidade);
}

void clienteMaiorIdade(cadastro *clientes, int indice){
	int i, maiorIdade = -1, cliente;
	for (i=0;i<indice;i++){
		if (clientes[i].idade > maiorIdade){
			maiorIdade = clientes[i].idade;
			cliente = i;
		}
	}
	printf("Cliente com maior idade: %s - %d anos", clientes[cliente].nome, maiorIdade);
}

void imprimirSexoMasculino(cadastro *clientes, int indice){
	int i;
	for (i=0;i<indice;i++){
		if(strcmp(clientes[i].sexo,"Mas")==0){
			printf("Nome: %s\tSexo: %s\n", clientes[i].nome, clientes[i].sexo);	
		}
	}
		
}
