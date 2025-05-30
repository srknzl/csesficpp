#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n; cin >> n;
  vector<long> dur(n);
  long ans = 0;
  for (int i = 0; i < n; i++) {
    int d; cin >> d;
    int dead; cin >> dead;
    ans += dead;
    dur[i] = -d;
  }
  sort(dur.begin(), dur.end());
  for (int i = n; i >= 1; i--) {
    ans -= -dur[i - 1] * i;
  }
  cout << ans << endl;
}
