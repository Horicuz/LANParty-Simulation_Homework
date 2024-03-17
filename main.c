#include <stdio.h>

int main(int argc, char* argv[]) {
    
    FILE *input1, *input2, *output;

    input1 = fopen(argv[1], "r");
    input2 = fopen(argv[2], "r");
    output = fopen(argv[3], "w");

    //read from input1 and write to output



    fclose(input1);
    fclose(input2);
    fclose(output);

    return 0;
}