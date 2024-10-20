#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc045/tasks/arc061_a

int main() {
    string S;
    cin >> S;
    int N = (int)S.size();
    ll sum = 0;
    for(int bit = 0; bit < (1 << N - 1); bit++) {
        int pos = 0;
        string T = S;
        rep(i, N - 1) {
            if(bit & (1 << i)) {
                sum += stoll(T.substr(pos, i - pos + 1));
                pos = i + 1;
            }
        }
        T = T.substr(pos);
        if(T.size()) {
            sum += stoll(T);
        }
    }
    cout << sum << endl;
    return 0;
}