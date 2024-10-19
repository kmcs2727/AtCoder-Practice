#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// n進数を10進数に変換する関数
// string --> long long
ll base_n_to_10(string N, int n) {
    ll res = 0;
    for(int i = 0; i < (int)N.size(); i++) {
        res = res * n + int(N[i] - '0');
    }
    return res;
}

// 10進数をn進数に変換する関数
// long long --> string
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
    ll N;
    cin >> N;
    cout << base_10_to_n(N, 6) << endl;
    string temp = base_10_to_n(N, 6);
    cout << base_n_to_10(temp, 6) << endl;
    return 0;
}