#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  ll cur = -1e9, ans = -1e9;
  for (int i = 0; i < n; i++)
  {
    ll k;
    cin >> k;
    cur = max(k, cur + k);
    ans = max(ans, cur);
  }
  cout << ans << endl;
}
 