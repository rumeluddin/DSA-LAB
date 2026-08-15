#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    int item = queue[front];
    front++;
    return item;
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void bfs(int adj[MAX][MAX], int vertices, int startNode) {
    bool visited[MAX] = {false};

    visited[startNode] = true;
    enqueue(startNode);

    printf("BFS Traversal Order: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
    printf("\n");
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

    int startNode = 0;
    bfs(adj, vertices, startNode);

    return 0;
}
