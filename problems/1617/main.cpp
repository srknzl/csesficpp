#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    ll ans = 1;
    while (n--) {
        ans = ans * 2;
        ans = ans % MOD;
    }
    cout << ans << endl;
}
