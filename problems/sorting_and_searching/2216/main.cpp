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
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      
      arr[i] = make_pair(a, i);
  }
  sort(arr.begin(), arr.end());
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i].second < arr[i - 1].second) {
        ans++;  
    }
  }
  cout << ans << endl;
}