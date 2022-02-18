/*Escreva um algoritmo que cadastre as vendas de uma loja.
Cada venda registra: nome do cliente, a quantidade
de itens, o valor total da compra e a forma de pagamento, 
se é cartão de crédito, débito ou dinheiro. 
O algoritmo deve, por meio de função e procedimento, 
registrar a venda e imprimir a venda.*/
//Vetor
#include<stdio.h>
typedef struct vendas{
	char nome[20];
	int quantidades;
	char pagamento[20];
	float valor;
	} vendas ;
	
	vendas cadastrarVendas();
	void imprimirVendas(struct vendas cliente);
	
	main(){
		vendas cliente1, cliente2;
			
		cliente1=cadastrarVendas();
		cliente2=cadastrarVendas();
		imprimirVendas(cliente1);
		imprimirVendas(cliente2);
	}
    vendas cadastrarVendas(){
		struct vendas venda;
		printf("Nome do cliente\n");
	    gets(venda.nome);
		printf("Quantidade de produtos\n");
		scanf("%d",&venda.quantidades);
		fflush(stdin);
		printf("Valor dos produtos\n");
		scanf("%f",&venda.valor);
		fflush(stdin);
		printf("Forma de pagamento\n");
		scanf("%s",&venda.pagamento);
		fflush(stdin);
		return venda;
	}
void imprimirVendas(vendas cliente){
		printf("nome= %s\n quantidade= %d\n valor= %f\n forma de pagamento= %s\n\n",cliente.nome,cliente.quantidades,cliente.valor,cliente.pagamento);
	}
		
