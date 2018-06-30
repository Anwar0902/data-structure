#include<bits/stdc++.h>
using namespace std;
void toh(int n,char a,char c, char b)
{
    if(n==1)
    {
        cout<<"move disk number "<<n<<" from tower "<<a<<" to tower "<<c<<endl;
        return ;
    }
    toh(n-1,a,b,c);
    cout<<"move disk number "<<n<<" from tower "<<a<<" to tower "<<c<<endl;
    toh(n-1,b,c,a);
}
int main()
{
    int n;
    cout<<"enter number of disk :- ";
    cin>>n;
    toh(n,'A','C','B');
}
