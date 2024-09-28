#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc221/tasks/abc221_c

int main() {
    string N;
    cin >> N;
    sort(N.begin(), N.end());
    ll ans = 0;
    do {
        for(int i = 1; i <= N.size() - 1; i++) {
            string t1 = N.substr(0, i);
            string t2 = N.substr(i);
            if(t1[0] != '0' && t2[0] != '0') {
                ll product = stoll(t1) * stoll(t2);
                ans = max(ans, product);
            }
        }
    } while(next_permutation(N.begin(), N.end()));
    cout << ans << endl;
    return 0;
}