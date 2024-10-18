#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_bi

int main() {
    int Q;
    cin >> Q;
    vector<int> A(Q, -1);
    int top = 0;
    int but = 0;
    rep(q, Q) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            top--;
            if(top == -1) {
                top = Q - 1;
            }
            A[top] = x;
        } else if(t == 2) {
            A[but] = x;
            but++;
        } else {
            if(Q - top >= x) {
                cout << A[top + x - 1] << endl;
            } else {
                cout << A[x - Q + top - 1] << endl;
            }
        }
    }
    return 0;
}