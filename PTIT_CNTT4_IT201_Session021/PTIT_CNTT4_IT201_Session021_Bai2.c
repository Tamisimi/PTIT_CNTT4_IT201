#include <stdio.h>

int graph[4][4];

void initGraph() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            graph[i][j] = 0;
}

void addEdge(int firstNode, int secondNode) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

void printGraph() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

int main() {
    initGraph();
    printf("Do thi ban dau:\n");
    printGraph();
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);
    
    printf("\nDo thi sau khi them cac canh:\n");
    printGraph();
    
    return 0;
}