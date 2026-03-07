#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{"; for (int i = 0; i < v.size(); ++i) { if (i) os << ", "; os << v[i]; } return os << "}";
}
template<typename... Args> void dbg_out(Args&&... args) { ((cerr << " " << args), ...) << endl; }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

bool multipleTests = true;

void solve() {
    ll x, y; cin >> x >> y;

    ll dp[64][2][2];
    for(int i=0; i<64; ++i) 
        for(int j=0; j<2; ++j) 
            for(int k=0; k<2; ++k) dp[i][j][k] = -1;
    
    dp[0][0][0] = 0;

    bitset<64> s(x), t(y);

    for (ll i = 0; i < 60; i++) {
        for (ll cx = 0; cx < 2; cx++) {
            for (ll cy = 0; cy < 2; cy++) {
                ll curr = dp[i][cx][cy];
                if(curr == -1) continue;

                // adding 0
                ll nx0 = (s[i] + cx) & 1;
                ll ncx0 = (s[i] + cx) / 2;
                ll ny0 = (t[i] + cy) & 1; 
                ll ncy0 = (t[i] + cy) / 2; 
                if(!(nx0 & ny0)) dp[i + 1][ncx0][ncy0] = curr;

                // adding 1
                ll nx1 = (s[i] + cx + 1) & 1;
                ll ncx1 = (s[i] + cx + 1) / 2;
                ll ny1 = (t[i] + cy + 1) & 1; 
                ll ncy1 = (t[i] + cy + 1) / 2; 
                if(!(nx1 & ny1)) dp[i + 1][ncx1][ncy1] = curr + (1LL << i);
            }
        }
    }
    cout << dp[60][0][0] << endl; 
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