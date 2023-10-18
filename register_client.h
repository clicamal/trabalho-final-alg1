//
// Created by Tarcísio on 16/10/2023.
//

#ifndef TRABALHO_FINAL_ALG1_REGISTER_CLIENT_H
#define TRABALHO_FINAL_ALG1_REGISTER_CLIENT_H

#include <stdio.h>

#endif //TRABALHO_FINAL_ALG1_REGISTER_CLIENT_H

// Registra um cliente.
void register_client(double *CLIENTS_DEBT)
{
    int client_id = 0; // ID do cliente.

    // Lê o ID do cliente.
    printf("Digite o ID do cliente: ");
    scanf("%d", &client_id);

    // Checa se o cliente já existe.
    if (CLIENTS_DEBT[client_id] != -1) {
        printf("Cliente já existe.\n");
        return;
    }

    // Registra o cliente.
    CLIENTS_DEBT[client_id] = 0;

    printf("Cliente registrado.\n");
}
