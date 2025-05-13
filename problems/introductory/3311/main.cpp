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
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool allowed[4] = {};
            fill_n(allowed, 4, true);
            if (i - 1 >= 0) {
                allowed[grid[i - 1][j] - 'A'] = false;
            }
            if (j - 1 >= 0) {
                allowed[grid[i][j - 1] - 'A'] = false;
            }
            allowed[grid[i][j] - 'A'] = false;
            for (int k = 0; k < 4; k++) {
                if (allowed[k]) {
                    grid[i][j] = 'A' + k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}