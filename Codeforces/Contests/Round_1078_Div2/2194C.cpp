#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (ll _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<string> a(k); inarr(a, k);

    vector<vector<bool>> has(n, vector<bool>(26, false));
    for(string& s : a) {
        for(ll i = 0; i < n; ++i) {
            has[i][s[i] - 'a'] = true;
        }
    }

    vector<ll> div2; 
    for (ll i = 1; i * i <= n; i++) {
        if(n % i != 0) continue;
        ll res1 = i, res2 = n / i;
        if (res1 != res2) div2.push_back(res2);
        string patt = "";
        bool chk2 = true;
        for (ll j = 0; j < res1; j++) {
            char best_ch = 0;
            for(char ch = 'a'; ch <= 'z'; ++ch) {
                bool chk1 = true;
                for (ll pos = j; pos < n; pos += res1) {
                    if (!has[pos][ch - 'a']) {
                        chk1 = false;
                        break;
                    }
                }
                if (chk1) {
                    best_ch = ch;
                    break; 
                }
            }
            if (best_ch == 0) {
                chk2 = false;
                break;
            }
            patt += best_ch;
        }
        if (chk2) {
            string ans = "";
            for (ll r = 0; r < n / res1; ++r) ans += patt;
            cout << ans << endl;
            return;
        }
    }

    reverse(all(div2));
    
    for (ll d : div2) {
        string patt = "";
        bool chk2 = true;
        for (ll j = 0; j < d; j++) {
            char best_ch = 0;
            for(char ch = 'a'; ch <= 'z'; ++ch) {
                bool chk1 = true;
                for (ll pos = j; pos < n; pos += d) {
                    if (!has[pos][ch - 'a']) {
                        chk1 = false;
                        break;
                    }
                }
                if (chk1) {
                    best_ch = ch;
                    break;
                }
            }
            if (best_ch == 0) {
                chk2 = false;
                break;
            }
            patt += best_ch;
        }

        if (chk2) {
            string ans = "";
            for (ll r = 0; r < n / d; ++r) ans += patt;
            cout << ans << endl;
            return;
        }
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