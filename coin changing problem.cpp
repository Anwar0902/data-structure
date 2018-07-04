#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
 {
	ll i,j,k,l,n,m;
	ll t;
	cout<<"enter the number of test cases\n";
	cin>>t;
	while(t--)
	{
	    cout<<"enter the number of coins\n";
	    cin>>n;
	    ll a[n];
	    cout<<"enter the coins value\n";
	    for(i=1;i<=n;i++)
	    cin>>a[i];
	    cout<<"enter the sum u want to make\n";
	    cin>>m;
	    ll b[n+5][m+5];
	    for(i=1;i<=m;i++)
	    b[0][i]=0;
	    for(i=0;i<=n;i++)
	        b[i][0]=1;
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=m;j++)
	        {
	            if(j<a[i])
	                b[i][j]=b[i-1][j];
	            else
	            {
	                b[i][j]=b[i-1][j]+b[i][j-a[i]];
	            }
	        }
	    }
	    cout<<"the total number of ways in which we can mak e the given sum using the coin is :- ";
	    cout<<b[n][m]<<endl;
	}
	return 0;
}
