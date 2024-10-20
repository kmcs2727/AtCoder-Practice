#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc289/tasks/abc289_c

int main() {
    int N, M;
    cin >> N >> M;
    vector<set<int>> S(M);
    rep(i, M) {
        int c;
        cin >> c;
        rep(j, c) {
            int a;
            cin >> a;
            S[i].insert(a);
        }
    }
    int ans = 0;
    for(int bit = 0; bit < (1 << M); bit++) {
        set<int> T;
        rep(i, M) {
            if(bit & (1 << i)) {
                for(auto d : S[i]) {
                    T.insert(d);
                }
            }
        }
        bool flag = true;
        for(int i = 1; i <= N; i++) {
            if(T.count(i) == 0) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}