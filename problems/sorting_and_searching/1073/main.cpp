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
  multiset<int> s;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    auto it = s.upper_bound(v);
    if (it != s.end()) {
        s.erase(it);
    }
    s.insert(v);
  }
  cout << s.size() << endl;
}
