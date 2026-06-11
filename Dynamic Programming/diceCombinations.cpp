#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        long long ways = 0;

        for (int d = 1; d <= 6; d++) {
            if (i - d >= 0) {
                ways += dp[i - d];
            }
        }

        dp[i] = ways % MOD;
    }

    cout << dp[n] << '\n';
    return 0;
}