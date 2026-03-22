#include "functions.h"
#include <stdio.h>
#include <string.h>

void create_students(STUDENT *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("\n=== Студент %d ===\n", i + 1);
        
        printf("Введите фамилию: ");
        scanf("%s", students[i].surname);
        
        printf("Введите инициалы: ");
        scanf("%s", students[i].initials);
        
        printf("Введите номер группы: ");
        scanf("%s", students[i].group);
        
        printf("Введите 4 оценки (через пробел): ");
        for (int j = 0; j < SUBJECT_COUNT; j++) {
            scanf("%d", &students[i].grades[j]);
        }
    }
}

void calculate_averages(STUDENT *students, float *averages, int count) {
    for (int i = 0; i < count; i++) {
        float sum = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++) {
            sum += students[i].grades[j];
        }
        averages[i] = sum / SUBJECT_COUNT;
    }
}

void sort_by_average(STUDENT *students, float *averages, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (averages[i] < averages[j]) {
                // Обмен средних баллов
                float temp_avg = averages[i];
                averages[i] = averages[j];
                averages[j] = temp_avg;
                
                // Обмен структур
                STUDENT temp_student = students[i];
                students[i] = students[j];
                students[j] = temp_student;
            }
        }
    }
}

void print_excellent_students(STUDENT *students, float *averages, int count) {
    int found = 0;
    printf("\n=== Студенты с оценками только 4 и 5 ===\n");
    
    for (int i = 0; i < count; i++) {
        int is_excellent = 1;
        for (int j = 0; j < SUBJECT_COUNT; j++) {
            if (students[i].grades[j] != 4 && students[i].grades[j] != 5) {
                is_excellent = 0;
                break;
            }
        }
        
        if (is_excellent) {
            found = 1;
            printf("%s %s, группа %s, средний балл: %.2f\n", 
                   students[i].surname, students[i].initials, 
                   students[i].group, averages[i]);
            printf("Оценки: ");
            for (int j = 0; j < SUBJECT_COUNT; j++) {
                printf("%d ", students[i].grades[j]);
            }
            printf("\n\n");
        }
    }
    
    if (!found) {
        printf("Студенты с оценками только 4 и 5 не найдены.\n");
    }
}

void remove_min_average_student(STUDENT *students, float *averages, int *count) {
    if (*count == 0) return;
    
    int min_index = 0;
    for (int i = 1; i < *count; i++) {
        if (averages[i] < averages[min_index]) {
            min_index = i;
        }
    }
    
    printf("\nУдаление студента с минимальным средним баллом (%.2f): %s %s\n", 
           averages[min_index], students[min_index].surname, 
           students[min_index].initials);
    
    // Сдвигаем элементы
    for (int i = min_index; i < *count - 1; i++) {
        students[i] = students[i + 1];
        averages[i] = averages[i + 1];
    }
    
    (*count)--;
}

void print_all_students(STUDENT *students, float *averages, int count) {
    printf("\n=== Все студенты ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s %s, группа %s, средний балл: %.2f\n", 
               i + 1, students[i].surname, students[i].initials, 
               students[i].group, averages[i]);
        printf("   Оценки: ");
        for (int j = 0; j < SUBJECT_COUNT; j++) {
            printf("%d ", students[i].grades[j]);
        }
        printf("\n");
    }
}
