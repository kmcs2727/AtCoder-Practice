#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/arc025/tasks/arc025_1

int main() {
    vector<int> D(7);
    vector<int> J(7);
    rep(i, 7) cin >> D[i];
    rep(i, 7) cin >> J[i];
    int ans = 0;
    for(int bit = 0; bit < (1 << 7); bit++) {
        int temp = 0;
        rep(i, 7) {
            if(bit & (1 << i)) {
                temp += D[i];
            } else {
                temp += J[i];
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}