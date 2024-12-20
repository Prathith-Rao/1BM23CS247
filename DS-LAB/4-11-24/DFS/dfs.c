#include <stdio.h>

#define MAX_NODES 100

int adjacencyMatrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int nodes;

// Function for DFS
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);  // Print visited node

    for (int i = 0; i < nodes; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Function to check if the graph is connected
int isConnected() {
    // Initialize visited array to 0
    for (int i = 0; i < nodes; i++) {
        visited[i] = 0;
    }

    // Start DFS from node 0
    DFS(0);

    // Check if all nodes are visited
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            return 0;  // Graph is not connected
        }
    }
    return 1;  // Graph is connected
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Check connectivity
    if (isConnected()) {
        printf("\nThe graph is connected.\n");
    } else {
        printf("\nThe graph is not connected.\n");
    }

    return 0;
}
