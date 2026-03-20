#ifndef PURCHASER_H
#define PURCHASER_H

/**
 * @file purchaser.h
 * @brief Определение структуры PURCHASER и вспомогательных структур
 * @author Иванов Иван, группа 11
 * @version 1.0
 */

/**
 * @brief Структура для хранения даты рождения
 */
typedef struct {
    int year;   /* Год рождения */
    int month;  /* Месяц рождения */
    int day;    /* День рождения */
} Date;

/**
 * @brief Структура для хранения адреса
 */
typedef struct {
    char postal_code[10];   /* Почтовый индекс */
    char country[50];       /* Страна */
    char region[50];        /* Область */
    char district[50];      /* Район */
    char city[50];          /* Город */
    char street[100];       /* Улица */
    char house[10];         /* Дом */
    char apartment[10];     /* Квартира */
} Address;

/**
 * @brief Структура, содержащая информацию о покупателе
 */
typedef struct {
    char surname[50];           /* Фамилия */
    char name[50];              /* Имя */
    char patronymic[50];        /* Отчество */
    char gender[10];            /* Пол */
    char nationality[30];       /* Национальность */
    int height;                 /* Рост (см) */
    int weight;                 /* Вес (кг) */
    Date birth_date;            /* Дата рождения */
    char phone[20];             /* Номер телефона */
    Address address;            /* Домашний адрес */
    char credit_card[20];       /* Номер кредитной карточки */
    char bank_account[30];      /* Номер банковского счета */
} Purchaser;

#endif /* PURCHASER_H */
