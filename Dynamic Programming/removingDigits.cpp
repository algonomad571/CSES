#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<long long> dp(n+1,1e9);
    dp[0]=0;
    dp[1]=1;

    for(int i=2; i<=n; i++){
        int x=i;

        while(x>0){
            int d=x%10;
            x/=10;

            if(d>0){
                dp[i]=min(dp[i],1+dp[i-d]);
            }
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}