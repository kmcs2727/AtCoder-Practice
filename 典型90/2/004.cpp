#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_d

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    vector<int> row(H, 0);
    vector<int> col(W, 0);
    rep(i, H) rep(j, W) row[i] += A[i][j];
    rep(j, W) rep(i, H) col[j] += A[i][j];
    rep(i, H) {
        rep(j, W) cout << row[i] + col[j] - A[i][j] << " ";
        cout << endl;
    }
    return 0;
}