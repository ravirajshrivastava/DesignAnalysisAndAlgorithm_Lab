// Aim of the program: Write a program to find out the second smallest and second largest element stored in an array of n integers.

#include <stdio.h>
#include <limits.h>

int main() {
    int n, fmax, smax, fmin, smin;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
        fmax = smax = INT_MIN;
        fmin = smin = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > fmax) {
            smax = fmax;
            fmax = arr[i];
        } 
        else if (arr[i] > smax && arr[i] != fmax)
            smax = arr[i];

        if (arr[i] < fmin) {
            smin = fmin;
            fmin = arr[i];
        } 
        else if (arr[i] < smin && arr[i] != fmin)
            smin = arr[i];
    }

    printf("The second largest number is %d\n", smax);
    printf("The second smallest number is %d\n", smin);
    return 0;
}
