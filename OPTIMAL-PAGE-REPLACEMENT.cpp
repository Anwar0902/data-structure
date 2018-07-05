#include<bits/stdc++.h>
using namespace std;
void OPTIMAL_PAGE_REPLACEMENT(int a[],int n,int m)
{
    list<int>l;
    map<int,int>mp;
    map<int,int>:: iterator it;
    int b[100]={0};
    int i,j;
    int ans=0;
    for(i=0;i<n;i++)
    {
        int c[100];
        if(b[a[i]]==0)
        {
            ans++;
            if(l.size()==m)
            {
                for(j=i+1;j<n;j++)
                {
                    if(b[a[j]])
                        mp[a[j]]=min(mp[a[j]],j);
                }
                int maxi=0;
                int position=-1;
                for(it=mp.begin();it!=mp.end();it++)
                {
                    if(it->second > maxi)
                    {
                        maxi=it->second;
                        position=it->first;
                    }
                    it->second=INT_MAX;
                }
                l.remove(position);
                mp.erase(position);
                b[position]=0;
                mp[a[i]]=INT_MAX;
                l.push_back(a[i]);
                b[a[i]]=1;
            }
            else
            {
                b[a[i]]=1;
                l.push_back(a[i]);
                mp[a[i]]=INT_MAX;
            }
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
    OPTIMAL_PAGE_REPLACEMENT(a,n,m);
}
