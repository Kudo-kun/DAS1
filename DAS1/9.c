#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 1440
#define endl printf("\n") 
#define read(x) scanf("%d", &x)
#define print(x) printf("%d ", x);


void increaseCount(int l, int r, int arr[])
{
	for(int i = l; i <= r; i++)
		arr[i]++;
}

int findMax(int arr[])
{
	int max = 0;
	for(int i = 0; i < N; i++)
		if(arr[i] >= max)
			max = arr[i];

	return max;
}


int main()
{
	int q, arr[N], l, r;
	read(q);
	memset(arr, 0, N*sizeof(int));

	for(int i = 0; i < q; i++)
	{
		read(l); read(r);
		increaseCount(l, r, arr);
	}
	printf("%d\n", findMax(arr));
	return 0;
}
