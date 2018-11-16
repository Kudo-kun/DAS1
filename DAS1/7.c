#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define endl printf("\n") 
#define read(x) scanf("%d", &x)
#define print(x) printf("%d ", x)

int cnt = 0;
void swap(int* a, int* b)
{
	int tmp = *a; *a = *b; *b = tmp;
}


int find(int x, int n, int arr[])										//finds index of al particular element in an array.
{
	for(int i = 0; i < n; i++)
		if(arr[i] == x)
			return i;
}


int check(int m, int n, int arr[], int mat[][2])
{
	for(int i = 0; i < m; i++)
		if(find(mat[i][0], n, arr) > find(mat[i][1], n, arr))			//checks if the elements of the array are in the expected order.
			return 0;
	
	return 1;
}


void Topo_sort_count(int m, int n, int arr[], int mat[][2], int l, int r)
{
	if(l == r && check(m, n, arr, mat))									//if a new permutation is formed which satisfies the given ordering,
		cnt++;															//increment count.
	else
	{
		for(int i = l; i <= r; i++)
		{
			swap(&arr[l], &arr[i]);										//swap elemnts of array, to create a new permutation.
			Topo_sort_count(m, n, arr, mat, l+1, r);					//recurse.
			swap(&arr[l], &arr[i]);										//re-swap to backtrack.				
		}
	}
}




int main()
{
	int n, m;
	read(n); read(m);
	int mat[m][2], arr[n];
	
	for(int i = 0; i < n; i++)	
		arr[i] = i;
		
	for(int i = 0; i < m; i++)
		scanf("%d%d", &mat[i][0], &mat[i][1]);

	Topo_sort_count(m, n, arr, mat, 0, n-1);							//counts all the permutations that satisfy the expected ordering.
	(!cnt) ? printf("-1\n") : printf("%d\n", cnt);						//print -1, if no combination is possible.
	return 0;
}