#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n); inarr(a, n); inarr(b, n);

    bool chk = true;
    for (ll i = 0; i < n; i++) {
        if (i < n - k || i >= k) {
            if (b[i] != -1 && b[i] != a[i]) chk = false;
        }
    }
    if(!chk) {
        cout <<"NO" << endl;
        return;
    }

    set<ll> vals;
    for (ll i = n - k; i < k; i++) {
        vals.insert(a[i]);
    }
    
    for (ll i = n - k; i < k; i++) {
        if(b[i] == -1) continue;
        else {
            auto it = vals.find(b[i]);
            if(it == vals.end()) chk = false;
            else vals.erase(it);
        }
    }
    if(!chk) {
        cout <<"NO" << endl;
        return;
    }

    cout << "YES" << endl;
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