#include <stdio.h>
#include <string.h>

//structs
struct financeiro {
    float salario, alimentacao, moradia, saldo, outros;
};

struct pessoa {
    char nome[50];
    int idade;
    char cidade[50];
    struct financeiro f;
};

//Funcoes
//OPCAO 2 RELACIONADO A REGISTROS
void ver_registros(const char *nome_pesquisado) {
    FILE *arquivo = fopen("bd.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    char linha[300];
    int numero_linha = 0;
    int encontrou = 0; // Flag para indicar se encontrou o nome pesquisado

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Verifique se a linha contém "--Fim--" para identificar o início de um registro
        if (strstr(linha, "--Fim--") != NULL) {
            if (encontrou) {
                printf("%s", linha); // Imprime a linha "--Fim--" do registro
                printf("===============================\n");
                printf("\n");
                encontrou = 0; // Reinicia a flag para o próximo registro
            }
        } else if (encontrou) {
            printf("%s", linha); // Imprime as linhas do registro
        } else if (strstr(linha, nome_pesquisado) != NULL) {
            printf("Registro #%d:\n", numero_linha);
            printf("===============================\n");
            printf("%s", linha); // Imprime a linha com o nome pesquisado
            encontrou = 1; // Define a flag para indicar que encontrou o nome pesquisado
        }
        numero_linha++;
    }

    // Fecha o arquivo quando terminar
    fclose(arquivo);
    int confirma;
    printf("Confirma visualizacao? 1 para sim\n");
    scanf("%d", &confirma);

    // Limpa a tela
    system("cls");
}

//RELACIONADO A OPCAO 1. CADASTRO
int numero_linha(FILE *arquivo) {
    // Move o ponteiro de arquivo para o início do arquivo
    fseek(arquivo, 0, SEEK_SET);
    char linha[300];
    int numero_linha = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, "--Fim--") != NULL) {
            numero_linha++;
        }
    }

    // Move o ponteiro de arquivo para o final do arquivo
    fseek(arquivo, 0, SEEK_END);

    return numero_linha;
}

void cadastrar() {
    struct pessoa p;
    printf("\nEscreva o seu nome:\n");
    scanf("%s", p.nome);
    printf("\nEscreva a sua idade:");
    scanf("%d", &p.idade);
    printf("\nCidade em que mora:");
    scanf("%s", p.cidade);
    printf("\nEscreva o seu salario bruto:\n");
    scanf("%f", &p.f.salario);
    printf("\nEscreva os seus gastos em alimentacao:");
    scanf("%f", &p.f.alimentacao);
    printf("\nEscreva os seus gastos em moradia:");
    scanf("%f", &p.f.moradia);
    printf("\nEscreva os seus gastos em outras atividades:");
    scanf("%f", &p.f.outros);
    p.f.saldo = p.f.salario - p.f.alimentacao - p.f.moradia - p.f.outros;

    FILE *arquivo = fopen("bd.txt", "a+");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    // Escreva os novos dados
    fprintf(arquivo, "%s\n", p.nome);
    fprintf(arquivo, "%d\n", p.idade);
    fprintf(arquivo, "%s\n", p.cidade);
    fprintf(arquivo, "%.2f\n", p.f.salario);
    fprintf(arquivo, "%.2f\n", p.f.alimentacao);
    fprintf(arquivo, "%.2f\n", p.f.moradia);
    fprintf(arquivo, "%.2f\n", p.f.outros);
    fprintf(arquivo, "%.2f\n", p.f.saldo);
    fprintf(arquivo, "--Fim--\n");

    // Fecha o arquivo quando terminar
    fclose(arquivo);
    //limpa a telinha :0
    system("cls");
}

//main
int main() {

    int op;
    int manter = 1;
    while (manter == 1){

        printf("-----CONTROLE FINANCEIRO-----\n");
        printf("Menu\n 1. Cadastro\n 2. Ver registros\n 3. Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                cadastrar();
                break;
            case 2:
                printf("Digite o nome a ser pesquisado: ");
                char nome_pesquisado[50];
                scanf("%s", nome_pesquisado);
                ver_registros(nome_pesquisado);
                break;
            case 3:
                manter = 0;
                break;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}
