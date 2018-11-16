#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define endl printf("\n")
#define N 26

int mat[N][N] = {0}, in[N] = {0}, rec[N] = {0}, out[N] = {0};
int find_Minimal_Element()													//finds minimal element lexciographically;
{
	for(int i = 0; i < N; i++)
		if(in[i] == 0 && out[i] != 0 && rec[i] == 0)						//finds element with no incoming links, non-zero outgoing links and un-'dfs'ed;
			return i;

	return -1;
}

void Lexico_Topo_sort(int i)						
{
	while(i != -1)														//till no element is found,
	{
	    printf("%c ", i + 97);											//prints minimal element;
	    rec[i] = 1;														//updates 'rec' saying that the following element has been checked and removed.

		for(int j = 0; j < N; j++)					
        	if(mat[i][j])
            	in[j]--;												//decreases number of links to in[j], due to removal of minimal element;

		i = find_Minimal_Element();										//update i to get new minimal element, in lexciographical order;
	}
	endl;
}



int main()
{
	int n, k; scanf("%d", &n);
	char y, x;
	for(int i = 0; i < n; i++)
	{
		scanf(" %c %c", &x, &y);
		mat[x-97][y-97] = 1; in[y-97]++; 								//count all incoming links to an element(not in order);
		out[x-97]++; out[y-97]++;										//count all outgoing links to an element(not in order);
	}

	k = find_Minimal_Element();											//finds first minimal element;		
	(k == -1) ? printf("-1\n") : Lexico_Topo_sort(k);					//if no minimal element is found, i.e cycle is found, print -1;
	return 0;
}