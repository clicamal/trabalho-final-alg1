//
// Created by Tarcísio on 18/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_PAY_DEBT_H
#define TRABALHO_FINAL_ALG1_PAY_DEBT_H

#include <stdio.h>
#include "head.h"

// Pagar débito de um cliente
void pay_debt(double *CLIENTS_DEBT)
{
    printf("Pagando débito de um cliente.\n");

    int max_pay_debt_i = 100; // Número de iteracões máximas para pagar a dívida de um cliente.

    for (int pay_debt_i = 0; pay_debt_i < max_pay_debt_i; pay_debt_i++) {
        int client_id = 0; // ID do cliente.
        float payment = 0; // Valor do pagamento.

        // Lê o ID do cliente.
        printf("Digite o ID do cliente (-1 para sair): ");
        scanf("%d", &client_id);

        // Verifica se o usuário deseja sair.
        if (client_id == -1) break;

        // Verifica se o ID do cliente é válido.
        if (client_id < 0 || client_id >= NUM_CLIENTS) {
            printf("ID do cliente inválido.\n");
            continue;
        }

        // Verifica se o cliente está cadastrado.
        if (CLIENTS_DEBT[client_id] == -1) {
            printf("O cliente não encontrado.\n");
            continue;
        }

        // Lê o valor do pagamento.
        printf("Digite o valor do pagamento: ");
        scanf("%f", &payment);

        // Verifica se o valor do pagamento é válido.
        if (payment <= 0) {
            printf("Valor do pagamento inválido.\n");
            continue;
        }

        // Verifica se o valor do pagamento é maior que a dívida do cliente.
        if (payment > CLIENTS_DEBT[client_id]) {
            printf("Valor do pagamento maior que a dívida do cliente.\n");
            continue;
        }

        // Paga a dívida do cliente.
        CLIENTS_DEBT[client_id] -= payment;
    }

    printf("Fim da operação.\n");
}

#endif //TRABALHO_FINAL_ALG1_PAY_DEBT_H
