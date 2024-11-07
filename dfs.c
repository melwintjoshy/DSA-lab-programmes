#include <stdio.h>

int visited[7] ={0, 0, 0, 0, 0, 0, 0};

int adjMat[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};

void Dfs(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if(adjMat[i][j] == 1 && !visited[j])
        {
            Dfs(j);
        }
    }
}

int main()
{
    int n;
    printf("Enter the node to start the DFS: ");
    scanf("%d", &n);

    Dfs(n);
}