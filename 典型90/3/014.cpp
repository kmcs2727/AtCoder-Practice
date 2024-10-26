#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_n

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll sum = 0;
    rep(i, N) sum += abs(A[i] - B[i]);
    cout << sum << endl;
    return 0;
}