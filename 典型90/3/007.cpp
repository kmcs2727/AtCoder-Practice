#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_g

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    int Q;
    cin >> Q;
    rep(q, Q) {
        ll b;
        cin >> b;
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        if(pos == 0) {
            cout << abs(A[pos] - b) << endl;
        } else {
            cout << min(abs(A[pos] - b), abs(A[pos - 1] - b)) << endl;
        }
    }
    return 0;
}