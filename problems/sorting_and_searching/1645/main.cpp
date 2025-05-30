#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    stack<int> s;
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            int greaterIndex = s.top();
            s.pop();
            ans[greaterIndex] = i + 1;
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}