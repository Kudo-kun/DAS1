    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #define print(x) printf("%d ", x)
	#define endl printf("\n")
    #define read(x) scanf("%d", &x)
     
    
    int sumOfArray(int n, int arr[])
    {
        int sum = 0;
        for(int i  = 0; i < n; i++)
            sum += arr[i];
     
        return sum;
    }
     
    int maxOfArray(int n, int arr[])
    {
        int max = 0;
        for(int i = 0; i < n; i++)
            if(arr[i] >= max)
                max = arr[i];
     
        return max;
    }
     
     
    int check(int n, int arr[], int val)
    {
        int sum = 0, k = 0;
        for(int i = 0; i < n; i++)
        {
            if(sum + arr[i] >= val)
                { i--; k++; sum = 0; }                                              //if optimum team strength(val), is reached, increment number of teams count.
            else
                sum += arr[i];                                                      //else add another member to that team.
        }
		return ((sum <= val) ? (k+1) : (k));                                         //even though the last team strength is less than val, put them into a team.
    }
     
     
    int binsearch(int cnt, int n, int arr[], int lo, int hi)
    {
        while(lo != hi)
        {
            int mid = (lo+hi)/2;
			//print(mid); endl;
            (cnt >= check(n, arr, mid)) ? (hi = mid - 1) : (lo = mid + 1);          //if number of teams is lesser than expected number, decrement the the max value of team, so as to get more teams.         
        }                                                                           //else increase the max value to decrease the number of teams.
        return lo;
    }
     
     
     
    int main()
    {
        int cnt, n, k;
        read(cnt); read(n);
        int arr[n];
     
        for(int i = 0; i < n; i++)
            read(arr[i]);
   
        printf("%d\n", binsearch(cnt, n, arr, maxOfArray(n, arr), sumOfArray(n, arr)));         //initial parameters: strength of most powerful hero, assuming max possible teams, one person per team.
        return 0;                                                                               //initial parameters: strength of all heros taken together, assuming a single team.
    }