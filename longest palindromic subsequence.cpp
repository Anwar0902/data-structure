#include<bits/stdc++.h>
using namespace std;
int lps(string a)
{
    int i,j,l;
    l=a.size();
    int arr[l][l];
    for(i=0;i<l;i++)
        arr[i][i]=1;
    for(i=2;i<=l;i++)
    {
        for(j=0;j<l-i+1;j++)
        {
            if(a[j]==a[j+i-1])
                if(i==2)
                    arr[j][j+i-1]=2;
                else
                    arr[j][j+i-1]=arr[j+1][j+i-2]+2;
            else
                arr[j][j+i-1]=max(arr[j+1][j+i-1],arr[j][j+i-2]);
        }
    }
    return arr[0][l-1];
}
int main()
{
    int i,j,k,l,n;
    cout<<"enter the string\n";
    string a;
    cin>>a;
    cout<<"longest palindromic subsequences is:- "<<lps(a);
}
