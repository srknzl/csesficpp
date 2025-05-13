#include <iostream>

#define ll long long 

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        if (y >= x) {
            if (y % 2 == 0) {
                cout << y * y - x + 1 << "\n";
            } else {
                cout << (y - 1) * (y - 1) + x << "\n";
            }
        } else {
            if (x % 2 == 0) {
                cout << (x - 1) * (x - 1) + y << "\n";
            } else {
                cout << x * x - y + 1 << "\n";
            }
        }
    }
    return 0;
}
