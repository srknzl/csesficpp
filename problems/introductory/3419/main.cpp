#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    int grid[n][n];
    unordered_set<int> col_sets[n];
    for (int i = 0; i < n; i++) {
        unordered_set<int> row;
        for (int j = 0; j < i; j++) {
            int k = 1;
            while (row.find(k) != row.end() || col_sets[j].find(k) != col_sets[j].end()) {
                k++;
            }
            grid[i][j] = k;
            col_sets[j].insert(k);
            col_sets[i].insert(k);
            row.insert(k);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j == i) grid[i][j] = 0;
            else grid[i][j] = grid[j][i];
        }
    }
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}