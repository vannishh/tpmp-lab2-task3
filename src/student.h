#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECT_COUNT 4
#define MAX_NAME_LEN 50
#define MAX_GROUP_LEN 10

typedef struct {
    char surname[MAX_NAME_LEN];
    char initials[MAX_NAME_LEN];
    char group[MAX_GROUP_LEN];
    int grades[SUBJECT_COUNT];
} STUDENT;

#endif
