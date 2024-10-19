#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_j

int main() {
    int N;
    cin >> N;
    vector<vector<int>> P(2, vector<int>(N + 2, 0));
    rep(i, N) {
        int c, p;
        cin >> c >> p;
        c--;
        P[c][i + 1] = p;
    }
    for(int i = 0; i <= N; i++) {
        P[0][i + 1] += P[0][i];
        P[1][i + 1] += P[1][i];
    }
    int Q;
    cin >> Q;
    rep(q, Q) {
        int l, r;
        cin >> l >> r;
        cout << P[0][r] - P[0][l - 1] << " " << P[1][r] - P[1][l - 1] << endl;
    }
    return 0;
}