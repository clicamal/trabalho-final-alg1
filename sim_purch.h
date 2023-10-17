//
// Created by Tarcísio on 11/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_SIM_PURCH_H
#define TRABALHO_FINAL_ALG1_SIM_PURCH_H

#include <stdio.h>
#include "head.h"

// Simular compra.
void sim_purch(const double *PRODUCTS_PRICE, int* PRODUCTS_STOCK, const double* PAYMENT_DISCOUNT, double* CLIENTS_DEBT)
{
    printf("Simulando compra.\n");

    int
            purchases[NUM_PRODUCTS], // Armazena as compras para subtrair do estoque.
    selection_i = 0, // Índice da seleção.
    max_selection = 100,
            client_id = 0; // Número máximo de seleções.

    double total_price = 0, discount = 0; // Preço total da compra.
    payment_code payment_code = 0; // Código da forma de pagamento escolhida pelo usuário.
    product_code prod_code = 0; // Código do produto escolhido pelo usuário.

    // Inicializa o vetor de compras.
    purchases[0] = 0; // Pão.
    purchases[1] = 0; // Leite.
    purchases[2] = 0; // Café.
    purchases[3] = 0; // Arroz.
    purchases[4] = 0; // Feijão.
    purchases[5] = 0; // Açúcar.
    purchases[6] = 0; // Sal.
    purchases[7] = 0; // Óleo.
    purchases[8] = 0; // Farinha.
    purchases[9] = 0; // Carne.

    // Loop da seleção de produtos.
    for (int i = 0; i < max_selection; i++) {
        int quantity = 0; // Quantidade do produto escolhido pelo usuário.
        double product_discount = 0; // Desconto do produto escolhido pelo usuário em função da quantidade.
        product_code temp_prod_code = 0; // Código do produto escolhido pelo usuário.

        // Menu de opções.
        printf("Escolha um produto:\n");
        printf("[%d] - Pão.\n", BREAD);
        printf("[%d] - Leite.\n", MILK);
        printf("[%d] - Café.\n", COFFEE);
        printf("[%d] - Arroz.\n", RICE);
        printf("[%d] - Feijão.\n", BEANS);
        printf("[%d] - Açúcar.\n", SUGAR);
        printf("[%d] - Sal.\n", SALT);
        printf("[%d] - Óleo.\n", OIL);
        printf("[%d] - Farinha.\n", FLOUR);
        printf("[%d] - Carne.\n", MEAT);
        printf("[%d] - Finalizar compra.\n", EXIT_PRODUCT_SEL);

        // Seleção do produto.
        printf("Selecione uma opção: ");
        scanf("%d", &temp_prod_code);

        if (temp_prod_code == EXIT_PRODUCT_SEL) break;
        else prod_code = temp_prod_code;

        // Lê a quantidade do produto escolhido pelo usuário.
        printf("Quantidade: ");
        scanf("%d", &quantity);

        // Verifica se a quantidade é válida.
        if (quantity <= 0) {
            printf("Quantidade inválida.\n");
            continue;
        }

        // Verifica se há quantidade o suficiente no estoque.
        if (PRODUCTS_STOCK[temp_prod_code] < quantity || PRODUCTS_STOCK[temp_prod_code] < purchases[temp_prod_code] + quantity) {
            printf("Quantidade indisponível.\n");
            continue;
        }

        // Checa se o código do produto é válido e atribui o desconto com acordo com a quantidade.
        switch (temp_prod_code) {
            case BREAD:
                if (quantity >= 10) product_discount = 0.10;
                break;
            case MILK:
                if (quantity >= 5) product_discount = 0.05;
                break;
            case COFFEE:
                if (quantity >= 3) product_discount = 0.03;
                break;
            case RICE:
            case BEANS:
            case SUGAR:
            case SALT:
            case OIL:
            case FLOUR:
            case MEAT:
                if (quantity >= 2) product_discount = 0.02;
                break;
            default:
                printf("Opção inválida.\n");
                continue;
        }

        // Adiciona o produto e a quantidade ao vetor de compras e calcula o preço total.
        purchases[temp_prod_code] += quantity;
        total_price += (PRODUCTS_PRICE[temp_prod_code] * quantity) * (1 - product_discount);
    }

    if (total_price != 0) {
        printf("Total: R$%.2f\n", total_price);

        // Seleção da forma de pagamento.
        printf("Escolha uma forma de pagamento:\n");
        printf("[%d] - Dinheiro.\n", CASH);
        printf("[%d] - Cartão (débito ou crédito).\n", CARD);
        printf("[%d] - Pix.\n", PIX);
        printf("[%d] - Crediário.\n", CREDIARY);
        printf("[%d] - Cancelar compra.\n", EXIT_PAYMENT_SEL);

        // Lê a forma de pagamento escolhida pelo usuário.
        printf("Selecione uma opção: ");
        scanf("%d", &payment_code);

        // Verifica se a forma de pagamento é válida e aplica o  desconto de acordo.
        switch (payment_code) {
            case CASH:
                discount = PAYMENT_DISCOUNT[CASH];
                break;
            case CARD:
                discount = PAYMENT_DISCOUNT[CARD];
                break;
            case PIX:
                discount = PAYMENT_DISCOUNT[PIX];
                break;
            case CREDIARY:
                // Lê o id do cliente.
                printf("ID do cliente: ");
                scanf("%d", &client_id);

                // Verifica se o id do cliente é válido.
                if (client_id < 0 || client_id >= NUM_CLIENTS) {
                    printf("ID inválido.\n");
                    break;
                }

                // Verifica se o cliente é válido.
                if (CLIENTS_DEBT[client_id] == -1) {
                    printf("Cliente não encontrado.\n");
                    break;
                }

                discount = PAYMENT_DISCOUNT[CREDIARY];
                CLIENTS_DEBT[client_id] += total_price;

                printf("Dívida do cliente %d: R$ %.2f\n", client_id, CLIENTS_DEBT[client_id]);
                break;
            case EXIT_PAYMENT_SEL:
                printf("Compra cancelada.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

        if (payment_code != EXIT_PAYMENT_SEL) {
            total_price *= (1 - discount);

            printf("Total: R$%.2f\n", total_price);

            // Subtrai itens do estoque.
            PRODUCTS_STOCK[prod_code] -= purchases[prod_code];

            getchar();

            printf("Compra finalizada.\n");
        } else printf("Compra cancelada.\n");
    }

    else printf("Compra cancelada.\n");
}

#endif //TRABALHO_FINAL_ALG1_SIM_PURCH_H
