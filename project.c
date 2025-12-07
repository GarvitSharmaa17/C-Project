#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOTAL_STUDENTS 60
#define CR 4
#define name_length 100

int main() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open students.txt\n");
        return 1;
    }

    char students[TOTAL_STUDENTS][name_length];
    int count = 0;

    while (fgets(students[count], name_length, fp) != NULL && count < TOTAL_STUDENTS) {
        students[count][strcspn(students[count], "\n")] = '\0';
        count++;
    }
    fclose(fp);

    if (count < TOTAL_STUDENTS) {
        printf("Error: File does not contain 60 student names.\n");
        return 1;
    }

    int used[TOTAL_STUDENTS] = {0};
    int indices[CR];

    srand(time(NULL));

    for (int i = 0; i < CR; i++) {
        int r;
        do {
            r = rand() % TOTAL_STUDENTS;
        } while (used[r]);
        used[r] = 1;
        indices[i] = r;
    }

    printf("\nSelected Class Representatives:\n");
    for (int i = 0; i < CR; i++) {
        printf("%s\n", students[indices[i]]);
    }

    return 0;
}
