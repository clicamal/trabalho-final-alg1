#include <stdio.h>

typedef enum {
    PURCH_SIM,
    SEARCH_DEBT,
    FILL_STOCK,
    SEARCH_STOCK,
    PAY_DEBT,
    FORGV_DEBT
} action;

int get_action();

void sim_purch();
void search_debt();
void fill_stock();
void search_stock();
void pay_debt();
void forgv_debt();

int main() {
    int action = get_action();

    switch (action) {
        case PURCH_SIM:
            sim_purch();
            break;
        case SEARCH_DEBT:
            search_debt();
            break;
        case FILL_STOCK:
            fill_stock();
            break;
        case SEARCH_STOCK:
            search_stock();
            break;
        case PAY_DEBT:
            pay_debt();
            break;
        case FORGV_DEBT:
            forgv_debt();
            break;
        default:
            printf("Ação inválida.");
    }

    printf("Fim do programa.\n");
    return 0;
}

int get_action()  {
    int action;

    printf("MENU:\n");
    printf("[%d] Simular compra\n", PURCH_SIM);
    printf("[%d] Consultar débito\n", SEARCH_DEBT);
    printf("[%d] Preencher estoque\n", FILL_STOCK);
    printf("[%d] Consultar estoque\n", SEARCH_STOCK);
    printf("[%d] Pagar débito\n", PAY_DEBT);
    printf("[%d] Perdoar dívida.\n", FORGV_DEBT);

    printf("Ação: ");

    scanf("%d", &action);

    return action;
}
