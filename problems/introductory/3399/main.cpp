#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;

bool attacksQueens(vector<pair<int, int>> queens, int x, int y) {
    for (pair<int, int> queen : queens) {
        if (queen.first - queen.second == x - y || queen.first + queen.second == x + y || queen.first == x || queen.second == y) return true;
    }
    return false;
}

int placeQueens(char grid[][8], int row, vector<pair<int, int>> queens) {
    if (row == 8) {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        if (grid[row][i] == '.' && !attacksQueens(queens, row, i)) {
            queens.push_back(make_pair(row, i));
            ans += placeQueens(grid, row + 1, queens);
            queens.pop_back();
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a == 0 && b == 0) {
            cout << "YES" << "\n";
            for (int k = 1; k <= 2; k++) {
                for (int i = 1; i <= n; i++) {
                    cout << i << " ";
                }
                cout << "\n";
            }
            continue;    
        }
        if (n == 1) {
            cout << "NO" << "\n";
        } else {
            if (a == 0 || b == 0 || a + b > n) {
                cout << "NO" << "\n";
            } else {
                cout << "YES" << "\n";
                for (int i = 1; i <= n; i++) {
                    cout << i << " ";
                }
                cout << "\n";
                int equalEls = n - (a + b);
                for (int i = 1; i <= equalEls; i++) {
                    cout << i << " ";
                }
                // a sequence from 0..(n - 1 - equalEls)
                int i = n - b - equalEls;
                
                for (int k = 0; k < n - equalEls; k++) {
                    cout << i + equalEls + 1 << " ";
                    i++;
                    i %= (n - equalEls);
                }
                cout << "\n";
            }
        }
    }
}