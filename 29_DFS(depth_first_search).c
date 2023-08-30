#include <stdio.h>
#include <stdlib.h>
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};
void dfs(int i)
{
    visited[i] = 1;
    printf(" %d", i);
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
        {

            visited[j] = 1;
            dfs(j);
        }
    }
}
int main()
{
    dfs(6);

    return 0;
}
