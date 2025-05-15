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

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }

  for (int i = 0; i < v.size(); i++) {
    if (i % 2 == 0) {
      v.push_back(v[i]);
    } else {
      cout << v[i] << " ";
    }
  }
  cout << "\n";
}
