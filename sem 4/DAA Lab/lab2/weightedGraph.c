#include <stdio.h>
#include <stdlib.h>
#define node *nodePtr;
#define graph *graphPtr
typedef struct graphNode
{
    int dest;
    nodePtr next;
} node;
typedef struct graphStruct
{
    int V;
    nodePtr *array;
}graph;

nodePtr newAdjListNode(int dest){
    nodePtr newNode = (nodePtr)malloc(sizeof(struct graphNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
graphPtr createGraph(int V){
    graphPtr newGraph = (graphPtr)malloc(sizeof(graphPtr));
    newGraph->V = V;
    newGraph->array = (nodePtr*)malloc(V*sizeof(struct graphNode));
    
}