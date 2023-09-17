#include <stdio.h>
#include <math.h>

int main() {
    int salario;
    int tempo;
    int reajuste;
    int bonus;

    printf("Digite o salario atual do funcionario: ");
    scanf("%d", &salario);

    printf("Digite o tempo de trabalho (em anos): ");
    scanf("%d", &tempo);

    if(salario <= 500){
        reajuste = (25/100) * salario;
    }
    else if(salario >= 501 && salario <= 1000){
        reajuste = (20/100) * salario;
    }
    else if(salario >= 1001 && salario <= 1500){
        reajuste = (15/100) * salario;
    }
    else if(salario >= 1501 && salario <= 2000){
        reajuste = (10/100) * salario;
    }
    else if(salario >= 2001){
        reajuste = 0;
    }
    if(tempo <= 1){
        bonus = 0;
    }
    if(tempo >= 1 && tempo <= 3){
        bonus = 100;
    }
    if(tempo >= 4 && tempo <= 6){
        bonus = 200;
    }
    if(tempo >= 7 && tempo <= 10){
        bonus = 300;
    }
    if(tempo >= 10){
        bonus = 500;
    }
    int salarioFinal = salario + reajuste;

    printf("O Salario final com reajuste e bonus é de: %d\n", salarioFinal);

}