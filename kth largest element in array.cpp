#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[100],n,k;
void heapify(ll i)
{
    ll l,r,s;
    l=i*2+1;
    r=i*2+2;
    s=i;
    if(l<k&&a[s]>a[l])
        s=l;
    if(r<k&&a[s]>a[r])
        s=r;
    if(s!=i)
    {
        ll temp=a[s];
        a[s]=a[i];
        a[i]=temp;
        heapify(s);
    }
}
void buildheap(ll k)
{
    ll m=k/2;
    while(m>=0)
    {
        heapify(m);
        m--;
    }
}
int main()
{
    ll i,j,l,m;
    cout<<"enter the size of the array\n";
    cin>>n;
    cout<<"enter the n elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"enter the kth value for largest\n";
    cin>>k;
    buildheap(k);
    for(i=k;i<n;i++)
    {
        if(a[i]>a[0])
        {
            a[0]=a[i];
            heapify(0);
        }
    }
    for(i=0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<k<<"th largest element is "<<a[0];
}
