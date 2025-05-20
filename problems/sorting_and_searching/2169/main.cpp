#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

void updateFw(vector<int>& fw, int i, int v) {
  while (i < fw.size()) {
    fw[i] += v;
    i += i & (-i);
  }
}

int queryFw(vector<int>& fw, int i) {
  int ans = 0;
  while (i > 0) {
    ans += fw[i];
    i -= i & (-i);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("a.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n; cin >> n;
  unordered_map<int, int> vToInd;
  vector<int> values;
  values.reserve(2 * n); 
  vector<pair<ll, ll>> arr(n);
  int p = 0;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    arr[i] = make_pair(a * MOD + b, i);
    values.push_back(a); values.push_back(b);
  }

  // coordinate compression
  sort(values.begin(), values.end());

  for (int i = 0; i < values.size(); i++) {
    if (i == 0 || values[i - 1] != values[i]) vToInd[values[i]] = p++;
  }

  vector<int> containedFw(p + 1, 0), containedCount(n);

  // is contained part starts here:
  sort(arr.begin(), arr.end(), [](pair<ll, ll> k, pair<ll, ll> l) {
    return k.first / MOD != l.first / MOD ? k.first / MOD < l.first / MOD : k.first % MOD > l.first % MOD;
  });

  for (int i = 0; i < arr.size(); i++) {
    containedCount[arr[i].second] = queryFw(containedFw, p) - queryFw(containedFw, vToInd[arr[i].first % MOD]);
    updateFw(containedFw, vToInd[arr[i].first % MOD] + 1, 1);
  }

  vector<int> containsFw(p + 1, 0), containsCount(n);

  // contains part starts here:
  sort(arr.begin(), arr.end(), [](pair<ll, ll> k, pair<ll, ll> l) {
    return ((k.first % MOD) != (l.first % MOD)) ? ((k.first % MOD) < (l.first % MOD)) : (k.first / MOD) > (l.first / MOD);
  });

  for (int i = 0; i < arr.size(); i++) {
    containsCount[arr[i].second] = queryFw(containsFw, p) - queryFw(containsFw, vToInd[arr[i].first / MOD]);
    updateFw(containsFw, vToInd[arr[i].first / MOD] + 1, 1);
  }

  for (int i : containsCount) {
    cout << i << " ";
  }
  cout << "\n";
  for (int i : containedCount) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
