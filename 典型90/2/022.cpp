#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks

ll gcd(ll a, ll b) {
    if(a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    ll n = gcd(A, gcd(B, C));
    cout << A / n + B / n + C / n - 3 << endl;
    return 0;
}