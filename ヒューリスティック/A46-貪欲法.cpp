#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_at

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    vector<bool> visited(N, false);
    vector<int> ans;
    int now = 0;
    int visit_count = 0;
    while(1) {
        visited[now] = true;
        visit_count++;
        ans.push_back(now + 1);
        if(visit_count == N) {
            break;
        }
        int temp = INT_MAX;
        int next = 0;
        rep(i, N) {
            if(!visited[i]) {
                int dis = (X[now] - X[i]) * (X[now] - X[i]) +
                          (Y[now] - Y[i]) * (Y[now] - Y[i]);
                if(temp > dis) {
                    temp = dis;
                    next = i;
                }
            }
        }
        now = next;
    }
    ans.push_back(1);
    for(auto d : ans) {
        cout << d << endl;
    }
    return 0;
}