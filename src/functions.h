#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "student.h"

// Создание массива записей (ввод с клавиатуры)
void create_students(STUDENT *students, int count);

// Вычисление среднего балла каждого студента
void calculate_averages(STUDENT *students, float *averages, int count);

// Сортировка по убыванию среднего балла
void sort_by_average(STUDENT *students, float *averages, int count);

// Вывод студентов с оценками только 4 и 5
void print_excellent_students(STUDENT *students, float *averages, int count);

// Удаление студента с минимальным средним баллом
void remove_min_average_student(STUDENT *students, float *averages, int *count);

// Вывод всех студентов
void print_all_students(STUDENT *students, float *averages, int count);

#endif
