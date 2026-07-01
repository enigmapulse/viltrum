#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    ll mx = 0;
    for (ll l = 0; l <= n; l++) {
        for (ll r = l - 1; r < n; r++) {
            string t = s;
            for (ll i = 0; i < l; i++) if(t[i] == 'N') t[i] = 'F';
            for (ll i = l; i <= r; i++) if(t[i] == 'N') t[i] = 'T';
            for (ll i = r + 1; i < n; i++) if(t[i] == 'N') t[i] = 'F';
            
            vector<ll> sm(n); ll ct = 0;
            for (ll i = 0; i < n; i++) {
                sm[i] = (t[i] == 'T');
                if(sm[i] == 0) {sm[i] = -1; ct++;}
            }
            
            ll best = 0, csm = 0;
            for (ll i = 0; i < n; i++) {
                csm += sm[i];
                if (csm > 0) csm = 0;
                best = min(best, csm);
            }
            ll now = ct + best;
            mx = max(mx, now);
        }
    }
    cout << mx << endl;
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