#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    vector<long long> prefixXor(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixXor[i + 1] = prefixXor[i] ^ arr[i];
    }

    long long result = 0;
    for (int i = 0; i <= n - k; i++) {
        long long windowXor = prefixXor[i + k] ^ prefixXor[i];
        result ^= windowXor;
    }

    cout << result << "\n";

    return 0;
}
