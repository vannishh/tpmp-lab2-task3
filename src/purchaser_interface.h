#ifndef PURCHASER_INTERFACE_H
#define PURCHASER_INTERFACE_H

#include "purchaser.h"

/**
 * @file purchaser_interface.h
 * @brief Интерфейс для работы со структурой PURCHASER
 * @author Иванов Иван, группа 11
 * @version 1.0
 */

/**
 * @brief Ввод данных о покупателе с клавиатуры
 * @param purchaser Указатель на структуру Purchaser
 */
void input_purchaser(Purchaser* purchaser);

/**
 * @brief Вывод информации о покупателе
 * @param purchaser Указатель на структуру Purchaser
 */
void print_purchaser(const Purchaser* purchaser);

/**
 * @brief Проверка, проживает ли покупатель в городе Брест
 * @param purchaser Указатель на структуру Purchaser
 * @return 1 если покупатель из Бреста, 0 в противном случае
 */
int is_from_brest(const Purchaser* purchaser);

/**
 * @brief Вывод покупателей из города Брест
 * @param purchasers Массив структур Purchaser
 * @param size Размер массива
 * @return Количество покупателей из Бреста
 */
int print_brest_purchasers(const Purchaser* purchasers, int size);

/**
 * @brief Вывод всех покупателей
 * @param purchasers Массив структур Purchaser
 * @param size Размер массива
 */
void print_all_purchasers(const Purchaser* purchasers, int size);

#endif /* PURCHASER_INTERFACE_H */
