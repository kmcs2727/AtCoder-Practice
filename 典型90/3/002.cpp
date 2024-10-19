#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_b

bool is_valid(string S) {
    stack<char> K;
    for(auto c : S) {
        if(c == ')') {
            if(K.size() == 0) {
                return false;
            }
            K.pop();
        } else {
            K.push('(');
        }
    }
    return K.empty();
}

int main() {
    int N;
    cin >> N;
    for(int bit = 0; bit < (1 << N); bit++) {
        string S = "";
        rep(i, N) {
            if(bit & (1 << i)) {
                S = ")" + S;
            } else {
                S = "(" + S;
            }
        }
        if(is_valid(S)) {
            cout << S << endl;
        }
    }
    return 0;
}