#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    ll k;
    cin >> k;
    k--;
    ll from = 1, to = 9;
    int c = 1;
    while (k >= c * (to - from + 1)) {
      k -= c * (to - from + 1);
      c++;
      from *= 10;
      to = to * 10 + 9;
    }
    ll digitAt = from + (k / c);
    cout << to_string(digitAt)[k % c] << "\n";
  }
}