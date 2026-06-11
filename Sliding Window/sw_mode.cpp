#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    unordered_map<int, int> freq;
    set<pair<int, int>> s;

    for (int i = 0; i < k; i++) {
        freq[a[i]]++;
    }

    for (auto &p : freq) {
        s.insert({-p.second, p.first});
    }

    cout << s.begin()->second << " ";

    for (int i = k; i < n; i++) {
        int out = a[i - k];
        int in = a[i];

        s.erase({-freq[out], out});
        freq[out]--;
        if (freq[out] > 0)
            s.insert({-freq[out], out});

        if (freq[in] > 0)
            s.erase({-freq[in], in});
        freq[in]++;
        s.insert({-freq[in], in});

        cout << s.begin()->second << " ";
    }
}