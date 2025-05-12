#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ll n;
    cin >> n;
    ll nInitial = n;
    if ((n * (n + 1) / 2) % 2 == 1) {
        cout << "NO" << endl;
        return 0; 
    }
    cout << "YES" << "\n";
    ll goal = n * (n + 1) / 4;
    vector<int> set1;
    while (goal >= n) {
        set1.push_back(n);
        goal -= n;
        n--;
    }
    int set1Size = set1.size();
    if (goal > 0) set1Size++;
    cout << set1Size << "\n"; 
    for (auto i : set1) cout << i << " ";
    if (goal > 0) cout << goal << " ";
    cout << endl;
    cout << nInitial - set1Size << "\n";
    while (n > 0) {
        if (n != goal) cout << n << " ";
        n--;
    }
    cout << endl;
    return 0;
}
