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
  ll grandSum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > grandSum + 1) {
        break;
    }
    grandSum += arr[i];
  }
  cout << grandSum + 1 << endl;
}