// This Assignment is about using POSIX threads.
// This program first writes 1,000,000 random numbers to a file called Data.txt
// Then it creates 3 threads.
// Create a file named Data_Thread_X.txt, where X is the letter A, B, or C, depending on which thread created the file.
// Each thread copies the data from the Data.txt file to its Data_Thread_X.txt file.
// While copying the data, calculate the average of the numbers in the Data.txt file to two places past the decimal point (e.g., 50.00) and output the average just before the thread finishes. Make sure this works on files of any size.
// Close the Data.txt file and the Data_Thread_X.txt files.
// Compute each thread’s execution time and output it in milliseconds (ms).
// The main thread should wait for the thread tasks to finish. The main thread should also compute the total “wall clock” execution time (ms) of the program execution (including all three thread tasks) and output the result.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Function to write random numbers to a file Data.txt
void write_random_numbers() {

    FILE *file = fopen("Data.txt", "w");

    for (int i = 0; i < 1000000; i++) {
        fprintf(file, "%d\n", rand() % 101);
    }

    fclose(file);

}

// Function to calculate the average of the numbers
// in the Data.txt file for Thread A
void *operation_a() {

    clock_t start = clock();
    int sum = 0;
    int count = 0;

    FILE *dataA = fopen("Data_Thread_A.txt", "w");
    FILE *data = fopen("Data.txt", "r");

    while (!feof(data)) {
        char buffer[255];
        fgets(buffer, 255, (FILE*)data);
        int number = atoi(buffer);
        fputs(buffer, (FILE*)dataA);
        sum += number;
        count++;
    }

    double average = (double) sum / count;

    clock_t end = clock();

    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    printf("Thread A found an average of %.2f in %.2f milliseconds\n", average, time);

    fclose(dataA);

    return NULL;
}

// Function to calculate the average of the numbers
// in the Data.txt file for Thread B
void *operation_b() {

    clock_t start = clock();
    int sum = 0;
    int count = 0;

    FILE *dataB = fopen("Data_Thread_B.txt", "w");
    FILE *data = fopen("Data.txt", "r");

    while (!feof(data)) {
        char buffer[255];
        fgets(buffer, 255, (FILE*)data);
        int number = atoi(buffer);
        fputs(buffer, (FILE*)dataB);
        sum += number;
        count++;
    }

    double average = (double) sum / count;

    clock_t end = clock();

    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    printf("Thread B found an average of %.2f in %.2f milliseconds\n", average, time);

    fclose(dataB);

    return NULL;
}

// Function to calculate the average of the numbers
// in the Data.txt file for Thread C
void *operation_c() {

    clock_t start = clock();
    int sum = 0;
    int count = 0;

    FILE *dataC = fopen("Data_Thread_C.txt", "w");
    FILE *data = fopen("Data.txt", "r");

    while (!feof(data)) {
        char buffer[255];
        fgets(buffer, 255, data);
        int number = atoi(buffer);
        fputs(buffer, dataC);
        sum += number;
        count++;
    }

    double average = (double) sum / count;

    clock_t end = clock();

    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000;

    printf("Thread C found an average of %.2f in %.2f milliseconds\n", average, time);

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

    double time = (double) (end - start) / CLOCKS_PER_SEC * 1000;
    printf("This operation took %.2f milliseconds\n", time);
}

