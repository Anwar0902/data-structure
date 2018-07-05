#include<bits/stdc++.h>
using namespace std;
void M_I_R(string a)
{
    int i,j,n;
    n=a.size();
    int table[n][n];
    memset(table,0,sizeof(table));
    for(i=0;i<n;i++)
    {
        for(j=0;j+i<n;j++)
        {
            if(i==0)
                table[j][j+i]=0;
            else if(a[j]==a[j+i])
            {
                if(i==1)
                    table[j][j+i]=0;
                else
                    table[j][j+i]=table[j+1][j+i-1];
            }
            else
            {
                table[j][j+i]=min(table[j][j+i-1],table[j+1][j+i])+1;
            }
        }
    }
    cout<<"minimum number of insertion required to make the string palindrome :- ";
    cout<<table[0][n-1]<<endl;
}
int main()
{
    int m;
    cout<<"enter the total number of the test cases\n";
	cin>>m;
	while(m--)
	{
	    cout<<"enter the string\n";
	    string a;
	    cin>>a;
	    M_I_R(a);
	}
	return 0;
}
