#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc150/tasks/abc150_c

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];
    vector<int> J(N);
    rep(i, N) J[i] = i + 1;
    int a;
    int b;
    int i = 1;
    do {
        if(P == J) {
            a = i;
        }
        if(Q == J) {
            b = i;
        }
        i++;
    } while(next_permutation(J.begin(), J.end()));
    cout << abs(a - b) << endl;
    return 0;
}