// Aim of the program: Generate an array using random number generator and then Write a function toROTATE_RIGHT(p1, p2 ) right an array for first p2 elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p & q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.  

// Input:
// Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99 
// Call the function ROTATE_RIGHT(A, 5)
// Output:
// Before ROTATE: 	11 22 33 44 55 66 77 88 99 
// After ROTATE: 	55 11 22 33 44 66 77 88 99
#include <stdio.h>
#define SIZE 10

void EXCHANGE(int p, int q) 
{
    int temp = p;
    p = q;
    q = temp;
}

void ROTATE_RIGHT(int p1, int p2) 
{
    for (int i = 0; i < p2 - 1; i++) 
    {
        EXCHANGE(p1 + i, p1 + p2 - 1);
    }
}
int main()
{
    int arr[SIZE];
    printf("The random numbers are: ");
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n"); 
    printf("Enter the postions to exhange");
    int x, y;
    scanf("%d",&x); 
    scanf("%d",&y);
    ROTATE_RIGHT(x, y);

     printf("After ROTATE:\t");
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
