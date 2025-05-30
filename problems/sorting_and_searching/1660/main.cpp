#include <bits/stdc++.h>

#define ll long long

using namespace std;

/** note: sliding window o (n) is possible
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0;
    int right = 0;
    int sum = a[0];
    int count = 0;

    while (left < n) {
        while (sum < x && right + 1 < n) {
            right++;
            sum += a[right];
        }
        if (sum == x) {
            count++;
        }
        sum -= a[left];
        left++;
    }

    cout << count << "\n";
}
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n; cin >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> pre(n);
    ll sum = 0;
    for (int i= 0; i < n; i++) {
        sum += arr[i];
        pre[i] = sum;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x - arr[i] >= 0) {
            int l = 0, r = i;
            while (l <= r) {
                int mid = (l + r) / 2;
                ll v = pre[i] - (mid - 1 < 0 ? 0 : pre[mid - 1]);
                if (v == x) {
                    ans++;
                    break;
                }
                if (v < x) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}