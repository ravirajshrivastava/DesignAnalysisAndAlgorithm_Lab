// Write a program to read 10 integers from a random number generation that must contain some duplicate values and store them into an array. Perform the following operations on the array.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int arr[SIZE], i,k, j, duplicates = 0;
    srand(time(0));

    printf("The random numbers are: ");
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (arr[i] == arr[j]) {
                duplicates = 1;
                arr[k] = arr[j];
                break;
            }
        }
        if (duplicates)
            break;
    }

    if (duplicates) {
        printf("The array contains duplicates.\n");
    } else {
        printf("it dosenot have duplicates.\n");
    }

    return 0;
}


