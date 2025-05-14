#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  multiset<int> tickets;
  for (int i = 0; i < n; i++) {
    int n;
    cin >> n;
    tickets.insert(n);
  }
  for (int i = 0; i < m; i++) {
    int cust;
    cin >> cust;
    if (tickets.empty()) {
      cout << -1 << "\n";
    } else {
      if (tickets.upper_bound(cust) == tickets.begin()) {
        cout << -1 <<  "\n";
      } else {
        auto a = prev(tickets.upper_bound(cust));
        tickets.erase(a);
        cout << *a <<  "\n";
      }
    }
  }
}
 