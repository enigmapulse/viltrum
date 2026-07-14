#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    map<ll, ll> mp;
    for(auto x : a) mp[x]++;

    vector<pll> best;
    for(ll i = 1; i <= n; i++) best.push_back({mp[i], n + 1 - i});
    sort(all(best));
    vector<ll> b; b.reserve(n);
    for(auto [_, val] : best) {
        b.push_back(val);
    }

    vector<ll> perm(n);
    for (ll i = 0; i < n; i++) {
        if(b.back() + a[i] != n + 1) {
            perm[i] = b.back();
            b.pop_back();
        }
        else {
            if(b.size() == 1) {
                cout << -1 << endl;
                return;
            }
            perm[i] = b[b.size() - 2];
            b[b.size() - 2] = b.back();
            b.pop_back();
        }
    }
    for(auto x : perm) cout << x << " ";
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