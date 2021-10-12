#include <stdio.h>

// main function of program
int main()
{
    // read all numbers from input file
    int c;
    FILE *file;
    file = fopen("COSC450_P1_Data.txt", "r");
    if (file)
    {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    return 0;
}