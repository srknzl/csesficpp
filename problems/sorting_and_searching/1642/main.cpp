#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, x; cin >> n >> x;
    if (n < 4) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // v left index
    vector<vector<int>> twoSums;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            twoSums.push_back({arr[i] + arr[j], i, j});
        }
    }
    sort(twoSums.begin(), twoSums.end());
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (found) {
            break;
        }
        for (int j = i + 1; j < n - 2; j++) {
            int sum1 = arr[i] + arr[j];
            int sum2 = x - sum1;
            if (sum2 < 2) {
                continue;
            }
            int l = 0, r = twoSums.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (twoSums[mid][0] < sum2) {
                    l = mid + 1;
                } else if (twoSums[mid][0] > sum2) {
                    r = mid - 1;
                } else {
                    if (twoSums[mid][1] <= j) {
                        l = mid + 1;
                    } else {
                        cout << i + 1 << " " << j + 1 << " " << twoSums[mid][1] + 1 << " " << twoSums[mid][2] + 1 << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                break;
            }
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
}
