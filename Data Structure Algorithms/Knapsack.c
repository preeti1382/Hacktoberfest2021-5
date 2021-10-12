//Knapsack implementation with dynamic programming.

#include<stdio.h>
#include<conio.h>

int max(int a  , int b)
{
    if(a>b) return a;
    return b;
}
int knapsack(int w , int wt[] , int val[] , int n)
{
    int i,j;
    int T[n][w+1];
    for(i=0 ; i<=n ; i++)
    {
        for(j=0 ; j<=w ; j++)
        {
            if(i==0 || j==0)
            {
                T[i][j] = 0;
            }
            else if(wt[i-1]>j)
            {

                    T[i][j] = T[i-1][j];
            }
            else{
                T[i][j] = max(T[i-1][j] , T[i-1][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    return T[n][w];
}
int main()
{
    int val[] = {1,2,5,6};
    int wt[] = {2,3,4,5};
    int w = 8;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d" , knapsack(w,wt,val,n));
    return 0;
}
