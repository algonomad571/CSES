#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector<long long> prev(m + 2, 0), cur(m + 2, 0);

    if (x[0] == 0) {
        for (int v = 1; v <= m; v++) prev[v] = 1;
    } else {
        prev[x[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        fill(cur.begin(), cur.end(), 0);

        for (int v = 1; v <= m; v++) {
            if (x[i] != 0 && x[i] != v) continue;

            cur[v] = (
                prev[v - 1] +
                prev[v] +
                prev[v + 1]
            ) % MOD;
        }

        swap(prev, cur);
    }

    long long ans = 0;

    if (x[n - 1] == 0) {
        for (int v = 1; v <= m; v++) {
            ans = (ans + prev[v]) % MOD;
        }
    } else {
        ans = prev[x[n - 1]];
    }

    cout << ans % MOD << '\n';
    return 0;
}