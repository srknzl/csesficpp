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
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  int median;
  if (arr.size() % 2 == 0) {
    median = (arr.at(n / 2) + arr.at(n / 2 - 1)) / 2;
  } else {
    median = arr.at(n / 2);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(median - arr[i]);
  }
  cout << ans << endl;
}