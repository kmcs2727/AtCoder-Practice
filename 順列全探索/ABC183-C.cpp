#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc183/tasks/abc183_c

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> T(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> T[i][j];
    vector<int> J(N - 1);
    rep(i, N - 1) J[i] = i + 1;
    int ans = 0;
    do {
        int temp_ans = 0;
        temp_ans += T[0][J[0]];
        temp_ans += T[J[N - 2]][0];
        rep(i, N - 2) temp_ans += T[J[i]][J[i + 1]];
        if(temp_ans == K) {
            ans++;
        }
    } while(next_permutation(J.begin(), J.end()));
    cout << ans << endl;
    return 0;
}