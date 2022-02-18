#include<stdio.h>

void apresentarClassificacao (){
	printf("IDADE <= 10 CRIANCA\n10 > IDADE < 18 ADOLESCENTE\n18 >= IDADE < 25 JOVEM\n25 >= IDADE <= 58 ADULTO\nIDADE > 58 IDOSO\n");	
}

int calcularIdade (int anoAtual, int anoNascimento){
	printf("Idade %d\n", anoAtual - anoNascimento);
	return  anoAtual - anoNascimento;
}

void obterNivel(int idade){
	apresentarClassificacao();
	switch (idade)    {
        case 0 ... 10:
            printf("Crianca!");
            break;
        case 11 ... 18:
            printf("Adolescente!");
            break;
        case 19 ... 25:
            printf("Jovem!");
            break;
        case 26 ... 58:
            printf("Adulto!");
            break;
        case 59 ... 100:
            printf("Idoso!");
           break;
		case 101 ... 120: 
			printf("Zumbi!\n");  
			break;
    default:
        printf("invalido!\n");
      }
}

int main(){
	
	int anoAtual, anoNascimento;
	printf("Digite o ano de nascimento e o ano atual: ");
	scanf("%d%d", &anoNascimento, &anoAtual);
	obterNivel(calcularIdade(anoAtual, anoNascimento));
	
}
