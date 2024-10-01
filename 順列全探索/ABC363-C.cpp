#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc363/tasks/abc363_c

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    sort(S.begin(), S.end());
    int ans = 0;
    do {
        bool flag = true;
        for(int i = 0; i <= N - K; i++) {
            string T = S.substr(i, K);
            string revT = T;
            reverse(revT.begin(), revT.end());
            if(revT == T) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans++;
        }
    } while(next_permutation(S.begin(), S.end()));
    cout << ans << endl;
    return 0;
}