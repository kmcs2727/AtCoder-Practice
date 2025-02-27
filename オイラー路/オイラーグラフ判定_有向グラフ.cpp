#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// オイラーグラフ: グラフが連結 + 全ての頂点で入次数=出次数

bool is_graph_connected(vector<vector<int>> &G) {
    int N = (int)G.size();
    queue<int> Q;
    vector<bool> visited(N, false);
    Q.push(0);
    while(!Q.empty()) {
        int pos = Q.front();
        Q.pop();
        if(visited[pos]) {
            continue;
        }
        visited[pos] = true;
        for(int i = 0; i < (int)G[pos].size(); i++) {
            if(visited[G[pos][i]] == false) {
                Q.push(G[pos][i]);
            }
        }
    }
    rep(i, N) {
        if(visited[i] == false) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N); // 出次数を管理
    vector<vector<int>> H(N); // 入次数を管理
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        H[b].push_back(a);
    }
    if(is_graph_connected(G)) {
        rep(i, N) {
            if(G[i].size() != H[i].size()) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}