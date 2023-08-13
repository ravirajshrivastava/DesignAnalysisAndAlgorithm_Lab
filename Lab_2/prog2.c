// Write a program in C to find GCD of two numbers using recursion.Read
// all pair of numbers from a fileand store the result in a separate file.
// Note# Source file name and destination file name taken from command line arguments. The
// source file must contain at least 20 pairs of numbers.

#include <stdio.h>

// Recursive function to find the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments are provided
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Open the source file for reading
    FILE *sFile = fopen(argv[1], "w");
    if (sFile == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    // Open the destination file for writing
    FILE *destinationFile = fopen(argv[2], "w");
    if (destinationFile == NULL) {
        printf("Error opening destination file.\n");
        fclose(sFile);
        return 1;
    }

    int num1, num2;
    while (fscanf(sFile, "%d %d", &num1, &num2) == 2) {
        // Compute the GCD using the recursive function
        int result = gcd(num1, num2);

        // Write the result to the destination file
        fprintf(destinationFile, "GCD of %d and %d is %d\n", num1, num2, result);
    }

    // Close the files
    fclose(sFile);
    fclose(destinationFile);

    printf("GCDs have been calculated and written to the destination file.\n");
    return 0;
}