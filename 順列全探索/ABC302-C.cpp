#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc302/tasks/abc302_c

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    sort(S.begin(), S.end());
    do {
        bool flag = true;
        rep(i, N - 1) {
            int diff = 0;
            rep(j, M) {
                if(S[i][j] != S[i + 1][j]) {
                    diff++;
                }
            }
            if(diff != 1) {
                flag = false;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    } while(next_permutation(S.begin(), S.end()));
    cout << "No" << endl;
    return 0;
}