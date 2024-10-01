#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc232/tasks/abc232_c

int main() {
    int N, M;
    cin >> N >> M;
    vector<set<int>> T(N);
    vector<set<int>> A(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        T[a].insert(b);
        T[b].insert(a);
    }
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        A[a].insert(b);
        A[b].insert(a);
    }
    vector<int> J(N);
    rep(i, N) J[i] = i;
    do {
        map<int, int> C;
        bool flag = true;
        rep(i, N) C[J[i]] = i;
        rep(i, N) {
            set<int> temp;
            for(auto d : A[J[i]]) {
                temp.insert(C[d]);
            }
            if(temp != T[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    } while(next_permutation(J.begin(), J.end()));
    cout << "No" << endl;
    return 0;
}