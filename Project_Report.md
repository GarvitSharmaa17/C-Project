# Project Report
## Program to Select Four Class Representatives Randomly from a List of Students

## 1. Introduction
This project presents a C program designed to randomly select four class representatives from a total of 60 students. The program reads all student names from an external text file (`students.txt`) and performs a fair and unbiased random selection without repetition.

## 2. Objective
- Read 60 student names from a file.
- Validate that the file contains the required number of entries.
- Randomly select 4 unique class representatives.
- Display the selected students on the screen.

## 3. Tools and Technologies Used
- Language: C  
- Compiler: GCC  
- Header Files: stdio.h, stdlib.h, time.h, string.h  

## 4. Program Logic and Flow
### 4.1 Reading Student Data
The program opens `students.txt`, reads each name using `fgets()`, removes newline characters, and stores them in an array.

### 4.2 Random Selection
A `used[]` array ensures no student is selected twice. `srand(time(NULL))` provides randomization, and four unique indices are chosen.

### 4.3 Output
The program prints the four selected class representatives.

## 5. Code Listing
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TOTAL_STUDENTS 60
#define REPS 4
#define MAX_NAME_LEN 100

int main() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open students.txt\n");
        return 1;
    }

    char students[TOTAL_STUDENTS][MAX_NAME_LEN];
    int count = 0;

    while (fgets(students[count], MAX_NAME_LEN, fp) != NULL && count < TOTAL_STUDENTS) {
        students[count][strcspn(students[count], "\n")] = '\0';
        count++;
    }
    fclose(fp);

    if (count < TOTAL_STUDENTS) {
        printf("Error: File does not contain 60 student names.\n");
        return 1;
    }

    int used[TOTAL_STUDENTS] = {0};
    int indices[REPS];

    srand(time(NULL));

    for (int i = 0; i < REPS; i++) {
        int r;
        do {
            r = rand() % TOTAL_STUDENTS;
        } while (used[r]);
        used[r] = 1;
        indices[i] = r;
    }

    printf("\nSelected Class Representatives:\n");
    for (int i = 0; i < REPS; i++) {
        printf("%s\n", students[indices[i]]);
    }

    return 0;
}
```

## 6. Sample Output
```
Selected Class Representatives:
Garvit Sharma
Sahil Pravesh Sharma
Neer Bhayani
Abhyarth Parmar
```

## 7. Conclusion
The program successfully demonstrates file handling, string manipulation, and random number generation in C to fairly select class representatives.

## 8. References
- The C Programming Language (K&R)
- GCC Documentation
- C Standard Library Reference
