#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_p

int main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    ll ans = 10000;
    for(ll i = 0; i < 10000; i++) {
        for(ll j = 0; i + j < 10000; j++) {
            ll res = N - A * i - B * j;
            if(res >= 0 && res % C == 0) {
                ans = min(ans, i + j + res / C);
            }
        }
    }
    cout << ans << endl;
    return 0;
}