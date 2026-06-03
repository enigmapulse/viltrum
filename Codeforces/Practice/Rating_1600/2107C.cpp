#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
ll MINF = -1e18;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> a(n); inarr(a, n);
    for (ll i = 0; i < n; i++) if(s[i] == '0') a[i] = MINF;
    
    ll f = -1;
    for (ll i = 0; i < n; i++) {
        if(s[i] == '0') {f = i; break;}
    }

    if (f == -1) {
        vector<ll> max_end(n); max_end[0] = a[0];
        for (ll i = 1; i < n; i++) {
            max_end[i] = max(max_end[i - 1] + a[i], a[i]);
        }
        if(*max_element(all(max_end)) == k) {
            cout << "YES" << endl;
            for (ll i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else cout << "NO" << endl;
        return;
    }

    auto fn = [&] () {
        vector<ll> max_end(n); max_end[0] = a[0];
        for (ll i = 1; i < n; i++) {
            max_end[i] = max(max_end[i - 1] + a[i], a[i]);
        }
        for (ll i = 0; i < n; i++) if (max_end[i] > k) return false;
        return true;
    };

    auto chk = [&] (ll x) {
        a[f] = x;
        return fn();
    };

    ll lo = -1e18, hi = 1e18;
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1)/2;
        if(chk(mid)) lo = mid;
        else hi = mid - 1;
    }
    a[f] = lo;
        vector<ll> max_end(n); max_end[0] = a[0];
        for (ll i = 1; i < n; i++) {
            max_end[i] = max(max_end[i - 1] + a[i], a[i]);
        }
        if(*max_element(all(max_end)) == k) {
            cout << "YES" << endl;
            for (ll i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else cout << "NO" << endl;
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