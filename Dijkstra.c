#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void printPath(int parent[], int j, char vertices[]) {
    if (parent[j] == -1)
        return;
    
    printPath(parent, parent[j], vertices);
    printf(" -> %c", vertices[j]);
}

void printSolution(int dist[], int parent[], int V, int src, char vertices[]) {
    printf("\nVertex\tDistance\tPath\n");
    
    for (int i = 0; i < V; i++) {
        if (i != src) {
            printf("%c\t%d\t\t%c", vertices[i], dist[i], vertices[src]);
            printPath(parent, i, vertices);
            printf("\n");
        } else {
            printf("%c\t%d\t\t%c\n", vertices[i], dist[i], vertices[i]);
        }
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V, char vertices[]) {
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];
    int parent[MAX_VERTICES];
    
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printSolution(dist, parent, V, src, vertices);
}

int main() {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];
    char vertices[MAX_VERTICES];
    int source_index;
    char source_vertex;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    printf("Enter the names of the vertices (single characters): ");
    getchar();
    for (int i = 0; i < V; i++) {
        scanf("%c", &vertices[i]);
        getchar();
    }
    
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    printf("Use 0 for no edge and positive value for edge weight:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the source vertex name: ");
    getchar();
    scanf("%c", &source_vertex);
    
    for (int i = 0; i < V; i++) {
        if (vertices[i] == source_vertex) {
            source_index = i;
            break;
        }
    }
    
    dijkstra(graph, source_index, V, vertices);
    
    return 0;
}
