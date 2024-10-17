#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_x

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    int count = 0;
    rep(i, N) count += abs(A[i] - B[i]);
    if(K >= count && (K - count) % 2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}