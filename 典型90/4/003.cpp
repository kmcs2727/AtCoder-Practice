#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_c

int tree_size(int N, vector<vector<int>> &G) {
    vector<int> dis_f(N, -1);
    vector<int> dis_l(N, -1);
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    while(!Q.empty()) {
        int pos = Q.front().first;
        int dis = Q.front().second;
        Q.pop();
        if(dis_f[pos] != -1) {
            continue;
        }
        dis_f[pos] = dis;
        for(int i = 0; i < (int)G[pos].size(); i++) {
            if(dis_f[G[pos][i]] == -1) {
                Q.push({G[pos][i], dis + 1});
            }
        }
    }
    int temp = -1;
    int pos_l;
    rep(i, N) {
        if(temp < dis_f[i]) {
            temp = dis_f[i];
            pos_l = i;
        }
    }
    Q.push({pos_l, 0});
    while(!Q.empty()) {
        int pos = Q.front().first;
        int dis = Q.front().second;
        Q.pop();
        if(dis_l[pos] != -1) {
            continue;
        }
        dis_l[pos] = dis;
        for(int i = 0; i < (int)G[pos].size(); i++) {
            if(dis_l[G[pos][i]] == -1) {
                Q.push({G[pos][i], dis + 1});
            }
        }
    }
    int size = -1;
    rep(i, N) size = max(size, dis_l[i]);
    return size;
}

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
    cout << tree_size(N, G) + 1 << endl;
    return 0;
}