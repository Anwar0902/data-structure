#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int *arr,int n,int sum)
{
    int i,j;
    bool cost[n+1][sum+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            if(i==0 || j==0)
            {
                if(j==0)
                    cost[i][j]=true;
                else if(i==0)
                    cost[i][j]=false;
                continue;
            }
            if(j<arr[i] || cost[i-1][j])
                cost[i][j]=cost[i-1][j];
            else
                cost[i][j]=cost[i-1][j-arr[i]];
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
            cout<<cost[i][j]<<" ";
        cout<<endl;
    }

   return cost[n][sum];
}
int main()
{
    int i,j,k,l,n;
    cout<<"enter the size of the array\n";
    cin>>n;
    cout<<"enter the array elements\n";
    int arr[n+1];
    for(i=1;i<=n;i++)
        cin>>arr[i];
    cout<<"enter the sum value\n";
    int sum;
    cin>>sum;
    cout<<"subset of "<<sum<<" existence is:- "<<subsetsum(arr,n,sum);
}
/*
6
3 34 4 12 5 2
9
*/
