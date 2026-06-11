#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    uint64_t x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<uint32_t> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (uint32_t)((a * (uint64_t)arr[i-1] + b) % c);
    }

    vector<int> bitCount(30, 0);
    uint64_t result = 0;

    // initialize counts for first window
    for (int i = 0; i < k; i++) {
        uint32_t val = arr[i];
        for (int bit = 0; bit < 30; bit++) {
            if (val & (1U << bit)) bitCount[bit]++;
        }
    }

    // calculate OR of first window
    uint64_t windowOr = 0;
    for (int bit = 0; bit < 30; bit++) {
        if (bitCount[bit] > 0) windowOr |= (1U << bit);
    }
    result ^= windowOr;

    // slide the window
    for (int i = k; i < n; i++) {
        uint32_t outVal = arr[i - k];
        uint32_t inVal = arr[i];
        for (int bit = 0; bit < 30; bit++) {
            if (outVal & (1U << bit)) bitCount[bit]--;
            if (inVal & (1U << bit)) bitCount[bit]++;
        }

        windowOr = 0;
        for (int bit = 0; bit < 30; bit++) {
            if (bitCount[bit] > 0) windowOr |= (1U << bit);
        }
        result ^= windowOr;
    }

    cout << result << "\n";
    return 0;
}
