#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//declaração da struct que age como uma lista encadeada
struct dados_mensais {
    char data[6];
    float salario;
    float gastos;
    struct dados_mensais* proximo;
};

//declaração da struct para Dados de usuário único, vai receber a struct anterior.

struct usuarios{
    int cod;
    int senha;
    char nome[50];
    struct dados_mensais* dados_usuario;
};

//declaração de funções


//função de cadastro de usuario que retorna a struct usuario(de usuarios) preenchida.
//para chamar essa função no código dps usa: "struct usuarios novoUsuario = cadastro();"
struct usuarios cadastro(){
    struct usuarios usuario;

    // Alocar memória para a struct dados_mensais
    usuario.dados_usuario = (struct dados_mensais*)malloc(sizeof(struct dados_mensais));

    // Perguntas para realizar o cadastro.
    printf("Poderia fornecer seu nome: ");
    scanf("%s", usuario.nome);
    printf("Crie uma senha: ");
    scanf("%d", &usuario.senha);
    printf("Forneça a Data de registro desejada: ");
    scanf("%s", usuario.dados_usuario->data);//usa a seta para acessar ponteiros
    printf("Diga o salário referente à data: ");
    scanf("%f", &usuario.dados_usuario->salario);//usa a seta para acessar ponteiros
    printf("Diga os gastos referentes à data: ");
    scanf("%f", &usuario.dados_usuario->gastos);//usa a seta para acessar ponteiros

    return usuario;
}

int main(){

    struct usuarios novoUsuario = cadastro();

    return 0;
}

