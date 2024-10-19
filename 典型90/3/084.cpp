#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_cf

int main() {
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> G;
    for(int i = 0; i < N;) {
        int j = i;
        while(j < N && S[i] == S[j]) {
            j++;
        }
        G.push_back(j - i);
        i = j;
    }
    ll all = N * (N - 1) / 2 + N;
    ll ex = 0;
    for(auto d : G) {
        ex += d * (d - 1) / 2;
        ex += d;
    }
    cout << all - ex << endl;
    return 0;
}