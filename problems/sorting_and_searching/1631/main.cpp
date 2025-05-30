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
  long sum = 0;
  long maxV = 0;
  for (int i = 0; i < n; i++) {
    long k;
    cin >> k;
    sum += k;
    maxV = max(maxV, k);
  }
  cout << max(maxV * 2, sum) << endl;
}
