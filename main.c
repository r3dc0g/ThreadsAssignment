// =================================================
//
//    Name:         Garrett Crites
//    Course:       CSC 3350
//    Assignment:   Threads Assignment
//    Professor:    Dr. Andy Cameron
//    Date:         5/29/2024
//
// =================================================
//
//    Compile:      gcc main.c -o theads
//
// =================================================
//
//    1. This Assignment is about using POSIX threads.
//
//    2. This program first writes 1,000,000 random
//       numbers to a file called Data.txt
//
//    3. Then it creates 3 threads.
//
//    4. Create a file named Data_Thread_X.txt, where
//       X is the letter A, B, or C, depending on which
//       thread created the file.
//
//    5. Each thread copies the data from the Data.txt
//       file to its Data_Thread_X.txt file.
//
//    6. While copying the data, calculate the average of
//       the numbers in the Data.txt file to two places
//       past the decimal point (e.g., 50.00) and output
//       the average just before the thread finishes. Make
//       sure this works on files of any size.
//
//    7. Close the Data.txt file and the Data_Thread_X.txt
//       files.
//
//    8. Compute each thread’s execution time and output
//       it in milliseconds (ms).
//
//    9. The main thread should wait for the thread tasks
//       to finish. The main thread should also compute
//       the total “wall clock” execution time (ms) of the
//       program execution (including all three thread
//       tasks) and output the result.
//
// =================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Function to write random numbers to a file Data.txt
void write_random_numbers() {

    // Seed the random number generator
    srand(time(NULL));

    // Open Data.txt file in write mode
    FILE *file = fopen("Data.txt", "w");

    // Write 1,000,000 random numbers to the file
    for (int i = 0; i < 1000000; i++) {
        fprintf(file, "%d\n", rand() % 101);
    }

    // Close the file
    fclose(file);

}

// Function to calculate the average of the numbers
// in the Data.txt file for Thread A
void *operation_a() {

    clock_t start = clock();
    int sum = 0;
    int count = 0;

    // Open Data_Thread_A.txt file in write mode
    // and Data.txt file in read mode
    FILE *dataA = fopen("Data_Thread_A.txt", "w");
    FILE *data = fopen("Data.txt", "r");

    // Copy each line from Data.txt to Data_Thread_A.txt
    while (!feof(data)) {
        char buffer[255];
        fgets(buffer, 255, (FILE*)data);
        int number = atoi(buffer);
        fputs(buffer, (FILE*)dataA);
        sum += number;
        count++;
    }

    // Find the average of the numbers
    double average = (double) sum / count;

    clock_t end = clock();

    // Find the time elapsed
    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    printf("Thread A found an average of %.2f in %.2f milliseconds.\n", average, time);

    // Close the file
    fclose(dataA);

    return NULL;
}

// Function to calculate the average of the numbers
// in the Data.txt file for Thread B
void *operation_b() {

    clock_t start = clock();
    int sum = 0;
    int count = 0;

    // Open Data_Thread_B.txt file in write mode
    // and Data.txt file in read mode
    FILE *dataB = fopen("Data_Thread_B.txt", "w");
    FILE *data = fopen("Data.txt", "r");

    // Copy each line from Data.txt to Data_Thread_B.txt
    while (!feof(data)) {
        char buffer[255];
        fgets(buffer, 255, (FILE*)data);
        int number = atoi(buffer);
        fputs(buffer, (FILE*)dataB);
        sum += number;
        count++;
    }

    // Find the average of the numbers
    double average = (double) sum / count;

    clock_t end = clock();

    // Find the time elapsed
    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    printf("Thread B found an average of %.2f in %.2f milliseconds.\n", average, time);

    // Close the file
    fclose(dataB);

    return NULL;
}

// Function to calculate the average of the numbers
// in the Data.txt file for Thread C
void *operation_c() {

    clock_t start = clock();
    int sum = 0;
    int count = 0;

    // Open Data_Thread_C.txt file in write mode
    // and Data.txt file in read mode
    FILE *dataC = fopen("Data_Thread_C.txt", "w");
    FILE *data = fopen("Data.txt", "r");

    // Copy each line from Data.txt to Data_Thread_C.txt
    while (!feof(data)) {
        char buffer[255];
        fgets(buffer, 255, data);
        int number = atoi(buffer);
        fputs(buffer, dataC);
        sum += number;
        count++;
    }

    // Find the average of the numbers
    double average = (double) sum / count;

    clock_t end = clock();

    // Find the time elapsed
    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    printf("Thread C found an average of %.2f in %.2f milliseconds.\n", average, time);

    // Close the file
    fclose(dataC);

    return NULL;
}

int main(int argc, char *argv[]) {

    write_random_numbers();

    pthread_t thread1, thread2, thread3;

    clock_t start = clock();

    pthread_create(&thread1, NULL, operation_a, NULL);
    pthread_create(&thread2, NULL, operation_b, NULL);
    pthread_create(&thread3, NULL, operation_c, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    clock_t end = clock();

    // Find the time elapsed
    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000;
    printf("This whole operation took %.2f milliseconds.\n", time);
}

