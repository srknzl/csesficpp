#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

map<ll, ll> invCache;

ll exp(ll x, ll y, ll p) {
  x %= p;
  ll ans = 1, mul = x;
  while (y > 0) {
    if (y % 2 == 1) {
      ans *= mul;
      ans %= p;
    }
    y >>= 1;
    mul = mul * mul;
    mul %= p;
  }
  return ans % p;
}

ll modInverse(ll x, ll mod) {
  if (invCache.find(x) != invCache.end()) {
    return invCache[x];
  }
  invCache[x] = exp(x, mod - 2, mod);
  return invCache[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n; cin >> n;
  map<int, ll> counts;
  ll totalProd = 1, ans = 0;
  for (int i = 0; i < n; i++) {
    int v; cin >> v; 
    ans += ((totalProd * modInverse(counts[v] + 1, MOD)) % MOD);
    ans %= MOD;
    totalProd *= modInverse(counts[v] + 1, MOD); 
    totalProd %= MOD;
    totalProd *= (counts[v] + 2);
    totalProd %= MOD;
    counts[v]++;
  }
  cout << ans << endl;
}
