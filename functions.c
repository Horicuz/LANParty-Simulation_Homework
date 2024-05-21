#include "functions.h"

void checkFile(FILE *file)
{
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
}

void closeFiles(FILE *input1, FILE *input2, FILE *output)
{
    fclose(input1);
    fclose(input2);
    fclose(output);
}