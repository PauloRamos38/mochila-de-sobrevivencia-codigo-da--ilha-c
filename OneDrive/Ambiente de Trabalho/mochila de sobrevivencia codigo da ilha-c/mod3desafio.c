// ======================================================
// DESAFIO FREE FIRE - NÍVEL MESTRE
// Sistema de organização de componentes da torre
// ======================================================
//
// Objetivo:
// Desenvolver um sistema avançado de inventário utilizando
// diferentes algoritmos de ordenação e busca binária.
//
// O programa permite:
// - Cadastrar componentes da torre;
// - Ordenar os componentes por diferentes critérios;
// - Comparar desempenho dos algoritmos;
// - Realizar busca binária otimizada;
// - Exibir número de comparações e tempo de execução.
//
// Algoritmos utilizados:
// - Bubble Sort  -> Ordenação por nome;
// - Insertion Sort -> Ordenação por tipo;
// - Selection Sort -> Ordenação por prioridade;
// - Busca Binária -> Busca rápida por nome.
//
// Estrutura utilizada:
// Struct Componente contendo:
// - nome;
// - tipo;
// - prioridade.
//
// Autor: Paulo Ramos
// Linguagem: C
// ======================================================

// Biblioteca para entrada e saída de dados
#include <stdio.h>

// Biblioteca padrão da linguagem C
#include <stdlib.h>

// Biblioteca para manipulação de strings
#include <string.h>

// Biblioteca para medição de tempo
#include <time.h>

// ======================================================
// Definição da quantidade máxima de componentes
// ======================================================
#define MAX_COMPONENTES 20

// ======================================================
// Struct Componente
// Armazena os dados dos componentes da torre
// ======================================================
typedef struct {

    char nome[30];
    char tipo[20];
    int prioridade;

} Componente;

// ======================================================
// Vetor de componentes
// ======================================================
Componente componentes[MAX_COMPONENTES];

// ======================================================
// Variável que controla a quantidade atual
// de componentes cadastrados
// ======================================================
int totalComponentes = 0;

// ======================================================
// Protótipos das funções
// ======================================================

// Função para cadastrar componentes
void cadastrarComponentes();

// Função para exibir componentes cadastrados
void mostrarComponentes();

// Função Bubble Sort por nome
void bubbleSortNome();

// Função Insertion Sort por tipo
void insertionSortTipo();

// Função Selection Sort por prioridade
void selectionSortPrioridade();

// Função de busca binária por nome
void buscaBinariaPorNome();

// ======================================================
// Variáveis para medição de tempo
// ======================================================
clock_t inicio, fim;

// Variável que armazena o tempo gasto
double tempoGasto;

// ======================================================
// Variável global para contar comparações
// realizadas pelos algoritmos
// ======================================================
int comparacoes = 0;
// ======================================================
// Função para cadastrar componentes
// ======================================================
void cadastrarComponentes() {

    // Verifica limite máximo
    if (totalComponentes >= MAX_COMPONENTES) {

        printf("\nLimite maximo atingido!\n");
        return;
    }

    printf("\nDigite o nome do componente: ");
    fgets(componentes[totalComponentes].nome, 30, stdin);
    componentes[totalComponentes].nome[strcspn(componentes[totalComponentes].nome, "\n")] = '\0';

    printf("Digite o tipo do componente: ");
    printf("(Estrutural, Eletronico, Energia): ");
    fgets(componentes[totalComponentes].tipo, 20, stdin);
    componentes[totalComponentes].tipo[strcspn(componentes[totalComponentes].tipo, "\n")] = '\0';

    printf("Digite a prioridade (1 a 10): ");
    scanf("%d", &componentes[totalComponentes].prioridade);

    getchar();

    totalComponentes++;

    printf("\nComponente cadastrado com sucesso!\n");
}

// ======================================================
// Função para mostrar os componentes
// ======================================================
void mostrarComponentes() {

    if (totalComponentes == 0) {

        printf("\nNenhum componente cadastrado!\n");
        return;
    }

    printf("\n===== COMPONENTES CADASTRADOS =====\n");

    for (int i = 0; i < totalComponentes; i++) {

        printf("\nComponente %d\n", i + 1);
        printf("Nome: %s\n", componentes[i].nome);
        printf("Tipo: %s\n", componentes[i].tipo);
        printf("Prioridade: %d\n", componentes[i].prioridade);
    }
}

// ======================================================
// Bubble Sort por nome
// ======================================================
void bubbleSortNome() {

    comparacoes = 0;

    inicio = clock();

    Componente temp;

    for (int i = 0; i < totalComponentes - 1; i++) {

        for (int j = 0; j < totalComponentes - 1 - i; j++) {

            comparacoes++;

            if (strcmp(componentes[j].nome,
                       componentes[j + 1].nome) > 0) {

                temp = componentes[j];
                componentes[j] = componentes[j + 1];
                componentes[j + 1] = temp;
            }
        }
    }

    fim = clock();

    tempoGasto =
    ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nOrdenacao por nome realizada!\n");
    printf("Comparacoes: %d\n", comparacoes);
    printf("Tempo: %f segundos\n", tempoGasto);
}

// ======================================================
// Insertion Sort por tipo
// ======================================================
void insertionSortTipo() {

    comparacoes = 0;

    inicio = clock();

    Componente chave;
    int j;

    for (int i = 1; i < totalComponentes; i++) {

        chave = componentes[i];
        j = i - 1;

        while (j >= 0 &&
               strcmp(componentes[j].tipo,
                      chave.tipo) > 0) {

            comparacoes++;

            componentes[j + 1] = componentes[j];
            j--;
        }

        componentes[j + 1] = chave;
    }

    fim = clock();

    tempoGasto =
    ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nOrdenacao por tipo realizada!\n");
    printf("Comparacoes: %d\n", comparacoes);
    printf("Tempo: %f segundos\n", tempoGasto);
}

// ======================================================
// Selection Sort por prioridade
// ======================================================
void selectionSortPrioridade() {

    comparacoes = 0;

    inicio = clock();

    Componente temp;
    int menor;

    for (int i = 0; i < totalComponentes - 1; i++) {

        menor = i;

        for (int j = i + 1; j < totalComponentes; j++) {

            comparacoes++;

            if (componentes[j].prioridade <
                componentes[menor].prioridade) {

                menor = j;
            }
        }

        temp = componentes[i];
        componentes[i] = componentes[menor];
        componentes[menor] = temp;
    }

    fim = clock();

    tempoGasto =
    ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nOrdenacao por prioridade realizada!\n");
    printf("Comparacoes: %d\n", comparacoes);
    printf("Tempo: %f segundos\n", tempoGasto);
}

// ======================================================
// Busca binária por nome
// ======================================================
void buscaBinariaPorNome() {

    char busca[30];

    int inicioBusca = 0;
    int fimBusca = totalComponentes - 1;
    int meio;

    comparacoes = 0;

    bubbleSortNome();

    printf("\nDigite o nome do componente: ");
    fgets(busca, 30, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    while (inicioBusca <= fimBusca) {

        comparacoes++;

        meio = (inicioBusca + fimBusca) / 2;

        int resultado =
        strcmp(componentes[meio].nome, busca);

        if (resultado == 0) {

            printf("\n===== COMPONENTE ENCONTRADO =====\n");
            printf("Nome: %s\n", componentes[meio].nome);
            printf("Tipo: %s\n", componentes[meio].tipo);
            printf("Prioridade: %d\n",
                   componentes[meio].prioridade);

            printf("Comparacoes: %d\n",
                   comparacoes);

            return;
        }

        if (resultado < 0) {

            inicioBusca = meio + 1;
        }

        else {

            fimBusca = meio - 1;
        }
    }

    printf("\nComponente nao encontrado!\n");
    printf("Comparacoes: %d\n", comparacoes);
}

// ======================================================
// Função principal
// ======================================================
int main() {

    int opcao;

    do {

        printf("\n========== NIVEL MESTRE ==========\n");
        printf("Status de ordenacao por nome: nao ordenados\n");
        printf("1 - Adicionar componentes\n");
        printf("2 - Mostrar componentes\n");
        printf("3 - Ordenar por nome\n");
        printf("4 - Ordenar por tipo\n");
        printf("5 - Ordenar por prioridade\n");
        printf("6 - Busca binaria por nome\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        getchar();

        switch (opcao) {

            case 1:
                cadastrarComponentes();
                break;

            case 2:
                mostrarComponentes();
                break;

            case 3:
                bubbleSortNome();
                mostrarComponentes();
                break;

            case 4:
                insertionSortTipo();
                mostrarComponentes();
                break;

            case 5:
                selectionSortPrioridade();
                mostrarComponentes();
                break;

            case 6:
                buscaBinariaPorNome();
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}