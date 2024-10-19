#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/typical90/tasks/typical90_aa

int main() {
    int N;
    cin >> N;
    set<string> user;
    rep(i, N) {
        string name;
        cin >> name;
        if(user.count(name) == 0) {
            cout << i + 1 << endl;
            user.insert(name);
        }
    }
    return 0;
}