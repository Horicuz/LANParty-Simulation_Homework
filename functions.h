#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team.h"
#include "match.h"

void checkFile(FILE *file);
void closeFiles(FILE *input1, FILE *input2, FILE *output);
int isLetterOrNumber(char c);
TEAM createTeam(FILE *file);
void printMatch(MATCH m, FILE *output);
void printWinner(MATCH m, FILE *output, int x);
