#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> moves[n];
    moves[0].push_back(make_pair(1, 3));
    for (int i = 1; i < n; i++) {
        for (pair<int, int> p : moves[i - 1]) {
            // 1 2 3
            // 1 3 2
            int f = p.first == 1 ? 1 : 5 - p.first;
            int s = p.second == 1 ? 1 : 5 - p.second;
            moves[i].push_back(make_pair(f, s));
        } 
        moves[i].push_back(make_pair(1, 3));
        // 1 2 3 
        // 2 1 3
        for (pair<int, int> p : moves[i - 1]) {
            int f = p.first == 3 ? 3 : 3 - p.first ;
            int s = p.second == 3 ? 3 : 3 - p.second;
            moves[i].push_back(make_pair(f, s));
        }
    }
    cout << moves[n - 1].size() << endl;
    for (pair<int, int> p : moves[n - 1]) {
        cout << p.first << " " << p.second << "\n";
    }
}