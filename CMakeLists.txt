cmake_minimum_required(VERSION 3.26)
project(trabalho_final_alg1 C)

set(CMAKE_C_STANDARD 99)

add_executable(trabalho_final_alg1 main.c
        sim_purch.h
        head.h
        search_debt.h
        register_client.h
        search_stock.h
        fill_stock.h
        forgv_debt.h
        pay_debt.h
)
