#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// 準オイラーグラフ: グラフが連結 +
// a: 入次数=出次数の頂点数
// b: 入次数=出次数+1の頂点数
// c: 入次数=出次数-1の頂点数 とするとき a=n or (a=n-2 and b=c=1)

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
        int a = 0, b = 0, c = 0;
        rep(i, N) {
            if(G[i].size() == H[i].size()) {
                a++;
            }
            if(G[i].size() + 1 == H[i].size()) {
                b++;
            }
            if(G[i].size() - 1 == H[i].size()) {
                c++;
            }
        }
        if(a == N || (a == N - 2 && b == c && b == 1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
    return 0;
}