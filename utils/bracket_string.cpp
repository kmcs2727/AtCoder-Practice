#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

bool is_valid(string S) {
    stack<char> K;
    for(auto c : S) {
        if(c == ')') {
            if(K.size() == 0) {
                return false;
            }
            K.pop();
        } else {
            K.push('(');
        }
    }
    return K.empty();
}

int main() {
    string S;
    cin >> S;
    if(is_valid(S)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}