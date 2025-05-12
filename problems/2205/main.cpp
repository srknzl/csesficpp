#include <bits/stdc++.h>

#define ll long long 

using namespace std;
constexpr ll MOD = 1000000007;



void generate(int n, vector<int>& v) {
    if (n == 2) {
        v.push_back(0);
        v.push_back(1);
        v.push_back(3);
        v.push_back(2);
        return;
    }
    generate(n - 1, v);
    vector<int> newNumbers;
    newNumbers.reserve(1 << (n - 1));
    for (int i = v.size() - 1; i >= 0; i--) {
        newNumbers.push_back((v[i] | (1 << (n - 1))));
    }
    for (int i : newNumbers) v.push_back(i);
}

void printToStdout(int node, int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << ((node & (1 << i)) > 0 ? 1 : 0);
    }
    cout << "\n";
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << "\n" << 1 << "\n";
        return 0;
    }
    vector<int> v;
    v.reserve(1 << n);
    generate(n, v);
    for (int i : v) {
        printToStdout(i, n);
    }
}