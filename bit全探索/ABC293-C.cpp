#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc293/tasks/abc293_c

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    int ans = 0;
    for(int bit = 0; bit < (1 << H + W - 2); bit++) {
        int count = 0;
        rep(i, H + W - 2) {
            if(bit & (1 << i)) {
                count++;
            }
        }
        if(count != H - 1) {
            continue;
        }
        set<int> T;
        int I = 0;
        int J = 0;
        T.insert(A[I][J]);
        bool flag = true;
        rep(i, H + W - 2) {
            if(bit & (1 << i)) {
                I++;
            } else {
                J++;
            }
            if(T.count(A[I][J]) != 0) {
                flag = false;
            }
            T.insert(A[I][J]);
        }
        if(flag) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}