#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;
constexpr int validMoves[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = INT_MAX;
        }
    }
    queue<pair<int, int>> q;
    grid[0][0] = 0;
    grid[1][0] = 3;
    grid[0][1] = 3;
    grid[1][1] = 4;
    q.push(make_pair(0, 0 * n + 0));
    q.push(make_pair(3, 0 * n + 1));
    q.push(make_pair(3, 1 * n + 0));
    q.push(make_pair(4, 1 * n + 1));
    while (!q.empty()) {
        pair<int, int> next = q.front();
        q.pop();
        if (next.first > grid[next.second / n][next.second % n]) continue;
        for (auto& move : validMoves) {
            int newX = next.second / n + move[0], newY = next.second % n + move[1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] > next.first + 1) {
                grid[newX][newY] = next.first + 1;
                q.push(make_pair(next.first + 1, newX * n + newY));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    
}