#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Nível: Novato, Aventureiro e Mestre

// Estrutura para armazenar os dados da cidade
typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Cidade;

// Função para imprimir os dados de uma cidade
void imprimirCidade(Cidade c) {
    printf("Estado: %s\n", c.estado);
    printf("Código: %d\n", c.codigo);
    printf("Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

int main() {
    Cidade cidade1, cidade2;

    // ============================
    // NÍVEL NOVATO
    // ============================

    printf("=== Cadastro da Cidade 1 ===\n");
    printf("Estado: ");
    scanf(" %[^\n]", cidade1.estado);
    printf("Código: ");
    scanf("%d", &cidade1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade1.nome);
    printf("População: ");
    scanf("%d", &cidade1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &cidade1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &cidade1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &cidade1.pontosTuristicos);

    printf("\n=== Cadastro da Cidade 2 ===\n");
    printf("Estado: ");
    scanf(" %[^\n]", cidade2.estado);
    printf("Código: ");
    scanf("%d", &cidade2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade2.nome);
    printf("População: ");
    scanf("%d", &cidade2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &cidade2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &cidade2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &cidade2.pontosTuristicos);

    printf("\n--- Cartas Cadastradas ---\n");
    printf("\n>> Cidade 1\n");
    imprimirCidade(cidade1);
    printf("\n>> Cidade 2\n");
    imprimirCidade(cidade2);
    printf("\n");

    // ============================
    // NÍVEL AVENTUREIRO
    // ============================
    int opcao;
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    // ============================
    // NÍVEL MESTRE
    // ============================
    int usarSegundo = 0, segundaOpcao = 0;
    printf("Deseja escolher um segundo atributo para desempate? (1-Sim / 0-Não): ");
    scanf("%d", &usarSegundo);
    if (usarSegundo == 1) {
        printf("Escolha o segundo atributo (mesmas opções): ");
        scanf("%d", &segundaOpcao);
    }

    int vitoria1 = 0, vitoria2 = 0;
    float valor1, valor2;

    // Função de comparação baseada na opção escolhida
    switch (opcao) {
        case 1: valor1 = cidade1.populacao; valor2 = cidade2.populacao; break;
        case 2: valor1 = cidade1.area; valor2 = cidade2.area; break;
        case 3: valor1 = cidade1.pib; valor2 = cidade2.pib; break;
        case 4: valor1 = cidade1.pontosTuristicos; valor2 = cidade2.pontosTuristicos; break;
        case 5: valor1 = cidade1.populacao / cidade1.area; valor2 = cidade2.populacao / cidade2.area; break;
        default: 
            printf("Opção inválida!\n"); 
            return 1;
    }

    // Comparação do primeiro atributo
    if (opcao == 5) {
        if (valor1 < valor2) vitoria1++;
        else if (valor2 < valor1) vitoria2++;
    } else {
        if (valor1 > valor2) vitoria1++;
        else if (valor2 > valor1) vitoria2++;
    }

    // Comparação do segundo atributo (caso exista)
    if (usarSegundo && opcao != segundaOpcao) {
        switch (segundaOpcao) {
            case 1: valor1 = cidade1.populacao; valor2 = cidade2.populacao; break;
            case 2: valor1 = cidade1.area; valor2 = cidade2.area; break;
            case 3: valor1 = cidade1.pib; valor2 = cidade2.pib; break;
            case 4: valor1 = cidade1.pontosTuristicos; valor2 = cidade2.pontosTuristicos; break;
            case 5: valor1 = cidade1.populacao / cidade1.area; valor2 = cidade2.populacao / cidade2.area; break;
            default: 
                printf("Segunda opção inválida!\n"); 
                return 1;
        }

        if (segundaOpcao == 5) {
            if (valor1 < valor2) vitoria1++;
            else if (valor2 < valor1) vitoria2++;
        } else {
            if (valor1 > valor2) vitoria1++;
            else if (valor2 > valor1) vitoria2++;
        }
    }

    // Resultado final
    printf("\n--- Resultado da Comparação ---\n");
    if (vitoria1 > vitoria2) {
        printf("Cidade vencedora: %s\n", cidade1.nome);
    } else if (vitoria2 > vitoria1) {
        printf("Cidade vencedora: %s\n", cidade2.nome);
    } else {
        printf("Empate entre as cidades!\n");
    }

    return 0;
}
