//
// Created by Tarcísio on 16/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_HEAD_H
#define TRABALHO_FINAL_ALG1_HEAD_H

#pragma once

// Código dos produtos.
typedef enum {
    BREAD, // Pão.
    MILK, // Leite.
    COFFEE, // Café.
    RICE, // Arroz.
    BEANS, // Feijão.
    SUGAR, // Açúcar.
    SALT, // Sal.
    OIL, // Óleo.
    FLOUR, // Farinha.
    MEAT, // Carne.
    EXIT_PRODUCT_SEL
} product_code;

// Código das formas de pagamento.
typedef enum {
    CASH, // Dinheiro.
    CARD, // Cartão (débito ou crédito).
    PIX, // Pix.
    CREDIARY, // Crediário.
    EXIT_PAYMENT_SEL
} payment_code;

const int NUM_PRODUCTS = 10; // Número de produtos.
const int NUM_CLIENTS = 100; // Número de clientes.

#endif //TRABALHO_FINAL_ALG1_HEAD_H
