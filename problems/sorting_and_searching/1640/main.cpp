#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr[i] = make_pair(v, i);
  }
  sort(arr.begin(), arr.end());
  int l = 0, r = arr.size() - 1;
  while (l < r) {
    if (arr[l].first + arr[r].first < x) {
      l++;
    } else if (arr[l].first + arr[r].first > x) {
      r--;
    } else {
      cout << (arr[l].second + 1) << " " << (arr[r].second + 1) << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
 