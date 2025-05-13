#include <iostream>

#define ll long long 

using namespace std;


ll f(ll n) {
    return (n * n * n * n - 9 * n * n + 24 * n - 16) / 2;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << f(i) << "\n";
    }
    return 0;
}
