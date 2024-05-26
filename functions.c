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

int isLetterOrNumber(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

TEAM createTeam(FILE *file) // read the team info from the file
{
    TEAM t;
    char auxChar;
    float teamPoints = 0;

    fscanf(file, "%d", &t.playerCount);
    t.players = (PLAYER *)malloc(t.playerCount * sizeof(PLAYER));
    fscanf(file, "%c", &auxChar);
    t.name = (char *)malloc(100 * sizeof(char));
    while (fscanf(file, "%c", &auxChar) && auxChar != '\n')
    {
        t.name[strlen(t.name)] = auxChar;
    }
    for (int i = strlen(t.name) - 1; i >= 0; i--)
    {
        if (isLetterOrNumber(t.name[i]) == 0)
        {
            t.name[i] = '\0';
        }
        else
        {
            t.name[i + 1] = '\0';
            break;
        }
    }

    for (int i = 0; i < t.playerCount; i++)
    {
        t.players[i].firstName = (char *)malloc(100 * sizeof(char));
        t.players[i].secondName = (char *)malloc(100 * sizeof(char));

        fscanf(file, "%s", t.players[i].firstName);
        fscanf(file, "%s", t.players[i].secondName);
        fscanf(file, "%d", &t.players[i].points);

        teamPoints += (float)t.players[i].points;
    }

    teamPoints /= (float)t.playerCount;
    t.teamPoints = teamPoints;

    return t;
}

void printMatch(MATCH m, FILE *output)
{
    fprintf(output, "%s", m.team1->val.name);
    for (int i = 1; i <= 33 - strlen(m.team1->val.name); i++)
        fprintf(output, " ");
    fprintf(output, "-");
    for (int i = 1; i <= 33 - strlen(m.team2->val.name); i++)
        fprintf(output, " ");
    fprintf(output, "%s\n", m.team2->val.name);
}

void printWinner(MATCH m, FILE *output, int x)
{
    if (x == 1)
    {
        fprintf(output, "%s", m.team1->val.name);
        for (int i = 1; i <= 34 - strlen(m.team1->val.name); i++)
            fprintf(output, " ");
        fprintf(output, "-  %.2f\n", m.team1->val.teamPoints);
    }
    else
    {
        fprintf(output, "%s", m.team2->val.name);
        for (int i = 1; i <= 34 - strlen(m.team2->val.name); i++)
            fprintf(output, " ");
        fprintf(output, "-  %.2f\n", m.team2->val.teamPoints);
    }
}