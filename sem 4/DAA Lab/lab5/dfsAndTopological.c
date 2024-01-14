#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// function prototypes
void dfs(int vertex);
void topological_sort_dfs();
void topological_sort_source_removal();

// adjacency list node structure
typedef struct node {
    int vertex;
    struct node* next;
} node;

// graph structure
typedef struct graph {
    node* vertices[MAX_VERTICES];
    int indegrees[MAX_VERTICES];
    int num_vertices;
    int num_edges;
} graph;

// global variables
graph g;
int visited[MAX_VERTICES];
int topo_sorted[MAX_VERTICES];
int topo_sorted_index = 0;

// function to create a new node
node* new_node(int vertex) {
    node* new = (node*)malloc(sizeof(node));
    new->vertex = vertex;
    new->next = NULL;
    return new;
}

// function to add an edge to the graph
void add_edge(int u, int v) {
    node* new = new_node(v);
    new->next = g.vertices[u];
    g.vertices[u] = new;
    g.indegrees[v]++;
    g.num_edges++;
}

// function to perform depth-first search
void dfs(int vertex) {
    visited[vertex] = 1;
    node* adj_list = g.vertices[vertex];
    while (adj_list != NULL) {
        int adjacent_vertex = adj_list->vertex;
        if (!visited[adjacent_vertex]) {
            dfs(adjacent_vertex);
        }
        adj_list = adj_list->next;
    }
    topo_sorted[topo_sorted_index++] = vertex;
}

// function to perform topological sort using depth-first search
void topological_sort_dfs() {
    int i;
    for (i = 0; i < g.num_vertices; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < g.num_vertices; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    printf("Topological Sort (DFS): ");
    for (i = g.num_vertices - 1; i >= 0; i--) {
        printf("%d ", topo_sorted[i]);
    }
    printf("\n");
}

// function to perform topological sort using source removal technique
void topological_sort_source_removal() {
    int i, j;
    for (i = 0; i < g.num_vertices; i++) {
        visited[i] = 0;
    }
    printf("Topological Sort (Source Removal): ");
    for (i = 0; i < g.num_vertices; i++) {
        // find a vertex with indegree 0
        int found = 0;
        for (j = 0; j < g.num_vertices; j++) {
            if (g.indegrees[j] == 0 && !visited[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nError: Graph contains a cycle\n");
            return;
        }
        visited[j] = 1;
        node* adj_list = g.vertices[j];
        while (adj_list != NULL) {
            int adjacent_vertex = adj_list->vertex;
            g.indegrees[adjacent_vertex]--;
            adj_list = adj_list->next;
        }
        printf("%d ", j);
    }
    printf("\n");
}

int main() {
    int i, num_vertices, num_edges, u, v;
    
    // read in number of vertices and edges
printf("Enter the number of vertices: ");
scanf("%d", &num_vertices);
printf("Enter the number of edges: ");
scanf("%d", &num_edges);

// initialize graph
g.num_vertices = num_vertices;
g.num_edges = 0;
for (i = 0; i < num_vertices; i++) {
    g.vertices[i] = NULL;
    g.indegrees[i] = 0;
}

// read in edges
printf("Enter the edges:\n");
for (i = 0; i < num_edges; i++) {
    scanf("%d %d", &u, &v);
    add_edge(u, v);
}

// perform topological sort using DFS
topological_sort_dfs();

// perform topological sort using source removal
topological_sort_source_removal();

return 0;
}







