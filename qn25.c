#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void DFSUsingStack(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int top = -1;

    stack[++top] = startVertex;
    visited[startVertex] = 1;

    printf("DFS Traversal: ");
    while (top >= 0) {
        int currentVertex = stack[top--];
        printf("%d ", currentVertex + 1);  

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                stack[++top] = i;  
            }
        }
    }
    printf("\n");
}

void BFSUsingQueue(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES], front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS Traversal: ");
    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex + 1);  

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i; 
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph graph;
    int vertices, edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    graph.vertices = vertices;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph.adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (v1 v2 format):\n");
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph.adjMatrix[v1 - 1][v2 - 1] = 1;
        graph.adjMatrix[v2 - 1][v1 - 1] = 1;  
    }

    printf("Enter the starting vertex for DFS and BFS: ");
    scanf("%d", &startVertex);
    startVertex -= 1; 

    DFSUsingStack(&graph, startVertex);
    BFSUsingQueue(&graph, startVertex);

    return 0;
}
