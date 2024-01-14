#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define MAX 100
typedef struct Edge
{
    int src, dest, wt;

}Edge;

typedef struct Graph
{
    int E, V;
    Edge edges[MAX];
}Graph;

int find(int paresnts[], int i){
    if(paresnts[i]==-1)
        return i;
    return find(paresnts, paresnts[i]);
}

Graph* createGraph(int V, int E){
    Graph * graph = (Graph * )malloc(sizeof(Graph*));
    graph->E = E;
    graph->V = V;
    return graph; 
}

void union_set(int parent[], int x, int y ){
    parent[x] = y;
}

int compare(const void * a, const void * b){
    Edge* e1 = (Edge *)a;
    Edge* e2 = (Edge *)b;
    return e1->wt - e2->wt;

}

void kruskal(Graph * graph){
    int parent[MAX];
    memset(parent, -1, sizeof(parent));
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]),compare);
    int i , j,u,v;
    for (int i=0;i<graph->E;i++){
        u = find(parent,graph->edges[i].src);
        v = find(parent,graph->edges[i].dest);

        if(u != v){
            printf("%d -- %d  \n",graph->edges[i].src, graph->edges[i].dest );
            union_set(parent,u, v);
        }

    }
}

int main() {
    int V = 5;
    int E = 5;
    
    struct Graph* graph = createGraph(V, E);
    
    // add edges to the graph
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].wt = 10;
    
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].wt = 6;
    
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].wt = 5;
    
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].wt = 15;
    
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].wt = 4;

    graph->edges[5].src = 4;
    graph->edges[5].dest = 3;
    graph->edges[5].wt = 6;
    
    kruskal(graph);
    
    return 0;
}