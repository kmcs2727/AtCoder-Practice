#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc034/tasks/abc034_c

const int mod = 1000000007;

// a^p mod p を求める関数
// 計算量O(log(b))
ll calc(ll a, ll b, ll p) {
    if(b == 0) {
        return 1;
    } else if(b % 2 == 0) {
        ll d = calc(a, b / 2, p);
        return (d * d) % p;
    } else {
        return (a * calc(a, b - 1, p)) % p;
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<ll> R(H + W, 1);
    for(int i = 1; i <= H + W - 2; i++) {
        R[i] = R[i - 1] * i % mod;
    }
    ll ans = R[H + W - 2] * calc(R[H - 1], mod - 2, mod) % mod *
             calc(R[W - 1], mod - 2, mod) % mod;
    cout << ans << endl;
    return 0;
}