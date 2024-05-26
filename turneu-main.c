#include "functii.h"

// acesta este "main"-ul temei 2

int main(int argc, char *argv[])
{   //pregătesc fișierele pentru input și output
    if (argc <= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    char *input = argv[1];
    char *output = argv[2];

    FILE *date_input = fopen(input, "rt"), *date_output = fopen(output, "wt");
    if(date_input == NULL)
    {printf("Eroare la deschidere fișier citire!");
     exit(1);}

    Graph *TeamsGraph = (Graph*)malloc(sizeof(Graph));
    TeamsGraph->V = numberOfNodes;
    citireDate(&TeamsGraph, date_input);
    fclose(date_input);

    if(date_output == NULL)
    {printf("Eroare la deschidere fișier afișare!");
     exit(1);}

    creareMeciuriTurneu(TeamsGraph, date_output);

    fclose(date_output);
}
