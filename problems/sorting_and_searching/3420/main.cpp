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
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i]; 
  }
  int l = 0;
  ll ans = 0;
  multiset<int> elements;
  for (int i = 0; i < n; i++) {
    elements.insert(arr[i]);
    while (elements.count(arr[i]) > 1) {
      elements.erase(elements.find(arr[l]));
      l++;
    }
    ans += i - l + 1;
  }
  cout << ans << endl;
}
