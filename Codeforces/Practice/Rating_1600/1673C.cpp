#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
ll MAXN = 4 * 1e4 + 5;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = true;

vector<ll> pal;
vector<ll> cnt(MAXN, 0);

void precompute() {
    for (ll i = 1; i < MAXN; i++) {
        string s = to_string(i);
        bool chk = true;
        for (ll j = 0; j < s.size(); j++) {
            chk &= (s[j] == s[s.size() - 1 - j]);
        }
        if(chk) pal.push_back(i);
    }
    
    cnt[0] = 1;
    for (ll i = 0; i < pal.size(); i++) {
        for (ll j = 1; j < MAXN; j++) {
            cnt[j] = (cnt[j] + (j >= pal[i] ? cnt[j - pal[i]] : 0ll)) % MOD;
        }
    }
}

void solve() {
    ll n; cin >> n;
    cout << cnt[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    precompute();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}