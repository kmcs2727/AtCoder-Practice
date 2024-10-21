#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

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
    ll a, b, p;
    cin >> a >> b >> p;
    return 0;
}
