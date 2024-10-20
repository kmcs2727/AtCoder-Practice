#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_bl

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> B(N - 1);
    vector<ll> ans;
    rep(i, N) cin >> A[i];
    ll H = 0;
    rep(i, N - 1) {
        B[i] = A[i + 1] - A[i];
        H += abs(B[i]);
    }
    rep(q, Q) {
        int l, r, v;
        cin >> l >> r >> v;
        l--;
        r--;
        if(l - 1 >= 0) {
            H = H - abs(B[l - 1]) + abs(B[l - 1] + v);
            B[l - 1] += v;
        }
        if(r < N - 1) {
            H = H - abs(B[r]) + abs(B[r] - v);
            B[r] -= v;
        }
        ans.push_back(H);
    }
    for(auto d : ans) {
        cout << d << endl;
    }
    return 0;
}