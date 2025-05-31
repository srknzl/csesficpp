#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool check(ll mid, vector<int>& arr, int k) {
    ll sum = 0, groups = 1;
    for (int i = 0; i < arr.size(); i++) {
        if (sum + arr[i] <= mid) {
            sum += arr[i];
        } else if (arr[i] > mid) {
            return false;
        } else {
            sum = arr[i];
            groups++;
        }
    }
    return groups <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    ll l = 1, r = 2e15;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid, arr, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}