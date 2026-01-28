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
    string s; cin >> s;

    auto chk = [&] (string& x, ll start, ll end) {
        ll n = x.size(); bool ret = true;
        for (ll i = start; i <= end; i++) ret &= (x[i] == x[end - i]);
        return ret;
    };

    ll sz = s.size();

    vector<vector<ll>> dp(sz, vector<ll> (sz, 1e12)); // min edit distance to make a palindrome consdering 
    // only i initial char insert is never ideal?? if I can make a palindrome by inserting
    // one then I can also make it by deleting one element, so we have two ops deletion and
    // substitutions. so we need dp[i][j] is the min distance for s[i ... j]
    // so dp[i][j] = min(dp[i][j - 1] + 1, dp[i + 1][j - 1] + 1)
    // base case consdition i <= j
    // s[0 ,, 2] = 'abcba'
    // I still need to check if something is becoming palindrome somehow

    for (ll j = 1; j <= sz; j++) {
        for (ll i = 0; i <= sz-j; i++) {
            ll st=i;
            ll last=i+j-1;
            if(st == last) {dp[st][last] = 0; continue;}
            if(st == last - 1) {
                if(s[st] != s[last]) {dp[st][last] = 1;}
                else dp[st][last] = 0;
                continue;
        }
            dp[st][last] = min({dp[st][last] ,dp[st + 1][last] + 1, dp[st][last - 1] + 1, dp[st + 1][last - 1] + (s[st] != s[last])});
            // if(chk(s, i, j)) dp[i][j] = 0;
        }
    }
    
    cout << dp[0][sz - 1] << endl;
    dbg(dp);
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