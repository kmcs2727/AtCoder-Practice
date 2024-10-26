#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// 鉄則本9.6 (A66)
// URL: https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bn
class UnionFind {
  public:
    int parent[100009];
    int siz[100009];

    void init(int N) {
        for(int i = 1; i <= N; i++) {
            parent[i] = -1;
            siz[i] = 1;
        }
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
    int N, Q;
    cin >> N >> Q;
    UnionFind UF;
    UF.init(N);
    rep(q, Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            UF.unite(u, v);
        } else {
            if(UF.same(u, v)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}