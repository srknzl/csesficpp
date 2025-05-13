#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    unordered_set<ll> set;
    ll total = 0;
    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    ll ans = LONG_MAX;
    for (ll i: arr) {
        unordered_set<ll> newNums;
        for (ll k: set) {
            newNums.insert(k + i);
        }
        ans = min(ans, abs(total - 2 * i));
        set.insert(i);
        for (ll k : newNums) {
            set.insert(k);
            ans = min(ans, abs(total - 2 * k));
        }
    }
    cout << ans << endl;
}