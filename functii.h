#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// acest header conține apeluri de funcții ajutătoare pentru task-ul acesta
#define numberOfNodes 32 
#define parameter 0.15

typedef struct graphNode
{   
    char *teamName;
    int position;
    float scoreOfTeam;
    int numberOfWins;
}GraphNode;

typedef struct graph
{
    int V;
    int E;
    int a[numberOfNodes][numberOfNodes];
    GraphNode nodes[numberOfNodes];
}Graph;

typedef struct queueNode{
    GraphNode *subject;
    struct queueNode *next;
}QueueNode;

typedef struct Queue{
    QueueNode *front, *rear;
}Queue;

void citireDate(Graph **TeamsGraph, FILE *date_input);

Queue *createQueue();

void enQueue(Queue *q, GraphNode *node);

GraphNode *deQueue(Queue *q);

void deleteQueue(Queue *q);

void scrieMatriceAdiacenta(Graph *TeamsGraph, FILE *date_output);

void calculeazaPrestigiu(Graph *TeamsGraph, Queue *order, FILE *output);

void creareMeciuriTurneu(Graph *TeamsGraph, FILE *date_output, FILE *date_output2);
