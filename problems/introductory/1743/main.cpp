#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  string s;
  cin >> s;
  int freq[26] = {};
  int maxFreq = -1, total = 0;
  for (size_t i = 0; i < s.length(); i++) {
    freq[s[i] - 'A']++;
    if (freq[s[i] - 'A'] > maxFreq) {
      maxFreq = freq[s[i] - 'A'];
    }
    total++;
  }

  if (maxFreq > (total + 1) / 2) {
    cout << -1 << endl;
    return 0;
  }

  int prev = -1;
  for (size_t i = 0; i < s.length(); i++) {
    int maxFreq = -1, total = 0, maxFreqIndex = 0;
    for (int j = 0; j < 26; j++) {
      if (freq[j] > maxFreq) {
        maxFreqIndex = j;
        maxFreq = freq[j];
      }
      total += freq[j];
    }
    if (maxFreq * 2 - 1 == total) {
      for (int i = 0; i < maxFreq * 2 - 1; i++) {
        if (i % 2 == 0) {
          cout << (char) (maxFreqIndex + 'A');
          freq[maxFreqIndex]--;
        } else {
          for (int j = 0; j < 26; j++) {
            if (freq[j] > 0 && j != maxFreqIndex) {
              freq[j]--;
              cout << (char) (j + 'A');
              break;
            }
          }
        }
      }
    } else {
      for (int j = 0; j < 26; j++) {
        if (freq[j] > 0 && j != prev) {
          freq[j]--;
          prev = j;
          cout << (char) (j + 'A');
          break;
        }
      }
    }
  }
}