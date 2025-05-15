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
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int l = 0, ans = 0; 
  map<int, int> ind;
  for (int i = 0; i < n; i++) {
    auto it = ind.find(arr[i]);
    if (it != ind.end() && l <= (*it).second) {
        l = (*it).second + 1;
    }
    ind[arr[i]] = i;
    ans = max(ans, i - l + 1);
  }
  cout << ans << endl;
}
