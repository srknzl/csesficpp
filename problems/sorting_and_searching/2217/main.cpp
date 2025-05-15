#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;


int calculateInversions(vector<int>& nums, vector<int>& vToInd,  int vA, int vB) {
    int inv = 0;
    if (vA > 0 && vToInd[vA] < vToInd[vA - 1]) {
        inv++;
    }
    if (vB + 1 < vToInd.size() && vToInd[vB] > vToInd[vB + 1]) {
        inv++;
    }
    if (vA + 1 < vToInd.size() && vToInd[vA] > vToInd[vA + 1]) {
        inv++;
    }
    if (vB > 0 && vToInd[vB] < vToInd[vB - 1]) {
        inv++;
        if (vA + 1 == vB) inv--; // prevent double counting 
    }
    return inv;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<int> vToInd(n);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      vToInd[a - 1] = i;
      nums[i] = a;
  }
  vector<pair<int, int>> queries(m); 
  for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      queries[i] = make_pair(min(a, b), max(a, b));
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (vToInd[i] < vToInd[i - 1]) {
        ans++;  
    }
  }
  for (auto & p : queries) {
    int a = p.first, b = p.second;
    if (a == b) {
        cout << ans << "\n";
        continue;
    }
    int vA = nums[a - 1] - 1, vB = nums[b - 1] - 1;
    ans -= calculateInversions(nums, vToInd, min(vA, vB), max(vA, vB));
    // swap a and b
    int tmp = nums[a - 1];
    nums[a - 1] = nums[b - 1];
    nums[b - 1] = tmp;
    vToInd[vB] = a - 1;
    vToInd[vA] = b - 1;
    ans += calculateInversions(nums, vToInd, min(vA, vB), max(vA, vB));
    cout << ans << "\n";
  }
}