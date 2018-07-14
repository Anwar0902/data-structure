#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void sorted(stack<ll>a,stack<ll>b)
{
    while(!a.empty())
    {
        ll p=a.top();
        b.push(p);
        a.pop();
    }
    while(!b.empty())
    {
        ll p=b.top();
        b.pop();
        if(a.empty()==true || p>a.top())
        {
            a.push(p);
        }
        else
        {
            ll q=0;
            while(!a.empty() && p<a.top())
            {
                q++;
                ll r=a.top();
                a.pop();
                b.push(r);
            }
            a.push(p);
            while(q--)
            {
                ll r=b.top();
                b.pop();
                a.push(r);
            }
        }
    }
    while(!a.empty())
    {
        ll r=a.top();
        a.pop();
        cout<<r<<" ";
    }
}
int main()
{
    ll i,j,k,l,n,m;
    cout<<"enter the number of elements in the stack\n";
    cin>>n;
    stack<ll>a,b;
    cout<<"enter the stack elements\n";
    for(i=0;i<n;i++)
    {
        cin>>j;
        a.push(j);
    }
    cout<<"sorted stack :- \n";
    sorted(a,b);
}
