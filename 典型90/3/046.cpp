#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_at

int main() {
    int N;
    cin >> N;
    vector<ll> AN(46, 0);
    vector<ll> BN(46, 0);
    vector<ll> CN(46, 0);
    rep(i, N) {
        ll n;
        cin >> n;
        n %= 46;
        AN[n]++;
    }
    rep(i, N) {
        ll n;
        cin >> n;
        n %= 46;
        BN[n]++;
    }
    rep(i, N) {
        ll n;
        cin >> n;
        n %= 46;
        CN[n]++;
    }
    ll ans = 0;
    for(int i = 0; i < 46; i++) {
        for(int j = 0; j < 46; j++) {
            for(int k = 0; k < 46; k++) {
                if((i + j + k) % 46 == 0) {
                    ans += AN[i] * BN[j] * CN[k];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}