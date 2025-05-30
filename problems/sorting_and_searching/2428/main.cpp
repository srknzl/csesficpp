#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, k; cin >> n; cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 0;
    int l = 0;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        while (count.size() > k) {
            int oldV = count[arr[l]];
            if (oldV == 1) {
                count.erase(arr[l]);
            } else {
                count[arr[l]] = oldV - 1;
            }
            l++;
        }
        ans += i - l + 1;
    }
    cout << ans << endl;
    return 0;
}