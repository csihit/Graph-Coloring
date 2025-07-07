#include <stdio.h>
#include <stdbool.h>

#define MAX 20

bool isSafe(int v, bool graph[MAX][MAX], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoring(bool graph[MAX][MAX], int m, int color[], int v, int V) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if (graphColoring(graph, m, color, v + 1, V))
                return true;
            color[v] = 0;  // backtrack
        }
    }
    return false;
}

int main() {
    int V, E, m;
    bool graph[MAX][MAX] = {false};
    int color[MAX] = {0};

    printf("Enter number of vertices = ");
    scanf("%d", &V);
    printf("Enter number of edges = ");
    scanf("%d", &E);

    printf("Enter the edges (u v) :-\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = true;
        graph[v][u] = true;
    }

    printf("Enter the number of colors (M) = ");
    scanf("%d", &m);

    if (graphColoring(graph, m, color, 0, V)) {
        printf("Solution exists. Vertex colors :-\n");
        for (int i = 0; i < V; i++)
            printf("Vertex %d ---> Color %d\n", i, color[i]);
    } else {
        printf("No solution exists with %d colors.\n", m);
    }

    return 0;
}
