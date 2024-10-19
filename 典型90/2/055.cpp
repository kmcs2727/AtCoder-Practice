#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_bc

int main() {
    ll N, P, Q;
    cin >> N >> P >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    for(int a = 0; a < N; a++) {
        for(int b = a + 1; b < N; b++) {
            for(int c = b + 1; c < N; c++) {
                for(int d = c + 1; d < N; d++) {
                    for(int e = d + 1; e < N; e++) {
                        if(A[a] * A[b] % P * A[c] % P * A[d] % P * A[e] % P ==
                           Q) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}