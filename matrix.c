#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// init variables
int SIZE;
int c;
int inputArray[100000];
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

// function that writes matrix to output file
// params Array, num_rows,num_cols
void print_to_file()
{
    // remove("COSC450_P1_Output.txt");
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
    // fclose(outputFile);
    return;
}

void print_matrix(int **array, int rows, int cols)
{
    printf("\nPrinting matrix...\n");
    if (outputFile == NULL)
    {
        // file not found
        printf("Output file not found!\n");
        exit(-1);
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fprintf(outputFile, "array value: %d\n", array[i][j]);
        }
    }
}

void create_matrices()
{
    int x = SIZE / 5;
    // dimensions of matrix A is 5 * X
    int **matrixA;

    // allocate an array of array for matrixA
    matrixA = (int **)malloc(5 * sizeof(int *));
    // allocate space for each entry in matrixA
    for (int i = 0; i < 5; i++)
    {
        matrixA[i] = (int *)malloc(x * sizeof(int));
    }

    // dimensions of matrix B is X * 5
    // int matrixB[SIZE / 5][5];
    int input_idx = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < (SIZE / 5); j++)
        {
            matrixA[i][j] = inputArray[input_idx];
            input_idx++;
        }
    }

    print_matrix(matrixA, 5, x);
}

// main function of program
int main()
{
    outputFile = fopen("COSC450_P1_Output.txt", "w");
    process_input_file();
    create_matrices();
    // print_to_file();
    fclose(outputFile);
    return 0;
}