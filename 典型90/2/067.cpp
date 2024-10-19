#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_bo

ll base_n_to_10(string N, int n) {
    ll res = 0;
    for(int i = 0; i < (int)N.size(); i++) {
        res = res * n + int(N[i] - '0');
    }
    return res;
}

string base_10_to_n(ll N, int n) {
    if(N == 0) {
        return "0";
    }
    string res;
    while(N > 0) {
        res = char(N % n + '0') + res;
        N /= n;
    }
    return res;
}

int main() {
    string N;
    int K;
    cin >> N >> K;
    rep(k, K) {
        ll N_10 = base_n_to_10(N, 8);
        N = base_10_to_n(N_10, 9);
        rep(i, (int)N.size()) {
            if(N[i] == '8') {
                N[i] = '5';
            }
        }
    }
    cout << N << endl;
    return 0;
}