#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define endl printf("\n") 
#define read(x) scanf("%d", &x)
#define print(x) printf("%d ", x)
#define decorate printf("*****************\n")


void printRow(int i, int n, int mat[][N])
{
	for(int j = 0; j < n; j++)
		print(mat[i][j]);

	endl;
}

void printPartitions(int x, int n, int mat[][N])
{
	for(int i = 1; i < (1 << n-1); i++)
	{
		for(int j = (1 << n-1), k = n-1; j > 0; j >>= 1, k--)					//print all subsets of a given row.				
			if(i & j)															//moves a one along the binary number, and checks if one is present at that particular location.
				print(mat[x][k]);			
		endl;
		
		for(int j = (1 << n-1), k = n-1; j > 0; j >>= 1, k--)					//prints the remaining elements as a set.
			if((i & j) == 0)													//moves a one along the binary number, and checks if zero is present at that particular location.
				print(mat[x][k]);
		endl;		
	}
}




int main()
{
	int n;
	read(n);
	int l[n], mat[n][N];

	for(int i = 0; i < n; i++)
	{
		read(l[i]);
		for(int j = 0; j < l[i]; j++)
			read(mat[i][j]);	
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j && n != 1)											//if we have more than more row, partition one row at a time.
				printPartitions(j, l[j], mat); 
			else if(i == j && n == 1)										//if we have only one row, partition that and exit.
				{printPartitions(j, l[j], mat); decorate; return 0;}	
			else 
				printRow(j, l[j], mat);										//print rest of the unpartitoned rows.
		}
		decorate;
	}
	return 0;
}