#include <stdio.h>
#include <string.h>

struct financeiro{
        float salario, alimentacao, moradia, saldo, outros;
};

struct pessoa{
        char nome[50];
        int idade;
        char cidade[50];
        struct financeiro f;
};

int main(){

printf("-----CONTROLE FINANCEIRO-----");

printf("Menu\n 1. Cadastro\n 2.Calculo financeiro\n 3. Sair");

int op;

switch op{

scanf("%d", &op);

    case 1: //funcao de cadastrar
        cadastrar();
    break;
    case 2: //acessar o registro

    break;
}

return 0;
}

void cadastrar(){

struct pessoa p;
    printf("\nEscreva o seu nome:\n");
    scanf("%s", & p.nome);
    printf("\nEscreva a sua idade:");
    scanf("%d", & p.idade);
    printf("\nCidade em que mora:");
    scanf("%s", & p.cidade);
    printf("\nEscreva o seu salario bruto:\n");
    scanf("%f", & p.f.salario);
    printf("\nEscreva os seus gastos em alimentaçao:");
    scanf("%f", & p.f.alimentacao);
    printf("\nEscreva os seus gastos em moradia:");
    scanf("%f", & p.f.moradia);
    printf("\nEscreva os seus gastos em outras atividades:");
    scanf("%f", & p.f.outros);
    p.f.saldo = p.f.salario - p.f.alimentacao - p.f.moradia - p.f.outros;
    printf("\nsaldo atual: %f", p.f.saldo);

}
