//
// Created by Tarcísio on 17/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_SEARCH_STOCK_H
#define TRABALHO_FINAL_ALG1_SEARCH_STOCK_H

#include <stdio.h>
#include "head.h"

// Pesquisar estoque.
void search_stock(int *PRODUCTS_STOCK) {
    printf("Pesquisando estoque...\n");

    int
            max_search_i = 100; // Índice máximo de pesquisa.

    for (int search_i = 0; search_i < max_search_i; search_i++) {
        product_code product = 0; // Código do produto.

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

        // Verifica se o código do produto é válido.
        if (product < 0 || product > NUM_PRODUCTS) {
            printf("Código de produto inválido.\n");
            continue;
        }

        // Printa a quantidade de produtos no estoque.
        printf("Quantidade de produtos no estoque: %d\n", PRODUCTS_STOCK[product]);
    }

    printf("Operação finalizada.\n");
}

#endif //TRABALHO_FINAL_ALG1_SEARCH_STOCK_H
