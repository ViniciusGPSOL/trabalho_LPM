#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura para armazenar datas
struct ListaData {
    char data[10]; // Assumindo que as datas têm no máximo 10 caracteres
    struct ListaData* proximo;
};

// Definindo a estrutura para armazenar saldos
struct ListaSaldo {
    float saldo;
    struct ListaSaldo* proximo;
};

// Estrutura principal para dados financeiros
struct DadosFinanceiros {
    struct ListaData* datas;
    struct ListaSaldo* saldos;
};

// Função para adicionar uma data à lista
void adicionarData(struct DadosFinanceiros* dados, const char* data) {
    struct ListaData* novaData = (struct ListaData*)malloc(sizeof(struct ListaData));
    snprintf(novaData->data, sizeof(novaData->data), "%s", data);
    novaData->proximo = dados->datas;
    dados->datas = novaData;
}

// Função para adicionar um saldo à lista
void adicionarSaldo(struct DadosFinanceiros* dados, float saldo) {
    struct ListaSaldo* novoSaldo = (struct ListaSaldo*)malloc(sizeof(struct ListaSaldo));
    novoSaldo->saldo = saldo;
    novoSaldo->proximo = dados->saldos;
    dados->saldos = novoSaldo;
}

int main() {
    // Criando a estrutura de dados financeiros
    struct DadosFinanceiros dados;
    dados.datas = NULL;
    dados.saldos = NULL;

    // Adicionando dados à lista de datas
    adicionarData(&dados, "10/01");
    adicionarData(&dados, "10/02");

    // Adicionando dados à lista de saldos
    adicionarSaldo(&dados, 1000.0);
    adicionarSaldo(&dados, 1500.0);

    // Acessando os dados
    struct ListaData* dataAtual = dados.datas;
    struct ListaSaldo* saldoAtual = dados.saldos;

    while (dataAtual != NULL && saldoAtual != NULL) {
        printf("Data: %s, Saldo: %.2f\n", dataAtual->data, saldoAtual->saldo);
        dataAtual = dataAtual->proximo;
        saldoAtual = saldoAtual->proximo;
    }

    // Liberando a memória alocada
    while (dados.datas != NULL) {
        struct ListaData* temp = dados.datas;
        dados.datas = dados.datas->proximo;
        free(temp);
    }
    while (dados.saldos != NULL) {
        struct ListaSaldo* temp = dados.saldos;
        dados.saldos = dados.saldos->proximo;
        free(temp);
    }

    return 0;
}
