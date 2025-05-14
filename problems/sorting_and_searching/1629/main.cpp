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
  vector<pair<int, int>> movies(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    movies[i] = make_pair(a, b);
  }
  sort(movies.begin(), movies.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second; 
  });
  int currentEnd = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    if (movies[i].first < currentEnd) continue;
    currentEnd = movies[i].second;
    ans++;
  }
  cout << ans << endl;
}
 