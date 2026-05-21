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
struct Item {
    char nome[30];       // Nome do item
    char tipo[20];       // Tipo do item (arma, munição, cura, etc.)
    int quantidade;      // Quantidade do item
};

// Vetor de structs para armazenar até 10 itens
struct Item mochila[MAX_ITENS];

// Variável global que controla a quantidade atual de itens
int totalItens = 0;

// ======================================================
// Função para listar todos os itens cadastrados
// ======================================================
void listarItens() {

    // Verifica se a mochila está vazia
    if (totalItens == 0) {

        // Mensagem informando que não existem itens
        printf("\nA mochila esta vazia!\n");

        // Encer
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

    // Linha final de organização
    printf("============================\n");
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

    // Lê o nome do item (aceita espaços)
    if (fgets(mochila[totalItens].nome, sizeof(mochila[totalItens].nome), stdin) != NULL) {
        size_t ln = strlen(mochila[totalItens].nome);
        if (ln > 0 && mochila[totalItens].nome[ln-1] == '\n')
            mochila[totalItens].nome[ln-1] = '\0';
    }

    // Solicita o tipo do item
    printf("Digite o tipo do item (arma, municao, cura, etc.): ");

    // Lê o tipo do item (aceita espaços)
    if (fgets(mochila[totalItens].tipo, sizeof(mochila[totalItens].tipo), stdin) != NULL) {
        size_t lt = strlen(mochila[totalItens].tipo);
        if (lt > 0 && mochila[totalItens].tipo[lt-1] == '\n')
            mochila[totalItens].tipo[lt-1] = '\0';
    }

    // Solicita a quantidade do item
    printf("Digite a quantidade do item: ");

    // Lê a quantidade do item
    if (scanf("%d", &mochila[totalItens].quantidade) != 1) {
        // limpar entrada
        int _c; while ((_c = getchar()) != '\n' && _c != EOF) {}
        printf("Quantidade invalida. Operacao cancelada.\n");
        return;
    }
    // limpar newline restante
    int _c; while ((_c = getchar()) != '\n' && _c != EOF) {}

    // Incrementa a quantidade total de itens
    totalItens++;

    // Mensagem de sucesso
    printf("\nItem cadastrado com sucesso!\n");

    // Lista os itens após a operação
    listarItens();
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

    // Lê o nome informado (aceita espaços)
    if (fgets(nomeBusca, sizeof(nomeBusca), stdin) != NULL) {
        size_t ln = strlen(nomeBusca);
        if (ln > 0 && nomeBusca[ln-1] == '\n') nomeBusca[ln-1] = '\0';
    }

    // Percorre o vetor procurando o item
    for (int i = 0; i < totalItens; i++) {

        // Compara o nome digitado com o nome do item
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            // Salva os dados do item que será removido
            struct Item removido = mochila[i];

            // Exibe os dados do item removido
            printf("\n===== ITEM REMOVIDO =====\n");
            printf("Nome: %s\n", removido.nome);
            printf("Tipo: %s\n", removido.tipo);
            printf("Quantidade: %d\n", removido.quantidade);

            // Move os elementos uma posição para trás
            for (int j = i; j < totalItens - 1; j++) {
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
// ======================================================
// Função de busca sequencial
// ======================================================
void buscarItem() {

    // Variável para armazenar o nome procurado
    char nomeBusca[30];

    // Variável de controle
    int encontrado = 0;

    // Solicita o nome do item
    printf("\nDigite o nome do item que deseja buscar: ");

    // Lê o nome digitado (aceita espaços)
    if (fgets(nomeBusca, sizeof(nomeBusca), stdin) != NULL) {
        size_t ln = strlen(nomeBusca);
        if (ln > 0 && nomeBusca[ln-1] == '\n') nomeBusca[ln-1] = '\0';
    }

    // Percorre o vetor sequencialmente
    for (int i = 0; i < totalItens; i++) {

        // Compara os nomes
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            // Exibe os dados do item encontrado
            printf("\n===== ITEM ENCONTRADO =====\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);

            encontrado = 1;

            break;
        }
    }

    // Caso o item não exista
    if (encontrado == 0) {

        printf("\nItem nao encontrado!\n");
    }

    // Lista os itens após a operação
    listarItens();
}

// ======================================================
// Função principal do programa
// ======================================================
int mod1_main() {

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
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        // Lê a opção digitada, ignorando espaços e quebras de linha pendentes
        if (scanf("%d", &opcao) != 1) {
            // limpar entrada e sair
            int _c; while ((_c = getchar()) != '\n' && _c != EOF) {}
            printf("\nEntrada invalida!\n");
            break;
        }
        // limpar newline remanescente para que fgets funcione nas próximas leituras
        int _c; while ((_c = getchar()) != '\n' && _c != EOF) {}
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

            // Opção de sair
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            // Caso o usuário digite opção inválida
            default:
                printf("\nOpcao invalida!\n");
        }

    // Continua executando enquanto a opção for diferente de 0
    } while (opcao != 0);

    // Retorna 0 indicando sucesso
    return 0;
}