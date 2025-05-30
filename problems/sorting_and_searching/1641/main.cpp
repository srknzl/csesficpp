#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, sum;
    cin >> n >> sum;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        arr[i] = make_pair(v, i + 1);
    }
    sort(arr.begin(), arr.end());
    bool found = false;
    for (int i = 0; i < n; i++) {
        int target = sum - arr[i].first;
        if (target < 2) {
            continue;
        }
        int l = i + 1, r = n - 1;
        while (l < r) {
            if (arr[l].first + arr[r].first < target) {
                l++;
            } else if (arr[l].first + arr[r].first > target) {
                r--;
            } else {
                cout << arr[i].second  << " " << arr[l].second << " " << arr[r].second << endl;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
}
