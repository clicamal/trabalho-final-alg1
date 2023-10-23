//
// Created by Tarcísio on 11/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_SIM_PURCH_H
#define TRABALHO_FINAL_ALG1_SIM_PURCH_H

#include <stdio.h>
#include <stdbool.h>
#include "head.h"

// Simular compra.
void sim_purch(const float *PRODUCTS_PRICE, int* PRODUCTS_STOCK, const float* PAYMENT_DISCOUNT, double* CLIENTS_DEBT)
{
    printf("Simulando compra.\n");

    int
        purchases[NUM_PRODUCTS], // Armazena as compras para subtrair do estoque.
        max_selection_i = 100, // Número máximo de seleções.
        client_id = 0; // ID do cliente.

    float total_price = 0, discount = 0; // Preço total da compra.
    payment_code payment_code = 0; // Código da forma de pagamento escolhida pelo usuário.

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
    for (int selection_i = 0; selection_i < max_selection_i; selection_i++) {
        int quantity = 0; // Quantidade do produto escolhido pelo usuário.
        float product_discount = 0; // Desconto do produto escolhido pelo usuário em função da quantidade.
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

        // Lê a opção escolhida pelo usuário.
        printf("Selecione uma opção: ");
        scanf("%d", &temp_prod_code);

        // Verifica se o usuário deseja finalizar a compra.
        if (temp_prod_code == EXIT_PRODUCT_SEL) break;

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
                if (quantity >= 10) product_discount = (float) 0.10;
                break;
            case MILK:
                if (quantity >= 5) product_discount = (float) 0.05;
                break;
            case COFFEE:
                if (quantity >= 3) product_discount = (float) 0.03;
                break;
            case RICE:
            case BEANS:
            case SUGAR:
            case SALT:
            case OIL:
            case FLOUR:
            case MEAT:
                if (quantity >= 2) product_discount = (float) 0.02;
                break;
            default:
                printf("Opção inválida.\n");
                continue;
        }

        // Adiciona o produto e a quantidade ao vetor de compras e calcula o preço total.
        purchases[temp_prod_code] += quantity;
        total_price += (PRODUCTS_PRICE[temp_prod_code] * (float) quantity) * (1 - product_discount);
    }

    if (total_price != 0) {
        int
            max_cliend_sel_i = 100, // Número máximo de seleções de cliente.
            max_payment_meth_sel_i = 100; // Número máximo de seleções de forma de pagamento.
        bool client_found = false; // Indica se o cliente foi encontrado.
        bool purchase_canceled = false;

        printf("Total: R$%.2f\n", total_price);

        // Loop da seleção de cliente.
        for (int payment_meth_sel_i = 0; payment_meth_sel_i < max_payment_meth_sel_i; payment_meth_sel_i++) {
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
                    for (int client_sel_i = 0; client_sel_i < max_cliend_sel_i; client_sel_i++) {
                        // Lê o id do cliente.
                        printf("ID do cliente (-1 para sair): ");
                        scanf("%d", &client_id);

                        // Verifica se o usuário deseja sair.
                        if (client_id == -1) break;

                        // Verifica se o id do cliente é válido.
                        if (client_id < 0 || client_id >= NUM_CLIENTS) {
                            printf("ID inválido.\n");
                            continue;
                        }

                        // Verifica se o cliente é válido.
                        if (CLIENTS_DEBT[client_id] == -1) {
                            printf("Cliente não encontrado.\n");
                            continue;
                        }

                        client_found = true;
                        break;
                    }

                    if (!client_found) {
                        continue;
                    }

                    discount = PAYMENT_DISCOUNT[CREDIARY];
                    CLIENTS_DEBT[client_id] += total_price;

                    printf("Dívida do cliente %d: R$ %.2f\n", client_id, CLIENTS_DEBT[client_id]);
                    break;
                case EXIT_PAYMENT_SEL:
                    printf("Compra cancelada.\n");
                    purchase_canceled = true;
                    break;
                default:
                    printf("Opção inválida.\n");
                    continue;
            }

            if (client_found || purchase_canceled) break;
        }

        if (payment_code != EXIT_PAYMENT_SEL) {
            total_price *= (1 - discount);

            printf("Total: R$%.2f\n", total_price);

            for (int i = 0; i < NUM_PRODUCTS; i++) {
                PRODUCTS_STOCK[i] -= purchases[i];
            }

            getchar();

            printf("Compra finalizada.\n");
        }
    }

    else printf("Compra cancelada.\n");
}

#endif //TRABALHO_FINAL_ALG1_SIM_PURCH_H
