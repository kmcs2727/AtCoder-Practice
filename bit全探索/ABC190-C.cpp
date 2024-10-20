#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc190/tasks/abc190_c

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    vector<int> B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    int K;
    cin >> K;
    vector<int> C(K);
    vector<int> D(K);
    rep(i, K) {
        cin >> C[i] >> D[i];
        C[i]--;
        D[i]--;
    }
    int ans = 0;
    for(int bit = 0; bit < (1 << K); bit++) {
        vector<int> S(N, 0);
        int temp = 0;
        rep(i, K) {
            if(bit & (1 << i)) {
                S[C[i]]++;
            } else {
                S[D[i]]++;
            }
        }
        rep(i, M) {
            if(S[A[i]] && S[B[i]]) {
                temp++;
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}