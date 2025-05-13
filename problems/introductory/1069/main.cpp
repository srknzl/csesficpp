#include <iostream>

#define ll long long 

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    string sequence;
    cin >> sequence;

    int longest = 0, ans = 0; 
    char current = 0;
    for (auto &ch : sequence) {
        if (ch == current) {
            longest++;
        } else {
            ans = max(ans, longest);
            longest = 1;
            current = ch;
        }
    }
    ans = max(ans, longest);
    cout << ans << endl;
    return 0;
}
