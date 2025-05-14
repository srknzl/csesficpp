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
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  sort(w.begin(), w.end());
  int l = 0, r = w.size() - 1, ans = 0;
  while (l <= r) {
    if (l == r) {
      ans++;
      break;
    }

    if ((w[l] + w[r]) <= x) {
      l++;
      r--;
    } else {
      r--;
    }
    ans++;
  }
  cout << ans << endl;
}