#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_l

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

class UnionFind {
  public:
    vector<int> parent;
    vector<int> siz;
    void init(int N) {
        parent.resize(N + 1, -1);
        siz.resize(N + 1, 1);
    }

    int root(int x) {
        while(1) {
            if(parent[x] == -1) {
                break;
            }
            x = parent[x];
        }
        return x;
    }

    void unite(int u, int v) {
        int RootU = root(u);
        int RootV = root(v);
        if(RootU == RootV) {
            return;
        }
        if(siz[RootU] < siz[RootV]) {
            parent[RootU] = RootV;
            siz[RootV] = siz[RootU] + siz[RootV];
        } else {
            parent[RootV] = RootU;
            siz[RootU] = siz[RootU] + siz[RootV];
        }
    }

    bool same(int u, int v) {
        if(root(u) == root(v)) {
            return true;
        }
        return false;
    }
};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W, '.'));
    vector<string> ans;
    int Q;
    cin >> Q;
    map<pair<int, int>, int> Z;
    int pos = 1;
    rep(i, H) rep(j, W) {
        Z[{i, j}] = pos;
        pos++;
    }
    UnionFind UF;
    UF.init(H * W);
    rep(q, Q) {
        int t;
        cin >> t;
        if(t == 1) {
            int r, c;
            cin >> r >> c;
            r--;
            c--;
            G[r][c] = '#';
            rep(i, 4) {
                int I = r + dx[i];
                int J = c + dy[i];
                if(0 <= I && I < H && 0 <= J && J < W) {
                    if(G[I][J] == '#') {
                        UF.unite(Z[{I, J}], Z[{r, c}]);
                    }
                }
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--;
            ca--;
            rb--;
            cb--;
            if(G[ra][ca] == '#' && G[rb][cb] == '#') {
                if(UF.same(Z[{ra, ca}], Z[{rb, cb}])) {
                    ans.push_back("Yes");
                } else {
                    ans.push_back("No");
                }
            } else {
                ans.push_back("No");
            }
        }
    }
    for(auto s : ans) {
        cout << s << endl;
    }
    return 0;
}