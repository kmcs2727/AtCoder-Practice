#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_bz

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    rep(i, N) {
        int count = 0;
        for(int j = 0; j < (int)G[i].size(); j++) {
            if(G[i][j] < i) {
                count++;
            }
        }
        if(count == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}