#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, x; cin >> n >> m >> x;
    set<ll> s; s.insert(x - 1);

    for (ll i = 0; i < m; i++) {
        ll d; char ch; cin >> d >> ch;
        set<ll> ns;
        for(auto start : s) {
            if(ch == '0') ns.insert((start + d) % n);
            else if(ch == '1') ns.insert((start - d + n) % n);
            else {
                ns.insert((start + d) % n);
                ns.insert((start - d + n) % n);
            }
        }
        s = ns;
    }
    
    cout << s.size() << endl;
    for(auto x : s) cout << x + 1 << " ";
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