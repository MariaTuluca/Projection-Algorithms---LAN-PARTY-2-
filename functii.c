#include "functii.h"

//funcție pentru citire date și creare matrice de adiacență
void citireDate(Graph **TeamsGraph, FILE *date_input)
{
    for(int i=0; i<numberOfNodes; i++)
    {   float score;
        char name[100];
        //citesc scorul
        fscanf(date_input, "%f", &score);
        (*TeamsGraph)->nodes[i].scoreOfTeam = score;
        //elimin spațiul dintre scor și nume, citesc numele
        fscanf(date_input," ");
        fscanf(date_input, "%s", name);

        (*TeamsGraph)->nodes[i].teamName = (char*)malloc((strlen(name) + 1)*sizeof(char));
        strcpy((*TeamsGraph)->nodes[i].teamName, name);
        //actualizez poziția
        (*TeamsGraph)->nodes[i].position = i;
        (*TeamsGraph)->nodes[i].numberOfWins = 0;
    }

    for(int i = 0; i < numberOfNodes; i++)
    {for(int j = 0; j < numberOfNodes; j++)
        (*TeamsGraph)->a[i][j] = 0;
    }
}

//funcție pentru creare coadă
Queue *createQueue()
{
    Queue *q;
    q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

//funcție pentru adăugare în coadă
void enQueue(Queue *q, GraphNode *node)
{
    if (q->front == NULL)
        q->rear = NULL;

    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->subject = node;
    newNode->next = NULL;
    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
    if (q->front == NULL)
        q->front = q->rear = newNode;
}

//funcție pentru eliminare din coadă
GraphNode *deQueue(Queue *q)
{
    QueueNode *aux = q->front;
    GraphNode *d = aux->subject;

    if (q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;

    free(aux);
    return d;
}

//funcție pentru ștergere coadă
void deleteQueue(Queue *q)
{
    QueueNode *aux;
    while (q != NULL)
    {
        aux = q->front;
        q->front = q->front->next;
        free(aux);
    }
    free(q);
    q = NULL;
}

//funcție pentru afișare matrice
void scrieMatriceAdiacenta(Graph *TeamsGraph, FILE *date_output)
{
    for(int i = 0; i<numberOfNodes; i++)
    {
        for(int j = 0; j<numberOfNodes; j++)
        {fprintf(date_output, "%d ", TeamsGraph->a[i][j]);
        }
        fprintf(date_output, "\n");
    }
}

//funcție pentru manipularea meci-urilor din coadă    
void creareMeciuriTurneu(Graph *TeamsGraph, FILE *date_output)
{   //creez coada de meciuri
    Queue *matches = createQueue(); 
    for(int i = 0; i<numberOfNodes; i++)
        enQueue(matches, &TeamsGraph->nodes[i]);
        
    Queue *losers = createQueue();
    //cât timp coada nu e goală
    while(matches->front != matches->rear)
    {
        Queue *newRound = createQueue();
        while(matches->front != NULL)
        {   //procesez câte două echipe
            GraphNode *team_A = deQueue(matches), *team_B = deQueue(matches);
            //creez câte un nod pentru fiecare echipă din meci, câștigătoare și pierzătoare
            GraphNode *winner, *loser;

            if(team_A == NULL && team_B == NULL)
                { printf("Eroare la desfășurare turneu!");
                   return;}
            //actualizez winner and losers
            if(team_A->scoreOfTeam < team_B->scoreOfTeam || (team_A->scoreOfTeam == team_B->scoreOfTeam && strcmp(team_A->teamName, team_B->teamName)))
                {loser = team_A;
                 winner = team_B;}
            else if(team_A->scoreOfTeam > team_B->scoreOfTeam || (team_A->scoreOfTeam == team_B->scoreOfTeam && strcmp(team_A->teamName, team_B->teamName)))
                {loser = team_B;
                 winner = team_A;}
            //actualizez numărul de muchii și matricea de adiacență
            TeamsGraph->E++; 
            TeamsGraph->a[loser->position][winner->position] = 1;
            enQueue(newRound, winner); //reînnoiesc cozile
            enQueue(losers, loser);
        }//eliberez spațiul și reînnoiesc coada de meciuri
    free(matches);
    matches = newRound;
    }
    free(matches);
    free(losers); //scriu matricea de adiacență
    scrieMatriceAdiacenta(TeamsGraph, date_output);
}


