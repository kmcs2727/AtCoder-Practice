#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc123/tasks/abc123_b

int main() {
    vector<int> P(5);
    rep(i, 5) cin >> P[i];
    sort(P.begin(), P.end());
    int ans = 100000;
    do {
        int temp_ans = 0;
        rep(i, 4) {
            temp_ans += P[i];
            if(P[i] % 10 != 0) {
                temp_ans += (10 - P[i] % 10);
            }
        }
        temp_ans += P[4];
        ans = min(ans, temp_ans);
    } while(next_permutation(P.begin(), P.end()));
    cout << ans << endl;
    return 0;
}