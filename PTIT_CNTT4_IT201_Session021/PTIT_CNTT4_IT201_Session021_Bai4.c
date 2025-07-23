#include <stdio.h>

int graph[3][3];

void initGraph() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            graph[i][j] = 0;
}

void addEdge(int startNode, int endNode) {
    graph[startNode][endNode] = 1;
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
    
    addEdge(1, 0);
    addEdge(1, 2);
    addEdge(2, 0);
    
    printf("\nDo thi sau khi them cac canh:\n");
    printGraph();
    
    return 0;
}