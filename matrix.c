#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// init variables
int SIZE;
int c;
int *inputArray;
int currentNumber;
FILE *inputFile;
FILE *outputFile;

void process_input_file()
{
    // read all numbers from input file
    // open the input file
    inputFile = fopen("COSC450_P1_Data.txt", "r");
    if (inputFile == NULL)
    {
        // file not found
        printf("Input File not found!\n");
        exit(-1);
    }

    //index to keep track of which char we are on
    int idx = 0;
    // put all ints into a temp array
    // read file number by number
    while (fscanf(inputFile, "%d", &currentNumber) == 1) // check if there is a next digit
    {
        inputArray[idx] = currentNumber;
        printf("Added %d to the array.\n", currentNumber);
        idx++;
    }
    // close file when done
    fclose(inputFile);
    // record idx in a size variable so that we can track the size of our arrays
    SIZE = idx + 1;
}

void create_matrices()
{
    // int s = SIZE;
    // int matrixA[s][s / 2];
}

// function that writes array to output file
void print_to_file()
{
    // remove("COSC450_P1_Output.txt");
    outputFile = fopen("COSC450_P1_Output.txt", "w");
    if (outputFile == NULL)
    {
        // file not found
        printf("Output file not found!\n");
        exit(-1);
    }
    for (int i = 0; i < SIZE - 1; i++)
    {
        fprintf(outputFile, "Some text: %d\n", inputArray[i]);
    }

    fclose(outputFile);
    return;
}

// main function of program
int main()
{
    process_input_file();
    // create_matrices();
    print_to_file();
    return 0;
}