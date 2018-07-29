/*
arrange the string so that the pair of adjacent characters are different.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
priority_queue<pair<ll,char> >pq;
ll b[26];
int main()
{
    ll i,j,k,l,n,m;
    string a="bbbaacc";
    for(i=0;i<a.size();i++)
    {
        b[a[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(b[i]>0)
        {
            char ch=i+'a';
            pq.push({b[i],ch});
        }
    }
    pair<ll,char>p;
    p=make_pair(-1,'#');
    string s="";
    while(!pq.empty())
    {
        pair<ll,char>c;
        c=pq.top();
        pq.pop();
        s+=c.second;
        if(p.first>0)
        pq.push(p);
        c.first--;
        p=c;
    }
    cout<<s;
}
