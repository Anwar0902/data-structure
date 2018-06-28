#include<bits/stdc++.h>
using namespace std;
int n=10;
void maxsubsquare(int a[][10])
{
    int i,j,k;
    int sum=-1e6;
    for(k=3;k<=3;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                int p,q;
                p=i+k-1;
                q=j+k-1;
                if(p>n || q>n)
                    continue;
                int ans=a[p][q]-a[i-1][q]-a[p][j-1]+a[i-1][j-1];
                sum=max(sum,ans);
            }
        }
    }
    cout<<"maximum sum square matrix is:- ";
    cout<<sum;
}
void prefixsum(int a[][10])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=2;j<=n;j++)
            a[i][j]+=a[i][j-1];
    }
    for(i=1;i<=n;i++)
    {
        for(j=2;j<=n;j++)
            a[j][i]+=a[j-1][i];
    }
}
int main()
{
    int i,j,k,l;
    cout<<"enter the size of the sqare matrix\n";
    cin>>n;
    cout<<"enter the matrix\n";
    int a[10][10];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    }
    prefixsum(a);
    maxsubsquare(a);
}
/*
4
1 2 -1 4
-8 -3 4 2
3 8 10 -8
-4 -1 1 7
*/
