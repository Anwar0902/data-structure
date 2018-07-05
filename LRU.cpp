#include<bits/stdc++.h>
using namespace std;
void LRU(int a[],int n,int m)
{
    list<int>l;
    int b[100]={0};
    int i,j;
    int ans=0;
    for(i=0;i<n;i++)
    {
        if(b[a[i]]==0)
        {
            ans++;
            if(l.size()==m)
            {
                b[l.front()]=0;
                l.pop_front();
            }
            l.push_back(a[i]);
            b[a[i]]=1;
        }
        else
        {
            l.remove(a[i]);
            l.push_back(a[i]);
        }
    }
    cout<<"total number of page faults are :- "<<ans<<endl;
}
int main()
{
    int i,j,n,m;
    cout<<"enter the number of process\n";
    cin>>n;
    int a[n];
    cout<<"enter the process\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"enter the number of cache\n";
    cin>>m;
    LRU(a,n,m);
}
