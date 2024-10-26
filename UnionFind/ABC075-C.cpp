#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/atc001/tasks/unionfind_a

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
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    vector<int> b(M);
    rep(i, M) cin >> a[i] >> b[i];
    int ans = 0;
    rep(i, M) {
        UnionFind UF;
        UF.init(N);
        rep(j, M) {
            if(i != j) {
                UF.unite(a[j], b[j]);
            }
        }
        if(UF.same(a[i], b[i]) == false) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}