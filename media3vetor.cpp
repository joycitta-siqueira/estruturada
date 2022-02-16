#include<stdio.h>

int main(){
	double N1[3], N2[3], N3[3], N4[3], media[3], EF, MEF;
	char nome[3][30];
	int i;
	
	for(i=0;i<3;i++){ //preencheu os vetores e calculou a media
		printf("Digite o nome do aluno: ");
		fflush(stdin);
		fgets(nome[i], 30, stdin);
		printf("Digite as notas 1, 2, 3 e 4");
		scanf("%lf%lf%lf%lf",&N1[i],&N2[i],&N3[i],&N4[i]);
		media[i] = (N1[i]*2 + N2[i]*3 + N3[i]*4 + N4[i]*1)/10;		
	}
	for(i=0;i<3;i++) //imprimiu o vetor de medias
		printf("Media: %.1lf\t",media[i]);
	printf("\n");
	printf("\nNome\t\tN1\tN2\tN3\tN4\tMedia\tResultado\n");	
	for(i=0;i<3;i++){
		if (media[i]>=7.0)
			printf("%s\t\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\tAprovado.\n", nome[i], N1[i], N2[i], N3[i], N4[i], media[i]);
		else if (media[i]<5.0)
			printf("%s\t\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\tReprovado.\n", nome[i], N1[i], N2[i], N3[i], N4[i], media[i]);
				else if (media[i] >= 5.0 && media[i] <=6.9)
					printf("%s\t\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\tExame Final.\n", nome[i], N1[i], N2[i], N3[i], N4[i], media[i] );
		}
}
