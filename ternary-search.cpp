#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
set<ll>s;
int main()
{
    ll i,j,k,l,n,m;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        l=1;
        ll r=min(a,b)-1;
        j=0;
        while(l<=r)
        {
            ll m=(l+r)/2;
            ll f1,f2,f3;
            f1=f2=f3=0;
            f2=m*(a-m)*(b-m);
            f3=(m+1)*(a-m-1)*(b-m-1);
            f1=(m-1)*(a-m+1)*(b-m+1);
            if(f2>=f1&&f2>=f3)
            {
               // cout<<f1<<" "<<f2<<" "<<f3<<endl;
                if(f1==f2)
                    cout<<m-1<<" "<<f1<<endl;
                else
                    cout<<m<<" "<<f2<<endl;
                break;
            }
            else if(f1<f2&&f2<f3)
                l=m+1;
            else
                r=m-1;
        }
    }
}#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
set<ll>s;
int main()
{
    ll i,j,k,l,n,m;
    cin>>n;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        l=1;
        ll r=min(a,b)-1;
        j=0;
        while(l<=r)
        {
            ll m=(l+r)/2;
            ll f1,f2,f3;
            f1=f2=f3=0;
            f2=m*(a-m)*(b-m);
            f3=(m+1)*(a-m-1)*(b-m-1);
            f1=(m-1)*(a-m+1)*(b-m+1);
            if(f2>=f1&&f2>=f3)
            {
               // cout<<f1<<" "<<f2<<" "<<f3<<endl;
                if(f1==f2)
                    cout<<m-1<<" "<<f1<<endl;
                else
                    cout<<m<<" "<<f2<<endl;
                break;
            }
            else if(f1<f2&&f2<f3)
                l=m+1;
            else
                r=m-1;
        }
    }
}
