#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> events(2 * n, vector<int>());
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        // 0 is entrance, 1 is exit
        events[2 * i] = {a, 0, i};
        events[2 * i + 1] = {b, 1, i};
    }
    sort(events.begin(), events.end(), [](vector<int> a, vector<int> b) {
      if (a[0] != b[0]) {
        return a[0] < b[0];
      }
      return a[1] < b[1];
    });
    vector<int> assignments(n);
    vector<int> availableRooms;
    int used = 0;
    for (int i = 0; i < 2 * n; i++) {
        vector<int> p = events[i];
        if (p[1] == 0) {
            if (availableRooms.empty()) {
                used++;
                assignments[p[2]] = used;
            } else {
                assignments[p[2]] = availableRooms.back();
                availableRooms.pop_back();
            }
        } else {
            availableRooms.push_back(assignments[p[2]]);
        }
    }
    cout << used << "\n";
    for (int i = 0; i < n; i++) {
        cout << assignments[i] << " ";
    }
    cout << endl;
}
