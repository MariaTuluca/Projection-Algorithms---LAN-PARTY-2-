#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// acest header conține apeluri de funcții ajutătoare pentru task-ul acesta
#define numberOfNodes 32 

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

void creareMeciuriTurneu(Graph *TeamsGraph, FILE *date_output);
