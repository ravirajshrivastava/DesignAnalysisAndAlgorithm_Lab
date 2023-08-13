// Aim of the program:Write a menu driven program to sort a list of elements in ascending order using InsertionSort technique. The nature of the input data is choice based anda distinct file is considered for each choice.The sorted elements can be stored in a separate output file. After sorting display the content of the output file along with number of comparisons. Based on the number of comparisons, conclude the input scenario is either best or worst case. 

// Note# 
// Number of elements in each input file should vary from 300 to 500 entries.
// For ascending order:Read data from a file “inAsce.dat”having content 10 20 30 40 ….., Store the result in “outInsAsce.dat”.
// For descending order: Read data from a file “inDesc.dat”having content 90 80 70 60….,Store the result in “outInsDesc.dat”.
// For random data: Read data from a file “inRand.dat”having content 55 66 33 11 44 …, Store the result in “outInsRand.dat”


//Additional Changes: Print the best, Worst and Average Case along with the time taken and generate the number using rand() function 



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int n)
{
    int arr[n];
    int i,j,key;
    for(i=0;i<n;i++)
    arr[i]=rand()%100;
    clock_t s,e;
    s=clock();
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    e=clock();
    printf("Time Required While Sorting : %ld\n",(e-s));


    s=clock();
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    e=clock();
    printf("Best Case : %ld\n",(e-s));


    s=clock();
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    e=clock();
    printf("Worst Case : %ld\n",(e-s));
}
int main()
{
    printf("For 1000 : \n");
    sort(1000);
    printf("For 5000 : \n");
    sort(5000);
    printf("For 10000 : \n");
    sort(10000);
    printf("For 15000 : \n");
    sort(15000);
    printf("For 20000 : \n");
    sort(20000);
    //printf("For 100000 : \n");
    //sort(100000);
    //printf("For 500000 : \n");
    //sort(500000);
}