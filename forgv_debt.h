//
// Created by Tarcísio on 18/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_FORGV_DEBT_H
#define TRABALHO_FINAL_ALG1_FORGV_DEBT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "head.h"

// Perdoar débito de um cliente aleatório.
void forgv_deb(float *CLIENTS_DEBT) {
    printf("Perdoando débito de um cliente aleatório.\n");

    int max_forgv_deb_i = 100; // Número de iterações máximas para perdoar a dívida de um cliente.
    bool found_client = false; // Indica se um cliente foi encontrado.
    int client_id = 0; // ID do cliente.

    for (int forgv_deb_i = 0; forgv_deb_i < max_forgv_deb_i; forgv_deb_i++) {
        // Sorteia um ID de cliente.
        client_id = rand() % NUM_CLIENTS;

        // Perdoa a dívida do cliente.
        if (CLIENTS_DEBT[client_id] != -1) {
            CLIENTS_DEBT[client_id] = 0;
            found_client = true;
        }
    }

    if (found_client) printf("Dívida do client %d perdoada.\n", client_id);
    else printf("Nenhum cliente encontrado.\n");

    printf("Fim da operação.\n");
}

#endif //TRABALHO_FINAL_ALG1_FORGV_DEBT_H
