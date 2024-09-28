#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc215/tasks/abc215_c

int main() {
    string S;
    int K;
    cin >> S >> K;
    sort(S.begin(), S.end());
    int i = 1;
    do {
        if(i == K) {
            cout << S << endl;
            return 0;
        }
        i++;
    } while(next_permutation(S.begin(), S.end()));
    return 0;
}