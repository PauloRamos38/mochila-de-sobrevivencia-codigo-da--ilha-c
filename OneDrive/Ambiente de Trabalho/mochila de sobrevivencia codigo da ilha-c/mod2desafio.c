// Biblioteca para entrada e saída de dados (printf, scanf)
#include <stdio.h>

// Biblioteca para manipulação de strings (strcmp, strcpy)
#include <string.h>

// Biblioteca padrão do C
#include <stdlib.h>

// Definição da quantidade máxima de itens da mochila
#define MAX_ITENS 10
// Criação da struct Item
// A struct armazena os dados de cada item da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;
// Vetor de structs para armazenar até 10 itens
Item mochila[MAX_ITENS];
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// Vetor de structs para armazenar até 10 itens
// Variável global que controla a quantidade atual de itens
int totalItens = 0;
// Ponteiro inicial da lista encadeada
No* inicioLista = NULL;

// ======================================================
// Função para listar todos os itens cadastrados
// ======================================================
void listarItens() {

    // Verifica se a mochila está vazia
    if (totalItens == 0) {

        // Mensagem informando que não existem itens
        printf("\nA mochila esta vazia!\n");

        // Encerra a função
        return;
    }

    // Título da listagem
    printf("\n===== ITENS DA MOCHILA =====\n");

    // Laço para percorrer todos os itens cadastrados
    for (int i = 0; i < totalItens; i++) {

        // Exibe os dados do item
        printf("\nItem %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo do item (arma, municao, cura, etc.): %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}
// ======================================================
// Função para inserir um novo item
// ======================================================
void inserirItem() {

    // Verifica se a mochila já atingiu o limite
    if (totalItens >= MAX_ITENS) {

        // Mensagem de limite atingido
        printf("\nA mochila esta cheia! Limite de 10 itens.\n");

        // Encerra a função
        return;
    }

    // Solicita o nome do item
    printf("\nDigite o nome do item: ");

    // Lê o nome do item
    scanf(" %29[^\n]", mochila[totalItens].nome);

    // Solicita o tipo do item
    printf("Digite o tipo do item (arma, municao, cura, etc.): ");

    // Lê o tipo do item
    scanf(" %19[^\n]", mochila[totalItens].tipo);

    // Solicita a quantidade do item
    printf("Digite a quantidade do item: ");

    // Lê a quantidade do item
    scanf("%d", &mochila[totalItens].quantidade);

    // Incrementa a quantidade total de itens
    totalItens++;

    // Mensagem de sucesso
    printf("\nItem cadastrado com sucesso!\n");

    // Lista os itens após a operação
    listarItens();
}
// ======================================================
// Função para ordenar os itens da mochila por nome
// Utiliza o algoritmo Bubble Sort
// ======================================================
void ordenarItens() {

    Item temp;

    for (int i = 0; i < totalItens - 1; i++) {

        for (int j = 0; j < totalItens - 1 - i; j++) {

            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {

                temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }

    printf("\nItens ordenados com sucesso!\n");
}
// ======================================================
// Função para remover um item pelo nome
// ======================================================
void removerItem() {

    // Variável para armazenar o nome digitado
    char nomeBusca[30];

    // Variável de controle
    int encontrado = 0;

    // Solicita o nome do item
    printf("\nDigite o nome do item que deseja remover: ");

    // Lê o nome informado
    scanf(" %29[^\n]", nomeBusca);

    // Percorre o vetor procurando o item
    for (int i = 0; i < totalItens; i++) {

        // Compara o nome digitado com o nome do item
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            // Move os elementos uma posição para trás
            for (int j = i; j < totalItens - 1; j++) {

                // Copia o próximo item para a posição atual
                mochila[j] = mochila[j + 1];
            }

            // Diminui a quantidade total de itens
            totalItens--;

            // Marca como encontrado
            encontrado = 1;

            // Mensagem de sucesso
            printf("\nItem removido com sucesso!\n");

            // Interrompe o laço
            break;
        }
    }

    // Caso o item não seja encontrado
    if (encontrado == 0) {

        printf("\nItem nao encontrado!\n");
    }

    // Lista os itens após a operação
    listarItens();
}
// // ======================================================
// Função de busca sequencial
// ======================================================
void buscarItem() {

    // Variável para contar o número de comparações realizadas na busca
    int comparacoes = 0;

    // Variável para armazenar o nome procurado
    char nomeBusca[30];

    // Variável de controle
    int encontrado = 0;

    // Solicita o nome do item
    printf("\nDigite o nome do item que deseja buscar: ");

    // Lê o nome digitado
    scanf(" %29[^\n]", nomeBusca);

    // Percorre o vetor sequencialmente
    for (int i = 0; i < totalItens; i++) {

        comparacoes++;

        // Compara os nomes
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            // Exibe os dados do item encontrado
            printf("\n===== ITEM ENCONTRADO =====\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);

            printf("Comparacoes realizadas: %d\n", comparacoes);

            encontrado = 1;

            break;
        }
    }

    // Caso o item não exista
    if (encontrado == 0) {

        printf("\nItem nao encontrado!\n");
        printf("Comparacoes realizadas: %d\n", comparacoes);
    }
}

// ======================================================
// Função de busca binária
// ======================================================
void buscaBinaria() {
// Variável para armazenar o nome procurado
    ordenarItens();
    char nomeBusca[30];

    // Variáveis de controle
    int inicio = 0;
    int fim = totalItens - 1;
    int meio;

    // Contador de comparações
    int comparacoes = 0;

    // Solicita o nome do item
    printf("\nDigite o nome do item: ");

    // Lê o nome digitado
    scanf(" %29[^\n]", nomeBusca);

    // Executa a busca binária
    while (inicio <= fim) {

        comparacoes++;

        meio = (inicio + fim) / 2;

        int resultado = strcmp(mochila[meio].nome, nomeBusca);

        // Item encontrado
        if (resultado == 0) {

            printf("\n===== ITEM ENCONTRADO =====\n");
            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);

            printf("Comparacoes realizadas: %d\n", comparacoes);

            return;
        }

        // Busca na metade direita
        if (resultado < 0) {

            inicio = meio + 1;
        }

        // Busca na metade esquerda
        else {

            fim = meio - 1;
        }
    }

    // Caso não encontre
    printf("\nItem nao encontrado!\n");
    printf("Comparacoes realizadas: %d\n", comparacoes);
}
// ======================================================
// Função para listar itens da lista encadeada
// ======================================================
void listarItensLista() {

    // Ponteiro auxiliar
    No* atual = inicioLista;

    // Verifica lista vazia
    if (atual == NULL) {

        printf("\nLista vazia!\n");
        return;
    }

    printf("\n===== ITENS DA LISTA =====\n");

    // Percorre toda a lista
    while (atual != NULL) {

        printf("\nNome: %s\n", atual->dados.nome);
        printf("Tipo: %s\n", atual->dados.tipo);
        printf("Quantidade: %d\n", atual->dados.quantidade);

        atual = atual->proximo;
    }
}
// ======================================================
// Função de busca sequencial na lista encadeada
// ======================================================
void buscarItemLista() {

    // Ponteiro auxiliar
    No* atual = inicioLista;

    // Nome procurado
    char nomeBusca[30];

    // Contador de comparações
    int comparacoes = 0;

    // Controle
    int encontrado = 0;

    // Solicita nome
    printf("\nDigite o nome do item: ");
    scanf(" %29[^\n]", nomeBusca);

    // Percorre lista
    while (atual != NULL) {

        comparacoes++;
        // Compara nomes
        if (strcmp(atual->dados.nome, nomeBusca) == 0) {

            printf("\n===== ITEM ENCONTRADO =====\n");
            printf("Nome: %s\n", atual->dados.nome);
            printf("Tipo: %s\n", atual->dados.tipo);
            printf("Quantidade: %d\n", atual->dados.quantidade);

            printf("Comparacoes realizadas: %d\n", comparacoes);

            encontrado = 1;

            break;
        }

        atual = atual->proximo;
    }

    // Caso não encontre
    if (encontrado == 0) {

        printf("\nItem nao encontrado!\n");
        printf("Comparacoes realizadas: %d\n", comparacoes);
    }
}
// ======================================================
// Função para inserir item na lista encadeada
// ======================================================
void inserirItemLista() {

    // Cria novo nó dinamicamente
    No* novo = (No*) malloc(sizeof(No));

    // Verifica falha de memória
    if (novo == NULL) {

        printf("\nErro de memoria!\n");
        return;
    }

    // Lê os dados do item
    printf("\nDigite o nome do item: ");
    scanf(" %29[^\n]", novo->dados.nome);

    printf("Digite o tipo do item: ");
    scanf(" %19[^\n]", novo->dados.tipo);

    printf("Digite a quantidade: ");
    if (scanf("%d", &novo->dados.quantidade) != 1) novo->dados.quantidade = 0;

    // Insere no início da lista
    novo->proximo = inicioLista;
    inicioLista = novo;

    printf("\nItem inserido na lista!\n");
}
// ======================================================
// Função para remover item da lista encadeada
// ======================================================
void removerItemLista() {

    // Ponteiros auxiliares
    No* atual = inicioLista;
    No* anterior = NULL;

    // Nome procurado
    char nomeBusca[30];

    // Solicita nome
    printf("\nDigite o nome do item que deseja remover: ");
    scanf(" %29[^\n]", nomeBusca);

    // Procura item
    while (atual != NULL &&
           strcmp(atual->dados.nome, nomeBusca) != 0) {

        anterior = atual;
        atual = atual->proximo;
    }

    // Caso não encontre
    if (atual == NULL) {

        printf("\nItem nao encontrado!\n");
        return;
    }

    // Remove primeiro nó
    if (anterior == NULL) {

        inicioLista = atual->proximo;
    }

    // Remove do meio/final
    else {

        anterior->proximo = atual->proximo;
    }

    // Libera memória
    free(atual);

    printf("\nItem removido da lista!\n");
}
int main() {

    // Variável para armazenar a opção do menu
    int opcao;

    // Estrutura de repetição do menu principal
    do {

        // Exibe o menu do sistema
      printf("\n========== SISTEMA DE INVENTARIO ==========\n");
    printf("1 - Cadastrar item\n");
    printf("2 - Remover item\n");
    printf("3 - Listar itens\n");
    printf("4 - Buscar item\n");
    printf("5 - Ordenar itens\n");
    printf("6 - Busca binaria\n");
    printf("7 - Inserir item na lista\n");
    printf("8 - Listar itens da lista\n");
    printf("9 - Buscar item na lista\n");
    printf("10 - Remover item da lista\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");

        // Lê a opção digitada, ignorando espaços e quebras de linha pendentes
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); // Limpa buffer em caso de erro
            opcao = -1;
        }

        switch (opcao) {

            // Opção de cadastrar item
            case 1:
                inserirItem();
                break;

            // Opção de remover item
            case 2:
                removerItem();
                break;

            // Opção de listar itens
            case 3:
                listarItens();
                break;

            // Opção de buscar item
            case 4:
                buscarItem();
                break;

            // Opção de ordenar itens
            case 5:
                ordenarItens();
                break;
                // Opção de busca binária
            case 6:
                buscaBinaria();
                break;
            case 7:
                inserirItemLista();
                break;

            case 8:
                listarItensLista();
                break;

            case 9:
                buscarItemLista();
                break;

            case 10:
                removerItemLista();
                break;
            // Caso o usuário digite opção inválida
            // Opção de sair
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

    // Continua executando enquanto a opção for diferente de 0
    } while (opcao != 0);

    // Retorna 0 indicando sucesso
    printf("\nSistema finalizado com sucesso!\n");
    return 0;
}