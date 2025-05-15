#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

void update(vector<int>& fenwick, int idx, int val) {
  for (; idx <= fenwick.size(); idx += idx & -idx)
    fenwick[idx] += val;
}

int query(vector<int>& fenwick, int idx) {
  int sum = 0;
  for (; idx > 0; idx -= idx & -idx)
    sum += fenwick[idx];
  return sum;
}

int find_kth(vector<int>& fenwick, int k) {
  int lo = 1, hi = fenwick.size(), ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (query(fenwick, mid) >= k) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> fenwick(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    update(fenwick, i, 1); 
  }

  int pos = 1, remaining = n;
  while (remaining > 0) {
    pos = (pos + k) % remaining;
    if (pos == 0)
      pos = remaining;
    int idx = find_kth(fenwick, pos);
    cout << idx << " ";
    update(fenwick, idx, -1); 
    remaining--;
  }
  cout << endl;
  return 0;
}
