#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define endl printf("\n") 
#define read(x) scanf("%d", &x)
#define print(x) printf("%d ", x);


int isNotPresent(int k, int arr[], int n)
{
	for(int i = 0; i < n; i++)
		if(arr[i] == k)
			return 0;

	return 1;
}

void printArray(int n, int arr[])
{
	for(int i = 0; i < n; i++)
		print(arr[i]);
}

void appendSubsets(int ans[], int U[], int index, int n2, int n1)
{
	for(int i = 0; i < (1 << n1); i++)
	{
		printArray(n2-n1, ans);												//print the skills, that compulsorily have to be present in the other pokemon.
		for(int j = (1 << n1), k = n1; j > 0; j >>= 1, k--)					//add a subset of girantina's skills to it, to complete the set.
			if(i & j)														//moves a one along the binary number, and checks if one is present at that particular location.
				print(U[k]);

		endl;
	}
}


int main()
{
	int n, n1, n2, k, index = 0; 
	read(n);							//	totally,
	for(int i = 0; i < n; i++)			//	redundant,
		read(k);						//	steps, LOL.

	read(n1); 
	int U[n1];
	for(int i = 0; i < n1; i++)
		read(U[i]);

	read(n2);
	int T[n2]; int* ans = (int*)calloc(n2-n1, sizeof(int));
	for(int i = 0; i < n2; i++)
	{
		read(T[i]);
		if(isNotPresent(T[i], U, n1))										//append all skills that are not present in girantina.
			ans[index++] = T[i];
	}

	appendSubsets(ans, U, index, n2, n1);
	free(ans);
	return 0;
}