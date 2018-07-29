/*
minimum number of changes required so that we can arrange the array into ascending order.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i]=arr[i]-i;
        }

        int dp[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
        }
        for(int i=1;i<n;i++){
            if(arr[i]<0){
                dp[i]=0;
                continue;
            }
            for(int j=i-1;j>=0;j--){
                if(arr[j]<=arr[i]&&arr[j]>=0){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        for(int i=0;i<n;i++)
            cout<<dp[i]<<" ";
        cout<<endl;
        int ans=dp[0];
        for(int i=1;i<n;i++){
            ans = max(ans,dp[i]);
        }
        cout<<n-ans<<endl;
    }
}
