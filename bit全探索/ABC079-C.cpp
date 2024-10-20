#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc079/tasks/abc079_c

int main() {
    string S;
    cin >> S;
    for(int bit = 0; bit < (1 << 3); bit++) {
        int sum = (int)(S[0] - '0');
        string ans = "";
        rep(i, 3) {
            if(bit & (1 << i)) {
                sum += (int)(S[i + 1] - '0');
            } else {
                sum -= (int)(S[i + 1] - '0');
            }
        }
        if(sum == 7) {
            cout << S[0];
            rep(i, 3) {
                if(bit & (1 << i)) {
                    cout << "+" << S[i + 1];
                } else {
                    cout << "-" << S[i + 1];
                }
            }
            cout << "=7" << endl;
            return 0;
        }
    }
    return 0;
}