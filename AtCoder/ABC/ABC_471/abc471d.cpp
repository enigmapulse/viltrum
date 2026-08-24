#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, v; cin >> n >> v;
    priority_queue<ll> pq;
    for (ll i = 0; i < n; i++) {
        ll type; cin >> type;
        if(type == 1) {
            ll t, c; cin >> t >> c;
            pq.push(c - t);
        }
        else {
            ll t; cin >> t;
            if(pq.empty()) cout << -1 << endl;
            else {
                cout << min(v, pq.top() + t) << endl;
                pq.pop();
            }
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