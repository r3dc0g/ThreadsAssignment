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

void write_random_numbers() {
    FILE *file = fopen("Data.txt", "w");
    for (int i = 0; i < 1000000; i++) {
        fprintf(file, "%d\n", rand() % 101);
    }
    fclose(file);
}

void *operation_a() {

    return NULL;
}

void *operation_b() {

    return NULL;
}

void *operation_c() {

    return NULL;
}

int main(int argc, char *argv[]) {
    write_random_numbers();

    pthread_t thread1, thread2, thread3;

}

