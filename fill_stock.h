//
// Created by Tarcísio on 17/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_FILL_STOCK_H
#define TRABALHO_FINAL_ALG1_FILL_STOCK_H

#include <stdio.h>
#include "head.h"

// Preencher o estoque.
void fill_stock(int *PRODUCTS_STOCK)
{
    printf("Reabastecendo estoque...\n");
    int max_filling_i = 100; // Índice máximo do loop de preenchimento.

    for (int filling_i = 0; filling_i < max_filling_i; filling_i++) {
        product_code product = 0; // Código do produto.
        int quantity = 0; // Quantidade de produtos a serem adicionados.

        // Printando os produtos.
        printf("Produtos:\n");
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
        printf("[%d] - Sair.\n", EXIT_PRODUCT_SEL);

        // Lê o código do produto.
        printf("Digite o código do produto: ");
        scanf("%d", &product);

        if (product == EXIT_PRODUCT_SEL) break;

        // Lê a quantidade de produtos a serem adicionados.
        printf("Digite a quantidade de produtos a serem adicionados: ");
        scanf("%d", &quantity);

        // Verifica se o código do produto é válido.
        if (product < 0 || product > NUM_PRODUCTS) {
            printf("Código de produto inválido.\n");
            continue;
        }

        // Verifica se a quantidade de produtos é válida.
        if (quantity <= 0) {
            printf("Quantidade inválida.\n");
            continue;
        }

        // Adiciona a quantidade de produtos ao estoque.
        PRODUCTS_STOCK[product] += quantity;

        printf("Estoque atualizado.\n");
    }

    printf("Operação finalizada.\n");
}

#endif //TRABALHO_FINAL_ALG1_FILL_STOCK_H
