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
  vector<tuple<int, int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr[i] = make_tuple(a, b, i);
  }
  sort(arr.begin(), arr.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<0>(a) != get<0>(b)) {
      return get<0>(a) < get<0>(b);
    }
    if (get<1>(a) != get<1>(b)) {
      return get<1>(a) > get<1>(b);
    }
    return get<2>(a) < get<2>(b);
  });
  vector<bool> contained(n, false), contains(n, false);
  int end = get<1>(arr[0]);
  stack<int> s;
  s.push(0);
  for (int i = 1; i < n; i++) {
    if (get<1>(arr[i]) <= end) {
      contained[get<2>(arr[i])] = true;
      while (!s.empty() && get<0>(arr[s.top()]) <= get<0>(arr[i]) && get<1>(arr[s.top()]) >= get<1>(arr[i])) {
        int j = s.top();
        s.pop();
        contains[get<2>(arr[j])] = true;
      }
    } else {
      end = get<1>(arr[i]);
    }
    s.push(i);
  }
  for (int i = 0; i < n; i++) {
    cout << (contains[i] ? 1 : 0) << " "; 
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << (contained[i] ? 1 : 0) << " "; 
  }
  cout << "\n";
}
