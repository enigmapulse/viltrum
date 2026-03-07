#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    // any move is equivalent to blocking the rows and cols in it the move
    // so say I move r,c then rows numbered r, c and cols numbered r,c
    // all are blocked
    // when r != c then there are four lines other wise 2
    // let's try solving the problem when none of the k moves has happened
    // so in a way our aim is to block all the rows and cols
    // that is our move should cover the entire 1 to n
    // we must make disjoint sets of size 1 or 2
    // so for 2*2 following are valid
    // {{1} {2}} {{1, 2}} {{2, 1}} so order matters in the two sized sets
    // to break it into a problem of size n - 1 all you need to do is choose
    // an element in the diagonal -> n ways
    // otherwise it reduces to a problem of size n - 2 -> n^2 - n ways to choose a non diagonal element
    vector<ll> dp(10);
    dp[1] = 1; dp[2] = 3;
    for (ll i = 3; i < 10; i++) {
        dp[i] = (dp[i - 1]) + 2*(i - 1)*(dp[i - 2]);
        cout << dp[i] << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}