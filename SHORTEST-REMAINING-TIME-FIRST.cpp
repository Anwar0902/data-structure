#include<bits/stdc++.h>
using namespace std;
void SRTF(int burst[],int n)
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
    for(i=0;count<n;i++)
    {
        //cout<<i<<endl;
        int mini=INT_MAX;
        int position=-1;
        for(j=0;j<n;j++)
        {
            if(burst[j]<mini)
            {
                mini=burst[j];
                position=j;
            }
        }
        if(burst[position]==1)
        {
            count++;
            burst[position]=INT_MAX;
            compilation[position]=i+1;
        }
        else
            burst[position]-=1;
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
    SRTF(a,n);
}
