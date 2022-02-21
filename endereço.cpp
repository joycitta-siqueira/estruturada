#include<stdio.h>

int main(){
	int i = 0;
	int vInt[5]={0};
	double vDouble[5]={0};
	char vChar[5]={0};
	
	for(i=0;i<5;i++)
		printf("%d\t", &vInt[i]);
	printf("\n");
	for(i=0;i<5;i++)
		printf("%d\t", &vDouble[i]);
	printf("\n");
	for(i=0;i<5;i++)
		printf("%d\t", &vChar[i]);

}
