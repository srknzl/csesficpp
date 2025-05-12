#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string s;
    cin >> s;
    int freq[26] = {};
    for (auto c : s) {
        freq[c - 'A']++;
    }
    int oddCount = 0, oddLetterIndex = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddCount++;
            if (oddLetterIndex == -1) oddLetterIndex = i;
        }
    }
    if ((s.length() % 2 == 1 && oddCount != 1) || (s.length() % 2 == 0 && oddCount != 0)) {
        cout << "NO SOLUTION" << endl;
    } else {
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (i == oddLetterIndex) continue;
            for (int j = 0; j < freq[i] / 2; j++) {
                ans += ('A' + i);
            }
        }
        if (oddLetterIndex != -1) {
            for (int j = 0; j < freq[oddLetterIndex]; j++) {
                ans += ('A' + oddLetterIndex);
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (i == oddLetterIndex) continue;
            for (int j = 0; j < freq[i] / 2; j++) {
                ans += ('A' + i);
            }
        }
        cout << ans << endl;
    }
}
