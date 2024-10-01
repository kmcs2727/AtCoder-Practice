#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/abc198/tasks/abc198_d

ll change(string S, map<char, int> C, vector<int> J) {
    ll num = 0;
    ll x = 1;
    for(int i = 0; i < S.size(); i++) {
        num += J[C[S[i]]] * x;
        x *= 10;
    }
    return num;
}

int main() {
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    reverse(S1.begin(), S1.end());
    reverse(S2.begin(), S2.end());
    reverse(S3.begin(), S3.end());
    set<char> temp;
    for(auto c : S1) {
        temp.insert(c);
    }
    for(auto c : S1) {
        temp.insert(c);
    }
    for(auto c : S2) {
        temp.insert(c);
    }
    for(auto c : S3) {
        temp.insert(c);
    }
    if(temp.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    map<char, int> C;
    vector<int> J(10);
    int i = 0;
    for(auto c : temp) {
        C[c] = i;
        i++;
    }
    rep(i, J.size()) J[i] = i;
    do {
        if(J[C[S1[S1.size() - 1]]] == 0) {
            continue;
        }
        if(J[C[S2[S2.size() - 1]]] == 0) {
            continue;
        }
        if(J[C[S3[S3.size() - 1]]] == 0) {
            continue;
        }
        ll N1 = change(S1, C, J);
        ll N2 = change(S2, C, J);
        ll N3 = change(S3, C, J);
        if(N1 + N2 == N3) {
            cout << N1 << endl;
            cout << N2 << endl;
            cout << N3 << endl;
            return 0;
        }
    } while(next_permutation(J.begin(), J.end()));
    cout << "UNSOLVABLE" << endl;
    return 0;
}