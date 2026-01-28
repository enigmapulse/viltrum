#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m); inarr(a, n); inarr(b, m);

    ll mn = *min_element(all(b)), idx = -1;
    for (ll i = 0; i < m; i++) {
        b.push_back(b[i]);
        if(b[i] == mn) idx = i;
    }

    if(m == 1) {
        for (ll i = 0; i < n; i++) {
            if(a[i] > mn) a[i] = mn;
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    
    vector<ll> ins;
    for (ll i = 0; i < m; i++) ins.push_back(b[i + idx]);
    
    ll chosen = -1;
    for (ll i = 0; i <= n - m; i++) {
        if(a[i] > mn) {chosen = i; break;}
    }
    
    if(chosen != -1) {
        for (ll i = chosen; i <= n - m; i++) a[i] = mn;
        for (ll i = n - m; i < n; i++) a[i] = ins[i - n + m];
    }
    else {
        bool chk = false;
        for (ll i = n - m; i < n; i++) {
            if(a[i] != ins[i - n + m]) {
                chk = (a[i] > ins[i - n + m]);
                break;
            }
        }
        if(chk) for (ll i = n - m; i < n; i++) a[i] = ins[i - n + m];
    }

    for(auto x : a) cout << x << " ";
    cout << endl;
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