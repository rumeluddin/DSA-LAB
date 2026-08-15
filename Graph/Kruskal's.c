#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

int parent[100];

int findParent(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent[i]);
}

void unionSets(int i, int j) {
    int root_i = findParent(i);
    int root_j = findParent(j);
    parent[root_i] = root_j;
}

int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

void kruskal(struct Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;
    int edgesCount = 0;

    printf("Edges in Minimum Spanning Tree (MST):\n");
    for (int i = 0; i < E && edgesCount < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        if (findParent(u) != findParent(v)) {
            unionSets(u, v);
            printf("%d -- %d == %d\n", u, v, w);
            mstWeight += w;
            edgesCount++;
        }
    }

    printf("Total Minimum Cost: %d\n", mstWeight);
}

int main() {
    int V = 4;
    int E = 5;

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

    return 0;
}
