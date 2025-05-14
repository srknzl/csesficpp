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
  vector<pair<int, int>> events(2*n);
  for (int i = 0; i < 2 * n; i += 2) {
    int a, b;
    cin >> a >> b;
    events[i] = make_pair(a, 1);
    events[i + 1] = make_pair(b, -1);
  }
  sort(events.begin(), events.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
  });
  int ans = 0, cur = 0;
  for (pair<int, int>& p : events) {
    cur += p.second;
    ans = max(cur, ans);
  }
  cout << ans << endl;
}
 