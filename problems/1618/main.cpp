#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    while (n > 0) {
        ans += n / 5;
        n /= 5;
    }
    cout << ans << endl;
}
