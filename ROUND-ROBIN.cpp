#include<bits/stdc++.h>
using namespace std;
void RR(int burst[],int n,int m)
{
    int i,j;
    int compilation[n];
    int b[n];
    for(i=0;i<n;i++)
    {
        b[i]=burst[i];
    }
    i=0;
    int count=0;
    while(count<n)
    {
        for(j=0;j<n;j++)
        {
            if(burst[j]<=0)
                continue;
            if(burst[j]<=m)
            {
                i+=burst[j];
                compilation[j]=i;
                burst[j]=0;
                count++;
            }
            else
            {
                i+=m;
                burst[j]-=m;
            }
        }
    }
    cout<<"Turn around time\n";
    for(i=0;i<n;i++)
    {
        cout<<compilation[i]<<" ";
    }
    cout<<endl;
    cout<<"waiting time\n";
    for(i=0;i<n;i++)
    {
        cout<<compilation[i]-b[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int i,j,n,m;
    cout<<"enter the total number of process\n";
    cin>>n;
    cout<<"enter te burst time of the process all start at 0\n";
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"enter the RR time\n";
    cin>>m;
    RR(a,n,m);
}
