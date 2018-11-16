#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define endl printf("\n") 
#define read(x) scanf("%d", &x)
#define print(x) printf("%d ", x)


void setMat(int n, int mat[][n])
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			mat[i][j] = 0;
}


void DFS(int n, int mat[][n], int x)
{
	for(int j = 0; j < n; j++)
	{
		if(mat[x][j] == 1)										//if a secondary DFS point is again found.
		{
			mat[x][j] = -1;	mat[j][x] = -1;						//mark given point and its symmetric opposite point as well.
			DFS(n, mat, j);										//DFS again, and explore all routes.
		}
	}
	return;
}


int Untouched(int n, int arr[])
{
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(arr[i] == 0)
			cnt++;

	return cnt;

}


int main()
{
	int n, q, x, y, ans = 0;
	read(n); read(q);
	int mat[n][n], taps[n];
	setMat(n, mat); memset(0, arr, n*sizeof(int));

	for(int i = 0; i < q; i++)
	{
		read(x); read(y);
		mat[x][y] = 1; mat[y][x] = 1;								//create symmetric adjacency matrix, as given graph is undirected.
		taps[x] = 1; taps[y] = 1;									//marks the junctions that are connected.
	}

	ans += Untouched(n, taps);										//check how many junctions are not connected, they have to be opened individually.
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(mat[i][j] == 1)										//if point is a DFS point,
			{
				mat[i][j] = -1; mat[j][i] = -1;						//mark it as visited(also mark its symmetric opposite). 
				DFS(n, mat, j);										//DFS again at that point.
				ans++; 												//increment count after exploring all routes.
			}
		}
	}

	print(ans); endl;
	return 0;
}
