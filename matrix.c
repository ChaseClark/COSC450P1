#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// init variables
int SIZE;
int c;
int inputArray[100000]; // made large in case the input file is large
int currentNumber;
FILE *inputFile;
FILE *outputFile;

// this method takes our input file and reads it into an array
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

// this method takes in an 2d array pointer and prints it to the output file
void print_matrix(int **array, int rows, int cols)
{
    printf("\nPrinting matrix...\n");
    if (outputFile == NULL)
    {
        // file not found
        printf("Output file not found!\n");
        exit(-1);
    }
    // loop through each row and col and print the output
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fprintf(outputFile, "%-20d", array[i][j]);
        }
        fprintf(outputFile, "\n");
    }
}

// this method takes in an 2d long array pointer and prints it to the output file
void print_long_matrix(long **array, int rows, int cols)
{
    printf("\nPrinting matrix...\n");
    if (outputFile == NULL)
    {
        // file not found
        printf("Output file not found!\n");
        exit(-1);
    }
    // loop through each row and col and print the output
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fprintf(outputFile, "%-20d", array[i][j]);
        }
        fprintf(outputFile, "\n");
    }
}

// create our matrices and multiply them together
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

    // create a reference to our input array's index
    int input_idx = 0;

    // loop through each index in the matrix
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < x; j++)
        {
            // add the input to Matrix A
            matrixA[i][j] = inputArray[input_idx];
            input_idx++;
        }
    }
    fprintf(outputFile, "Matrix A\n=======================================\n");
    print_matrix(matrixA, 5, x);

    // matrix B
    // dimensions of matrix B is X * 5
    int **matrixB;

    // allocate an array of array for matrixB
    matrixB = (int **)malloc(x * sizeof(int *));
    // allocate space for each entry in matrixB
    for (int i = 0; i < x; i++)
    {
        matrixB[i] = (int *)malloc(5 * sizeof(int));
    }

    input_idx = 0;

    // loop through each index in the matrix
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // add the input to Matrix B
            matrixB[i][j] = inputArray[input_idx];
            input_idx++;
        }
    }
    fprintf(outputFile, "\n\nMatrix B\n=======================================\n");
    print_matrix(matrixB, x, 5);

    // product matrix
    // this will be a 5 x 5 matrix
    long **productMatrix;

    // allocate an array of array for productMatrix
    productMatrix = (long **)malloc(5 * sizeof(long *));
    // allocate space for each entry in productMatrix
    for (int i = 0; i < 5; i++)
    {
        productMatrix[i] = (long *)malloc(5 * sizeof(long));
    }

    // multiply each row in matrixA by each col in maxtrixB
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            long sum = 0;
            // now we need to loop through and calculate
            for (int i = 0; i < x; i++)
            {
                printf("%d * %d +", matrixA[r][i], matrixB[i][c]);
                sum += (long)(matrixA[r][i] * matrixB[i][c]);
            }
            productMatrix[r][c] = sum;
            printf("---- row: %d, col: %d, sum: %d\n", r, c, sum);
        }
    }
    fprintf(outputFile, "\n\nProduct Matrix\n=======================================\n");
    print_long_matrix(productMatrix, 5, 5);
}

// main function of program
int main()
{
    outputFile = fopen("COSC450_P1_Output.txt", "w");
    process_input_file();
    create_matrices();
    fclose(outputFile);
    return 0;
}