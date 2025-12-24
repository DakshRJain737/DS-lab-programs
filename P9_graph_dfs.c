#include <stdio.h>

int n;
int a[10][10];
int vis[10];

void dfs(int v)
{
    int j;
    vis[v] = 1;
    printf("%d ", v);

    for (j = 1; j <= n; j++)
    {
        if (a[v][j] == 1 && vis[j] == 0)
        {
            dfs(j);
        }
    }
}

int main()
{
    int i, j, count = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }

    printf("DFS traversal starting from vertex 1: ");
    dfs(1);

    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
            count++;
    }

    if (count == n)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");

    return 0;
}
