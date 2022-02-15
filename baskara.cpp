#include<stdio.h> //biblioteca para o printf e scanf
#include<math.h> //biblioteca matemática

int main(){
	double a, b, c, x1, x2, delta;
	
	printf("Digite os valores de a, b, c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	if (a == 0) 
	printf("impossivel calcular");
		else {
			delta = pow(b,2) - 4 * a * c;
			x1 = (-(b) + sqrt(delta))/(2*a);
			x2 = (-(b) - sqrt(delta))/(2*a);
			printf("X1 = %.3lf e X2 = %.1lf\n", x1, x2);
		}	
		
	return 0;
}
