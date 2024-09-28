#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc145/tasks/abc145_c

int main() {
    int N;
    cin >> N;
    vector<int> x(N);
    vector<int> y(N);
    rep(i, N) cin >> x[i] >> y[i];
    vector<int> J(N);
    rep(i, N) J[i] = i;
    double dis = 0;
    do {
        rep(i, N - 1) {
            int x2 = (x[J[i]] - x[J[i + 1]]) * (x[J[i]] - x[J[i + 1]]);
            int y2 = (y[J[i]] - y[J[i + 1]]) * (y[J[i]] - y[J[i + 1]]);
            dis += sqrt(x2 + y2);
        }
    } while(next_permutation(J.begin(), J.end()));
    for(int i = 1; i <= N; i++) {
        dis /= i;
    }
    cout << fixed << setprecision(10);
    cout << dis << endl;
    return 0;
}