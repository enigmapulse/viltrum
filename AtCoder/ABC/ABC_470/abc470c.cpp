#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n + 1, 0);

    map<ll, ll> cnt;
    for (ll i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    ll curr = 0;
    stack<ll> prev;
    ll p = 0;

    while (q--) {
        ll type; cin >> type;
        if(type == 1) {
            ll idx; cin >> idx;
            curr = curr ^ (a[idx]) ^ (a[idx] + 1);
            a[idx]++;
            if(a[idx] > 1) {
                p = p ^ (a[idx] - 2) ^ (a[idx] - 1);
                prev.push(p);
            }
            cout << curr << endl;
        }
        else {
            if(prev.empty()) curr = 0;
            else {
                curr = prev.top();
                prev.pop();
            }
            cout << curr << endl;
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