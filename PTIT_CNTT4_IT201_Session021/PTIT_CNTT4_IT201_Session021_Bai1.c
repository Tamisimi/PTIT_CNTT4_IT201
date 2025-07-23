#include <stdio.h>

int graph[3][3];

void initGraph() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            graph[i][j] = 0;
}

void addEdge(int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

void printGraph() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    initGraph();
    printf("Do thi ban dau:\n");
    printGraph();

    int firstNode = 1, secondNode = 2;
    addEdge(firstNode, secondNode);
    printf("\nDo thi sau khi them canh giua node %d va node %d:\n", firstNode, secondNode);
    printGraph();

    return 0;
}