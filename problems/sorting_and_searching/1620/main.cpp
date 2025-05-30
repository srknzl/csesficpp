#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n, t; cin >> n >> t;
  vector<int> timeNeeded(n);
  for (int i = 0; i < n; i++) {
    int k; cin >> k;
    timeNeeded[i] = k;
  }

  long ans = 0;
  long l = 0, r = 1e18;
  while (l <= r) {
    long mid = (l + r) / 2;
    long produced = 0;
    for (int i = 0; i < n; i++) {
      produced += mid / timeNeeded[i];
      if (produced >= t) break;
    }
    if (produced >= t) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
}
