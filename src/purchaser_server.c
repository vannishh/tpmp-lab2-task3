#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "purchaser_interface.h"

/**
 * @file purchaser_server.c
 * @brief Реализация функций для работы со структурой PURCHASER
 * @author Иванов Иван, группа 11
 * @version 1.0
 */

void input_purchaser(Purchaser* purchaser) {
    printf("Введите фамилию: ");
    scanf("%s", purchaser->surname);
    
    printf("Введите имя: ");
    scanf("%s", purchaser->name);
    
    printf("Введите отчество: ");
    scanf("%s", purchaser->patronymic);
    
    printf("Введите пол (М/Ж): ");
    scanf("%s", purchaser->gender);
    
    printf("Введите национальность: ");
    scanf("%s", purchaser->nationality);
    
    printf("Введите рост (см): ");
    scanf("%d", &(purchaser->height));
    
    printf("Введите вес (кг): ");
    scanf("%d", &(purchaser->weight));
    
    printf("Введите дату рождения (год месяц день): ");
    scanf("%d %d %d", &(purchaser->birth_date.year),
          &(purchaser->birth_date.month),
          &(purchaser->birth_date.day));
    
    printf("Введите номер телефона: ");
    scanf("%s", purchaser->phone);
    
    printf("--- Введите адрес ---\n");
    printf("Почтовый индекс: ");
    scanf("%s", purchaser->address.postal_code);
    printf("Страна: ");
    scanf("%s", purchaser->address.country);
    printf("Область: ");
    scanf("%s", purchaser->address.region);
    printf("Район: ");
    scanf("%s", purchaser->address.district);
    printf("Город: ");
    scanf("%s", purchaser->address.city);
    printf("Улица: ");
    scanf("%s", purchaser->address.street);
    printf("Дом: ");
    scanf("%s", purchaser->address.house);
    printf("Квартира: ");
    scanf("%s", purchaser->address.apartment);
    
    printf("Введите номер кредитной карточки: ");
    scanf("%s", purchaser->credit_card);
    
    printf("Введите номер банковского счета: ");
    scanf("%s", purchaser->bank_account);
}

void print_purchaser(const Purchaser* purchaser) {
    printf("\n========================================\n");
    printf("ФИО: %s %s %s\n", purchaser->surname, 
           purchaser->name, purchaser->patronymic);
    printf("Пол: %s, Национальность: %s\n", 
           purchaser->gender, purchaser->nationality);
    printf("Рост: %d см, Вес: %d кг\n", 
           purchaser->height, purchaser->weight);
    printf("Дата рождения: %02d.%02d.%d\n", 
           purchaser->birth_date.day,
           purchaser->birth_date.month,
           purchaser->birth_date.year);
    printf("Телефон: %s\n", purchaser->phone);
    printf("Адрес: %s, %s, %s, %s, г. %s, ул. %s, д. %s, кв. %s\n",
           purchaser->address.postal_code,
           purchaser->address.country,
           purchaser->address.region,
           purchaser->address.district,
           purchaser->address.city,
           purchaser->address.street,
           purchaser->address.house,
           purchaser->address.apartment);
    printf("Кредитная карта: %s\n", purchaser->credit_card);
    printf("Банковский счет: %s\n", purchaser->bank_account);
    printf("========================================\n");
}

int is_from_brest(const Purchaser* purchaser) {
    return (strcmp(purchaser->address.city, "Брест") == 0 ||
            strcmp(purchaser->address.city, "Brest") == 0);
}

int print_brest_purchasers(const Purchaser* purchasers, int size) {
    int count = 0;
    printf("\n=== Покупатели из города Брест ===\n");
    
    for (int i = 0; i < size; i++) {
        if (is_from_brest(&purchasers[i])) {
            print_purchaser(&purchasers[i]);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Покупателей из города Брест не найдено.\n");
    } else {
        printf("\nВсего покупателей из Бреста: %d\n", count);
    }
    
    return count;
}

void print_all_purchasers(const Purchaser* purchasers, int size) {
    printf("\n=== Список всех покупателей ===\n");
    for (int i = 0; i < size; i++) {
        printf("\nПокупатель %d:", i + 1);
        print_purchaser(&purchasers[i]);
    }
}
