#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        sum += num;
    }

    cout << (long long) n * (n + 1) / 2 - sum << endl;
    return 0;
}
