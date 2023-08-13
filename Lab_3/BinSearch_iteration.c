// Aim of the program: Write a program to implement Binary Search to give the position of leftmost appearance of the element in the array being searched. Display the number of comparisons made while searching. 

// Input:
// Enter size of array: 10
// Enter elements of the array: 2 3 7 7 7 11 12 12 20 50 
// Enter the key to be searched: 7

// Output:
// 7 found at index position 2 
// Number of comparisons: 3


// Addition to this question : write elments in an array using random number generation and using iteration method 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int count = 0;
int bin_search(int arr[], int l, int r, int x) 
{
    while (l <= r) 
    {
        int mid = (l + r) / 2;
        count++;
        if (arr[mid] == x) 
        {
            if (mid == 0 || arr[mid - 1] != x)
            {
                return mid;
            } 
            else 
            {
                r = mid - 1;
            }
        } 
        else if (arr[mid] > x) 
        {
            r = mid - 1;
        } 
        else 
        {
            l = mid + 1;
        }
    }
    return 0;
}
int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int main() 
{
    int x, n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));

    printf("Generated elements: ");
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 10; 
    }
    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int low = 0;
    printf("\nEnter the element to search: ");
    scanf("%d",&x);
    int high = n - 1;
    int pos = bin_search(arr, low, high, x);
    printf("The position of leftmost appearance of %d is %d\n", x, pos+1);
    printf("The number of comparisons made is %d\n", count);
    return 0;
}
