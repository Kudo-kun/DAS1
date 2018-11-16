#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define endl printf("\n")


void setMat(int n, int mat[][n])
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = 0;
}


void DFS(int x, int n, int mat[n][n], int visited[])
{
	for(int j = 0; j < n; j++)										//search the row for DFS points;
	{
		if(mat[x][j] == 1 && visited[j] == 0)						//it point is a DFS point and the row hasn't been encountered already;
		{	
			printf("%d ", j); visited[j] = 1;						//then print its value and mark it;
			DFS(j, n, mat, visited);								//DFS at that point again;
		}
	}
	return;
}


int main()
{
	
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	int mat[n][n], visited[n];
	setMat(n, mat); memset(visited, 0, n*sizeof(int));

	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		mat[x][y] = 1;												//mark all DFS points;
	}

	printf("0 "); visited[0] = 1;
	for(int j = 0; j < n; j++)
	{
		if(mat[0][j] == 1)
		{
			printf("%d ", j);
			DFS(j, n, mat, visited);
		}
	}

	endl;
	return 0;
}

