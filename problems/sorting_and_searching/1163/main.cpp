#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int x, n; cin >> x >> n;
  set<int> lights;
  multiset<int> lengths;
  lights.insert(0);
  lights.insert(x);
  lengths.insert(x);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    auto nextLight = lights.upper_bound(v);
    auto prevLight = prev(nextLight);

    int nextEnd = *nextLight;
    int nextStart = *prevLight;
    int nextLen = nextEnd - nextStart;
    
    lights.insert(v);
    
    lengths.erase(lengths.find(nextLen));
    lengths.insert(v - nextStart);
    lengths.insert(nextEnd - v);
    cout << *prev(lengths.end()) << " ";
  }
}
