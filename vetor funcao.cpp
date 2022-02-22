#include<stdio.h>

int cadastrarInteiros (int *vInt){
	int i, soma = 0;
	for(i=0;i<5;i++){
		scanf("%d", &vInt[i]);	
		soma += vInt[i];
	}
	return soma;
}
void imprimirInteiros(int *vInt){
	int i;
	for(i=0;i<5;i++)
		printf("%d\t", vInt[i]);
}

int main(){
	int vInt[5];
	
	printf("soma: %d", cadastrarInteiros(vInt));
	imprimirInteiros(vInt);
	

}






