#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, N) for(int i = 0; i < (int)N; i++)

// URL: https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aw

struct State {
    int score;
    int X[29];
    char LastMove;
    int LastPos;
};

bool operator>(const State &a1, const State &a2) {
    if(a1.score > a2.score) {
        return true;
    } else {
        return false;
    }
}

const int WIDTH = 10000;
const int N = 20;
int T;
int P[109], Q[109], R[109];
int NumState[109];
State Beam[109][WIDTH];
char Answer[109];

void BeamSearch() {
    NumState[0] = 1;
    Beam[0][0].score = 0;
    for(int i = 1; i <= N; i++) {
        Beam[0][0].X[i] = 0;
    }
    for(int i = 1; i <= T; i++) {
        vector<State> Candidate;
        for(int j = 0; j < NumState[i - 1]; j++) {
            State SousaA = Beam[i - 1][j];
            SousaA.LastMove = 'A';
            SousaA.LastPos = j;
            SousaA.X[P[i]]++;
            SousaA.X[Q[i]]++;
            SousaA.X[R[i]]++;
            for(int k = 1; k <= 20; k++) {
                if(SousaA.X[k] == 0) {
                    SousaA.score++;
                }
            }
            State SousaB = Beam[i - 1][j];
            SousaB.LastMove = 'B';
            SousaB.LastPos = j;
            SousaB.X[P[i]]--;
            SousaB.X[Q[i]]--;
            SousaB.X[R[i]]--;
            for(int k = 1; k <= 20; k++) {
                if(SousaB.X[k] == 0) {
                    SousaB.score++;
                }
            }
            Candidate.push_back(SousaA);
            Candidate.push_back(SousaB);
        }
        sort(Candidate.begin(), Candidate.end(), greater<State>());
        NumState[i] = min(WIDTH, (int)Candidate.size());
        for(int j = 0; j < NumState[i]; j++) {
            Beam[i][j] = Candidate[j];
        }
    }
    return;
}

int main() {
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> P[i] >> Q[i] >> R[i];
    }
    BeamSearch();
    int CurrentPlace = 0;
    for(int i = T; i >= 1; i--) {
        Answer[i] = Beam[i][CurrentPlace].LastMove;
        CurrentPlace = Beam[i][CurrentPlace].LastPos;
    }
    for(int i = 1; i <= T; i++) {
        cout << Answer[i] << endl;
    }
    return 0;
}