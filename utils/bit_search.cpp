#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

int main() {
    int N;
    cin >> N;
    // 2^N回の探索
    for(int bit = 0; bit < (1 << N); bit++) {
        string S = "";
        for(int i = 0; i < N; i++) {
            // 後ろからi番目に1が立っているか判定
            if(bit & (1 << i)) {
                S = "1" + S;
            } else {
                S = "0" + S;
            }
        }
        cout << S << endl;
    }
    return 0;
}