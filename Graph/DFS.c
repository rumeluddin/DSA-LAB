#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void dfs(int adj[MAX][MAX], bool visited[MAX], int vertices, int current) {
    visited[current] = true;
    printf("%d ", current);

    for (int i = 0; i < vertices; i++) {
        if (adj[current][i] == 1 && !visited[i]) {
            dfs(adj, visited, vertices, i);
        }
    }
}

int main() {
    int vertices = 5;

    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    bool visited[MAX] = {false};

    printf("DFS Traversal Order: ");
    dfs(adj, visited, vertices, 0);
    printf("\n");

    return 0;
}
