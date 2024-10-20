#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc249/tasks/abc249_c

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    int ans = 0;
    for(int bit = 0; bit < (1 << N); bit++) {
        map<char, int> T;
        int temp = 0;
        rep(i, N) {
            if(bit & (1 << i)) {
                set<char> t;
                rep(j, S[i].size()) t.insert(S[i][j]);
                for(auto c : t) {
                    T[c]++;
                }
            }
        }
        for(char c = 'a'; c <= 'z'; c++) {
            if(T[c] == K) {
                temp++;
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}