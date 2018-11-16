#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#define endl printf("\n")
#define N 1000

int arr[N] = {0};
void update(int tmp[], int n, char ch)
{
	for(int i = 0; i < n; i++)
		(ch == '=') ? (arr[tmp[i]] = INT_MAX) : (arr[tmp[i]]--);
}

int MinOfArray()
{
	int min = INT_MAX;
	for(int i = 0; i < N; i++)
		if(arr[i] <= min)
			min = arr[i];

	return min;
}

int findFake()
{
	int min = MinOfArray(), cnt = 0, index;
	for(int i = 0; i < N; i++)
	{
		if(arr[i] == min)
			{cnt++; index = i;}
	}

	if(cnt > 1 || min >= 0)
		return -1;
	else
		return index;
}




int main()
{
	int t, n;
	char ch;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n); n*= 2;
		int tmp[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &tmp[i]);

		scanf(" %c", &ch);
		update(tmp, n, ch);
	}
	printf("\n%d\n", findFake());
	return 0;
}