#include <iostream>
#include <deque>
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

    deque<int> dq;
    long long result = 0;

    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result ^= arr[dq.front()];
        }
    }

    cout << result << "\n";

    return 0;
}
