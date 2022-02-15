#include<stdio.h>

int main(){
	double N1, N2, N3, N4, media, EF, MEF;
	scanf("%lf%lf%lf%lf",&N1,&N2,&N3,&N4);
	media=0.2*N1+0.3*N2+0.4*N3+0.1*N4;
	printf("Media: %.1lf\n",media);
	if (media>=7.0)
		printf("Aluno aprovado.\n");
	else if (media<5.0)
		printf("Aluno reprovado.\n");
			else if (media >= 5.0 && media <=6.9)
				{
				printf("Aluno em exame.\n");
				scanf ("%lf", &EF);
				printf("Nota do exame: %.1lf\n", EF);
				MEF = (EF+media)/2;
				if (MEF >= 5.0)
					{
					printf("Aluno aprovado.\n");
					printf ("Media final: %.1lf\n", MEF);
					}
					else 
					{
					printf("Aluno reprovado.\n");
					printf("Media final: %1.lf\n",MEF);
					}
				}
}
