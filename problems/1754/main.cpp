#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int minEl = min(a, b), maxEl = max(a, b);;
        int diff = maxEl - minEl;
        if (minEl >= diff && (minEl - diff) % 3 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
