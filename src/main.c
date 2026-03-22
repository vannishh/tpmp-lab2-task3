#include <stdio.h>
#include <stdlib.h>
#include "purchaser_interface.h"

/**
 * @file main.c
 * @brief Клиентская часть программы для работы с покупателями
 * @author Иванов Иван, группа 11
 * @version 1.0
 */

#define MAX_PURCHASERS 100

/**
 * @brief Главная функция программы
 * @param argc Количество аргументов командной строки
 * @param argv Аргументы командной строки
 * @return 0 при успешном выполнении
 */
int main(int argc, char* argv[]) {
    Purchaser purchasers[MAX_PURCHASERS];
    int count = 0;
    int n;
    
    /* Проверка аргументов командной строки */
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <количество_покупателей>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    n = atoi(argv[1]);
    if (n <= 0 || n > MAX_PURCHASERS) {
        fprintf(stderr, "Ошибка: количество покупателей должно быть от 1 до %d\n", 
                MAX_PURCHASERS);
        return EXIT_FAILURE;
    }
    
    printf("=== Ввод данных о покупателях ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nПокупатель %d:\n", i + 1);
        input_purchaser(&purchasers[i]);
        count++;
    }
    
    print_all_purchasers(purchasers, count);
    
    print_brest_purchasers(purchasers, count);
    
    return EXIT_SUCCESS;
}
