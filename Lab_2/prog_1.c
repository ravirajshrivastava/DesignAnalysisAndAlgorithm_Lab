// Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion.Store the binary value in a separate discfile. 

// Note# Read the value of ‘n’, source file name and destination file name from command line arguments.Display the decimal numbers and their equivalent binary numbers from the output file. 

// Give the contents of the input disc file “inDec.dat” as 
// 30  75   2564  …

// Contents of the output disc file “outBin.dat” as
// The binary equivalent of 30 is 0000000000011110
// The binary equivalent of 75 is 0000000001001011
// The binary equivalent of 2564 is 0000101000000100 

// Terminal Input:
// $gcc lab2q1.c -o lab2q1
// $./lab2q1 150 inDec.dat outBin.dat

// Output:Content of the first ‘n’decimal and their equivalent binary numbers


// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     FILE *fin, *fout;
//     int num;
//  void dec_to_bin(int n)
//  {
//     if(n/2 != 0)
//     {
//         void dec_to_bin(int n);
//         fprintf("%d",n%2);
//     }
//  }
//  printf (" Enter the number of integers you want to convert:");
//  scanf("%d", &num);
//  FILE *fin = fopen("inDec.txt", "w");
//     if (fin == NULL) {
//         printf("Error opening input file\n");
//         extit(1);
//     }
//     else
//     {
//         for(int i=0; i<num; i++)
//         {
//             fprintf(fin, "%d", num);
//             // n = num;
//             dec_to_bin(num);
//         }
//     }
 
//  for(int i=0; i<num; i++)
//  {

//  }
// }

#include <stdio.h>
#include <stdlib.h>

int binary_rec( int num)
    {
        FILE *qptr;
        if (num == 0)
        {
            return 0;
        }
        else
        {
            return ((num % 2) + 10 * binary_rec( num/2));
        }
    }

int main() 
{
    int binary;
    FILE *fptr, *qptr;
    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    int n, num;
    printf("Enter no of  decimal values want to convert: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        fprintf(fptr, "\n%d",num);
        binary_rec( num);
    }
    qptr = fopen("output.txt","w");
    if (qptr == NULL)
    {
        printf("Error opening the output file.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
        
      //        int binary = binary_rec(qptr, num);

        binary = binary_rec(num);
        fprintf(qptr, "Binary Equivalent of %d is %d\n\n", num, binary);
    }
    // for(int i=0; i<n; i++)
    // {
    //     fprintf(qptr,"Binary Equivalent of %d is %d\n\n", num, binary);
    // }

    // Write the binary equivalent to the file
    // fprintf(fptr, "%d", binary);

    fclose(fptr);
    fclose(qptr);
    return 0;
}