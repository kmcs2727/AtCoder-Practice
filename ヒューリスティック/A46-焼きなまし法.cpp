#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_at

int N;
vector<int> X(1000);
vector<int> Y(1000);

// a以上b以下の乱数
int rand_int(int a, int b) { return a + rand() % (b - a + 1); }

// 0以上1以下の乱数
double rand_double() { return 1.0 * rand() / RAND_MAX; }

int calc_distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int calc_score(vector<int> &ans) {
    int temp = 0;
    for(int i = 0; i < N; i++) {
        temp += calc_distance(X[ans[i] - 1], Y[ans[i] - 1], X[ans[i + 1] - 1],
                              Y[ans[i + 1] - 1]);
    }
    return temp;
}

vector<int> make_init_ans() {
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
    return ans;
}

int main() {
    cin >> N;
    rep(i, N) cin >> X[i] >> Y[i];
    // 初期解は貪欲法で生成
    vector<int> ans = make_init_ans();
    int current_score = calc_score(ans);
    rep(q, 200000) {
        int L = rand_int(1, N - 1);
        int R = rand_int(1, N - 1);
        if(L > R) {
            swap(L, R);
        }
        reverse(ans.begin() + L, ans.begin() + R + 1);
        int temp_score = calc_score(ans);
        double T = 30.00 - 28.00 * (q + 1) / 200000.0;
        double Probability = exp(min(0.0, (current_score - temp_score) / T));
        if(Probability > rand_double()) {
            current_score = temp_score;
        } else {
            reverse(ans.begin() + L, ans.begin() + R + 1);
        }
    }
    for(auto d : ans) {
        cout << d << endl;
    }
    return 0;
}