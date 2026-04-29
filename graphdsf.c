#include <stdio.h>

#define MAX 100

int matrix[MAX][MAX];
int visited[MAX];
int n;

// DFS Function
void dfs(int city)
{
    int i;
    visited[city] = 1;
    printf("%d ", city);

    for(i = 0; i < n; i++)
    {
        if(matrix[city][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter connectivity matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter starting city: ");
    scanf("%d", &start);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("Reachable cities are:\n");
    dfs(start);

    return 0;
}
