// 9 Implement an Algorithm for detecting cycle in given
// graph Graph
// i. Accept graph as input from file
// ii. Accept graph as input in the form of adjacency list
// iii. Accept graph as input in the form of adjacency
// matrix
#include <stdio.h>

int adj[100][100], visited[100], n;

int dfs(int v, int parent) {
    visited[v] = 1;
    for(int u=0; u<n; u++) {
        if(adj[v][u]) {
            if(!visited[u]) {
                if(dfs(u, v)) return 1;
            } else if(u != parent)
                return 1;
        }
    }
    return 0;
}

int hasCycle() {
    for(int i=0; i<n; i++) visited[i] = 0;
    for(int i=0; i<n; i++)
        if(!visited[i])
            if(dfs(i, -1)) return 1;
    return 0;
}

int main() {
    int choice, e, u, v;

    printf("1.File  2.Adjacency List  3.Adjacency Matrix\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    
    if(choice == 1) {
        FILE *fp = fopen("graph.txt", "r");
        fscanf(fp, "%d", &n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                fscanf(fp, "%d", &adj[i][j]);
        fclose(fp);
    }

    
    else if(choice == 2) {
        printf("Enter number of nodes: ");
        scanf("%d", &n);

        printf("Enter number of edges: ");
        scanf("%d", &e);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j] = 0;

        printf("Enter edges (u v):\n");
        for(int i=0;i<e;i++) {
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = 1;
        }
    }

    
    else if(choice == 3) {
        printf("Enter number of nodes: ");
        scanf("%d", &n);

        printf("Enter adjacency matrix:\n");
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d", &adj[i][j]);
    }

    
    if(hasCycle())
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");

    return 0;
}
