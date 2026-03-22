#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "functions.h"

#define STUDENT_COUNT 7

int main() {
    STUDENT students[STUDENT_COUNT];
    float averages[STUDENT_COUNT];
    int current_count = STUDENT_COUNT;
    
    printf("=== Программа учета успеваемости студентов ===\n");
    printf("Ввод данных для %d студентов:\n", STUDENT_COUNT);
    
    // 1. Создание массива записей
    create_students(students, STUDENT_COUNT);
    
    // 2. Вычисление среднего балла
    calculate_averages(students, averages, STUDENT_COUNT);
    
    // Вывод всех студентов
    print_all_students(students, averages, current_count);
    
    // 3. Сортировка по убыванию среднего балла
    sort_by_average(students, averages, current_count);
    printf("\n=== После сортировки по убыванию среднего балла ===\n");
    print_all_students(students, averages, current_count);
    
    // 4. Вывод студентов с оценками только 4 и 5
    print_excellent_students(students, averages, current_count);
    
    // 5. Удаление студента с минимальным средним баллом
    remove_min_average_student(students, averages, &current_count);
    printf("\n=== После удаления студента с минимальным средним баллом ===\n");
    print_all_students(students, averages, current_count);
    
    return 0;
}
