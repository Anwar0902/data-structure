#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll i,j,l,m,n,k;
    cout<<"enter the size of the array\n";
    cin>>n;
    ll a[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0};
    cout<<"enter the number of allowed flipped\n";
    cin>>m;
    ll r;
    l=r=0;
    ll maxi=0,zero=0;
    while(r<n)
    {
        if(zero>m)
        {
            maxi=max(maxi,(r-l-1));
            if(a[l]==0)
                zero--;
            l++;
        }
        else
        {
            if(a[r]==0)
                zero++;
            r++;
        }
    }
    if(zero>m)
    {
        maxi=max(maxi,(r-l-1));
    }
    else
        maxi=max(maxi,(r-l));
    cout<<maxi;
}
