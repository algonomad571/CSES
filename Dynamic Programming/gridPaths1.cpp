#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;    

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }   

    vector<vector<int>> dp(n,vector<int>(n,0));

    if(s[0][0] == '*') {
        cout << 0 << '\n';
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='*'){
                dp[i][j]=0;
            }
            else{
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                    long long up=0;
                    long long left=0;
                    if(i>0)
                        up=dp[i-1][j];
                    if(j>0)
                        left=dp[i][j-1];
                    dp[i][j]=(up+left)%MOD;
                }
            }
        }   
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}
