#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[],int n);
int main()
{
    int N;
    cout<<"enter the number of elements\n";
    cin>>N;
    int A[N];
    cout<<"enter thr elements\n";
    for(int i=0;i<N;i++)
        cin>>A[i];
    cout<<"maximum length subarray :- ";
    cout<<maxLen(A,N)<<endl;
}
int maxLen(int a[],int n)
{
  int i,j,k;
  map<int,int>mm;
  int l=k=0;
  for(i=0;i<n;i++)
  {
      l+=a[i];
      if(l==0)
      k=i+1;
      if(a[i]==0)
      k=max(k,1);
      if(mm.find(l)!=mm.end())
        k=max(k,i-mm[l]);
      else
      mm[l]=i;
  }
  return k;
}
