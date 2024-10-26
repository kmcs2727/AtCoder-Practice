#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_h

const int mod = 1000000007;

int main() {
    int N;
    string S;
    string T = "atcoder";
    cin >> N >> S;
    vector<vector<int>> dp(N + 1, vector<int>(8, 0));
    rep(i, N + 1) dp[i][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 7; j++) {
            if(i >= j) {
                if(S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                dp[i][j] += dp[i - 1][j];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[N][7] << endl;
    return 0;
}