//
// Created by Tarcísio on 16/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_SEARCH_DEBT_H
#define TRABALHO_FINAL_ALG1_SEARCH_DEBT_H

#endif //TRABALHO_FINAL_ALG1_SEARCH_DEBT_H

#include <stdio.h>
#include "head.h"

void search_debt(const float *CLIENTS_DEBT)
{
    float client_debt = 0; // Dívida do cliente.
    int
        search_i = 0, // Índice da busca.
        max_search = 100, // Número máximo de buscas.
        client_id = 0; // ID do cliente.

    while (search_i < max_search) {
        // Lê o ID do cliente.
        printf("Digite o ID do cliente: ");
        scanf("%d", &client_id);

        // Checa se o cliente existe.
        if (client_id < 0 || client_id > NUM_CLIENTS) {
            printf("Cliente não encontrado.\n");
            search_i++;
            continue;
        }

        // Obtém a dívida do cliente.
        client_debt = CLIENTS_DEBT[client_id];

        // Se a dívida é -1, o cliente não existe.
        if (client_debt == -1) {
            printf("Cliente não encontrado.\n");
            search_i++;
            continue;
        }

        // Imprime a dívida do cliente.
        printf("Dívida do cliente %d: R$ %.2f\n", client_id, client_debt);
        break;
    }

    printf("Operação finalizada.\n");
}
