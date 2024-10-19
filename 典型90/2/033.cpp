#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_ag

int main() {
    int H, W;
    cin >> H >> W;
    if(H == 1 || W == 1) {
        cout << H * W << endl;
        return 0;
    }
    cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
    return 0;
}