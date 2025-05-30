#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, x; cin >> n; cin >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    map<ll, int> preCounts;
    preCounts[0] = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (preCounts.find(sum - x) != preCounts.end()) {
            ans += preCounts[sum - x];
        }
        preCounts[sum]++;
    }
    cout << ans << endl;
    return 0;
}