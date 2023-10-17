#include <stdio.h>
#include "sim_purch.h"
#include "search_debt.h"
#include "register_client.h"
#include "fill_stock.h"
#include "search_stock.h"

// O objetivo do programa é simular um sistema de super-mercado.

// Código das ações para o menu.
typedef enum {
    SIM_PURCH, // Simular compra.
    REG_CLIENT, // Registrar cliente.
    SEARCH_DEBT, // Pesquisar débito de um cliente.
    FILL_STOCK, // Reabastecer estoque.
    SEARCH_STOCK, // Pesquisar estoque.
    PAY_DEBT, // Pagar débito de um cliente.
    FORGV_DEBT, // Perdoar débito de um cliente aleatório.
    EXIT_ACTION // Sair.
} action_code;

int main()
{
    double PRODUCTS_PRICE[NUM_PRODUCTS]; // Preços dos produtos.

    int PRODUCTS_STOCK[NUM_PRODUCTS]; // Estoque dos produtos.

    // Dívida dos clientes.
    double CLIENTS_DEBT[NUM_CLIENTS];

    // Inicializa o vetor de dívidas dos clientes.
    for (int i = 0; i < NUM_CLIENTS; i++) {
        CLIENTS_DEBT[i] = -1;
    }

    // Desconto de cada forma de pagamento.
    const double PAYMENT_DISCOUNT[4] = {
        0.10, // Dinheiro.
        0.05, // Cartão (débito ou crédito).
        0.12, // Pix.
        0 // Crediário.
    };

    // Definindo os preços dos produtos.
    PRODUCTS_PRICE[0] = 0.50; // Pão.
    PRODUCTS_PRICE[1] = 3.50; // Leite.
    PRODUCTS_PRICE[2] = 5.00; // Café.
    PRODUCTS_PRICE[3] = 10.00; // Arroz.
    PRODUCTS_PRICE[4] = 8.00; // Feijão.
    PRODUCTS_PRICE[5] = 3.00; // Açúcar.
    PRODUCTS_PRICE[6] = 2.00; // Sal.
    PRODUCTS_PRICE[7] = 5.00; // Óleo.
    PRODUCTS_PRICE[8] = 3.00; // Farinha.
    PRODUCTS_PRICE[9] = 30.00; // Carne.

    // Definindo os estoques dos produtos.
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        PRODUCTS_STOCK[i] = 100;
    }

    action_code action = 0; // Código da ação escolhida pelo usuário.

    // Loop principal do programa.
    while (action != EXIT_ACTION) {
        // Menu de opções.
        printf("Escolha uma opção:\n");
        printf("[%d] - Simular compra.\n", SIM_PURCH);
        printf("[%d] - Registrar cliente.\n", REG_CLIENT);
        printf("[%d] - Pesquisar débito de um cliente.\n", SEARCH_DEBT);
        printf("[%d] - Reabastecer estoque.\n", FILL_STOCK);
        printf("[%d] - Pesquisar estoque.\n", SEARCH_STOCK);
        printf("[%d] - Pagar débito de um cliente aleatório.\n", PAY_DEBT);
        printf("[%d] - Perdoar débito de um cliente aleatório.\n", FORGV_DEBT);
        printf("[%d] - Sair.\n", EXIT_ACTION);

        // Lê a ação escolhida pelo usuário.
        printf("Selecione uma opção: ");
        scanf("%d", &action);

        // Executa a ação escolhida pelo usuário.
        switch (action) {
            case SIM_PURCH:
                sim_purch((const double *) &PRODUCTS_PRICE, (int *) &PRODUCTS_STOCK,
                          (const double *) &PAYMENT_DISCOUNT, (double *) &CLIENTS_DEBT);
                break;
            case REG_CLIENT:
                register_client((double *) &CLIENTS_DEBT);
                break;
            case SEARCH_DEBT:
                search_debt((const float *) &CLIENTS_DEBT);
                break;
            case FILL_STOCK:
                fill_stock(PRODUCTS_STOCK);
                break;
            case SEARCH_STOCK:
                search_stock(PRODUCTS_STOCK);
                break;
            case PAY_DEBT:
                printf("Pagar débito de um cliente.\n");
                break;
            case FORGV_DEBT:
                printf("Perdoar débito de um cliente aleatório.\n");
                break;
            case EXIT_ACTION:
                printf("Sair.\n");
                return 0;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    printf("Fim do programa.\n");
    return 0;
}
