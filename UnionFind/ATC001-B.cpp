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
    int N, Q;
    cin >> N >> Q;
    UnionFind UF;
    UF.init(N);
    rep(q, Q) {
        int p, a, b;
        cin >> p >> a >> b;
        if(p == 0) {
            UF.unite(a, b);
        } else {
            if(UF.same(a, b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}