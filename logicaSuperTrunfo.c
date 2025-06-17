#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta com os dados da cidade
typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

// Função para cadastrar os dados de uma carta
Carta cadastrarCarta() {
    Carta c;

    printf("\n--- Cadastro de Carta ---\n");

    // Leitura dos dados do utilizador
    printf("Estado: ");
    scanf(" %[^\n]", c.estado);
    printf("Código da carta: ");
    scanf(" %[^\n]", c.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", c.cidade);
    printf("População: ");
    scanf("%d", &c.populacao);
    printf("Área (km²): ");
    scanf("%f", &c.area);
    printf("PIB (milhões R$): ");
    scanf("%f", &c.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &c.pontosTuristicos);

    // Cálculo da densidade populacional
    c.densidade = (c.area != 0) ? (float)c.populacao / c.area : 0;

    return c;
}

// Função para mostrar os dados de uma carta
void exibirCarta(Carta c) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f milhões R$\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
}

// Função que mostra o menu e retorna o atributo selecionado
int menuComparacao() {
    int opcao;
    printf("\n--- Menu de Comparação ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função que compara dois atributos e determina a cidade vencedora
void compararCartas(Carta c1, Carta c2, int atributo) {
    printf("\n--- Resultado da Comparação ---\n");

    // Seleção do atributo com base na escolha do utilizador
    switch (atributo) {
        case 1: // População
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s (Maior população)\n", c1.cidade);
            else if (c1.populacao < c2.populacao)
                printf("Vencedor: %s (Maior população)\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        case 2: // Área
            if (c1.area > c2.area)
                printf("Vencedor: %s (Maior área)\n", c1.cidade);
            else if (c1.area < c2.area)
                printf("Vencedor: %s (Maior área)\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        case 3: // PIB
            if (c1.pib > c2.pib)
                printf("Vencedor: %s (Maior PIB)\n", c1.cidade);
            else if (c1.pib < c2.pib)
                printf("Vencedor: %s (Maior PIB)\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        case 4: // Pontos turísticos
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s (Mais pontos turísticos)\n", c1.cidade);
            else if (c1.pontosTuristicos < c2.pontosTuristicos)
                printf("Vencedor: %s (Mais pontos turísticos)\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        case 5: // Densidade populacional (menor vence)
            if (c1.densidade < c2.densidade)
                printf("Vencedor: %s (Menor densidade populacional)\n", c1.cidade);
            else if (c1.densidade > c2.densidade)
                printf("Vencedor: %s (Menor densidade populacional)\n", c2.cidade);
            else
                printf("Empate!\n");
            break;
        default:
            // Se o utilizador escolher um valor inválido
            printf("Opção inválida!\n");
    }
}

// Função principal
int main() {
    printf("=== Jogo de Comparação de Cartas de Cidades ===\n");

    // Cadastro de duas cartas
    Carta carta1 = cadastrarCarta();
    Carta carta2 = cadastrarCarta();

    // Exibir as cartas cadastradas
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Selecionar atributo e comparar
    int atributo = menuComparacao();
    compararCartas(carta1, carta2, atributo);

    return 0;
}
