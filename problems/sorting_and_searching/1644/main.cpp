#include <bits/stdc++.h>

#define ll long long

// there is a deque based solution as well works in o (n) time.
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;  // reading in variables

    vector<long long> pfx(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        pfx[i] = a + pfx[i - 1];  // construction of our prefix sum
    }

    ll ret = LONG_MIN;
    multiset<ll> ms;

    // we can keep a sliding window of size B - A + 1,
    // then find the lowest pfx[j] using multiset
    for (int i = a; i <= n; ++i) {
        if (i > b) ms.erase(ms.find(pfx[i - b - 1]));  // erase the element if size > B
        ms.insert(pfx[i - a]);
        ret = max(ret,
                  pfx[i] - *ms.begin());  // we want to minimize ms.begin() aka pfx[j]
    }

    cout << ret << "\n";
}