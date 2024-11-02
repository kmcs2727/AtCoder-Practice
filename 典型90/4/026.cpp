#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_z

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> flag(N, -1);
    queue<pair<int, int>> Q;
    Q.push({0, 1});
    while(!Q.empty()) {
        int pos = Q.front().first;
        int f = Q.front().second;
        Q.pop();
        if(flag[pos] != -1) {
            continue;
        }
        flag[pos] = f;
        if(f == 0) {
            f = 1;
        } else {
            f = 0;
        }
        for(int i = 0; i < G[pos].size(); i++) {
            if(flag[G[pos][i]] == -1) {
                Q.push({G[pos][i], f});
            }
        }
    }
    vector<int> ans1;
    vector<int> ans2;
    rep(i, N) {
        if(flag[i] == 1) {
            ans1.push_back(i + 1);
        } else {
            ans2.push_back(i + 1);
        }
    }
    if(ans1.size() > ans2.size()) {
        rep(i, N / 2) {
            if(i == 0) {
                cout << ans1[i];
            } else {
                cout << " " << ans1[i];
            }
        }
    } else {
        rep(i, N / 2) {
            if(i == 0) {
                cout << ans2[i];
            } else {
                cout << " " << ans2[i];
            }
        }
    }
    cout << endl;
    return 0;
}