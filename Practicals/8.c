//8. Program for detection of single node failure in a network

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct node{
    int v;
    struct node* next;
};

void addEdge(struct node *adj[],int u, int v)
{
    struct node* t=malloc(sizeof(struct node));
    t->v=v;
    t->next=adj[u];
    adj[u]=t;

    t=malloc(sizeof(struct node));
    t->v=u;
    t->next=adj[v];
    adj[v]=t;
}

void dfs(struct node* adj[], int node, int failed, int visited[])
{
    visited[node]=1;
    for(struct node*t =adj[node];t!=NULL; t=t->next)
    {
        if(t->v!=failed && visited[t->v]==0)
        {
            dfs(adj, t->v, failed, visited);
        }
    }
}

int main()
{
    struct node* adj[MAX]={0};
    int n,e,failed;
    printf("Nodes: ");
    scanf("%d", &n);
    printf("Edges: ");
    scanf("%d", &e);
    printf("Enter edges:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    printf("Failed node: ");
    scanf("%d", &failed);
    int visited[MAX] = {0};
    int start = (failed == 0) ? 1 : 0;
    dfs(adj, start, failed, visited);

    int disconnected = 0;
    for (int i = 0; i < n; i++) {
        if (i != failed && visited[i] == 0)
            disconnected = 1;
    }
    if (disconnected)
    printf("Network DISCONNECTED after node %d fails\n", failed);
    else
        printf("Network CONNECTED after node %d fails\n", failed);

}