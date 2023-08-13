#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *sFile, *dFile;
    char ch;

    sFile = fopen("input.txt", "r");
    if (sFile == NULL) 
    {
        printf("Error opening source file");
        return 1;
    }
    dFile = fopen("output.txt", "w");
    if (dFile == NULL) 
    {
        printf("Error opening destination file");
        fclose(sFile);
        return 1;
    }
    while ((ch = fgetc(sFile)) != EOF) 
    {
        fputc(ch, dFile);
    }
    printf("Content successfully copied.\n");
    return 0;
}
