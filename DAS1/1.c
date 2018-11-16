#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define endl printf("\n")


int checkDivision(int n, int arr[], int k)
{
	for(int i = 0; i < n; i++)
		if(arr[i] % k == 0)
			return 0;

	return 1;
}


int main()
{
	int n, i1 = 0, ans = 0; 
	scanf("%d", &n);
	int divisors[256];

	for(int i = 1; i <= n/2; i++)
		if(n % i == 0)
			divisors[i1++] = i;																	//find all divisors that number and store them in an array.

	divisors[i1++] = n;																			//add the number itself as the last divisor.
	for(int i = i1-1; i >= 0; i--)																//chose a particular element of the divisors.							
	{
		int* comp = (int*)calloc(i1, sizeof(int)); int i2 = 0;
		for(int j = i-1; j >= 0; j--)															//for each number from the rest of the divisors,
		{
			if((divisors[i] % divisors[j] == 0) && checkDivision(i2, comp, divisors[j]))		//check if it divides the chosen number, 
			{																					//and it should divide any other number in the set of numbers that have already divided it, this ensures a direct link(relation) between the two numbers.
				comp[i2++] = divisors[j];														//if it divides, increment count and add this number as well into the secondary array of divisors.
				ans++;																			
			}
		}
		free(comp);
	}
	
	printf("%d", ans); endl;
	return 0;

}