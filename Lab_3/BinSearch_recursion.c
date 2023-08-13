// Aim of the program: Write a program to implement Binary Search to give the position of leftmost appearance of the element in the array being searched. Display the number of comparisons made while searching. 

// Input:
// Enter size of array: 10
// Enter elements of the array: 2 3 7 7 7 11 12 12 20 50 
// Enter the key to be searched: 7

// Output:
// 7 found at index position 2 
// Number of comparisons: 3


// Addition to this question : write elments in an array using random number generation and using recurrsion method 



#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

int count = 0;

int bin_search_recursive(int arr[], int l, int r, int x) 
{
    if (l <= r) 
    {
        int mid = l + (l - r) / 2;
        count++;
        if (arr[mid] == x) 
        {
            if (mid == 0 || arr[mid - 1] != x) 
            {
                return mid;
            } 
            else 
            {
                return bin_search_recursive(arr, l, mid - 1, x);
            }
        } else if (arr[mid] > x) 
        {
            return bin_search_recursive(arr, l, mid - 1, x);
        } else 
        {
            return bin_search_recursive(arr, mid + 1, r, x);
        }
    }
    return -1;
}

int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int main() 
{
    int x, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; 

    srand(time(NULL));
    printf("Generated and sorted elements: ");
    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % 100; 
    }
    qsort(arr, n, sizeof(int), compare); 
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int low = 0;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int high = n - 1;

    int pos = bin_search_recursive(arr, low, high, x);

    if (pos != -1) 
    {
        printf("The position of leftmost appearance of %d is %d\n", x, pos);
    } 
    else 
    {
        printf("Element %d not found in the array\n", x);
    }

    printf("The number of comparisons made is %d\n", count);

    return 0;
}
