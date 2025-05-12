#include <iostream>

#define ll long long 

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    int maxSoFar = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < maxSoFar) {
            ans += maxSoFar - arr[i];
        } else if (arr[i] > maxSoFar) {
            maxSoFar = arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}
