#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> desired(n);
  for (int i = 0; i < n; i++) {
    cin >> desired[i];
  }
  sort(desired.begin(), desired.end());
  vector<int> apartments(m);
  for (int i = 0; i < m; i++) {
    cin >> apartments[i];
  }
  sort(apartments.begin(), apartments.end());

  int ans = 0;
  int l = 0, r = 0;
  while (l < n && r < m) {
    if (desired[l] <= apartments[r] + k && desired[l] >= apartments[r] - k) {
      l++;
      r++;
      ans++;
    } else if (desired[l] < apartments[r] - k) {
      l++;
    } else {
      r++;
    }
  }
  cout << ans << endl;
}