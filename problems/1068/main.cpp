#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    long long n;
    cin >> n;

    cout << n << " ";
    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        cout << n << " ";
    }

    return 0;
}
