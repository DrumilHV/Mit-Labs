
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 1000

// structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// structure to represent a graph
struct Graph {
    int V, E;
    struct Edge edges[MAX];
};

// function to create a new graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

// find function for disjoint sets
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// union function for disjoint sets
void union_set(int parent[], int x, int y) {
    parent[x] = y;
}

// comparison function for sorting edges in ascending order of weight
int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

// function to find MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph) {
    int parent[MAX];
    memset(parent, -1, sizeof(parent)); // initialize parent array to -1
    
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compare); // sort edges in ascending order of weight
    
    int i, j, u, v;
    for (i = 0; i < graph->E; i++) {
        u = find(parent, graph->edges[i].src);
        v = find(parent, graph->edges[i].dest);
        
        if (u != v) {
            printf("%d - %d\n", graph->edges[i].src, graph->edges[i].dest);
            union_set(parent, u, v);
        }
    }
}

// main function
int main() {
    int V = 4;
    int E = 5;
    
    struct Graph* graph = createGraph(V, E);
    
    // add edges to the graph
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;
    
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;
    
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;
    
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;
    
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;
    
    KruskalMST(graph);
    
    return 0;
}
