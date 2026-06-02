#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, x, s; cin >> n >> x >> s;
    string t; cin >> t;
    ll rem = 0, table = x; ll cnt = 0;
    map<pair<ll, pair<ll, ll>>, ll> mp;
    function<ll(ll, ll, ll)> f = [&] (ll i, ll table, ll rem) {
        if(mp.contains({i, {table, rem}})) return mp[{i, {table, rem}}];
        if(i == n) return 0ll;
        if(t[i] == 'I') {
            if (table > 0) return mp[{i, {table, rem}}] = (1 + f(i + 1, table - 1, rem + s - 1));
            else return mp[{i, {table, rem}}] = (f(i + 1, table, rem));
        }
        else if(t[i] == 'E') {
            if(rem > 0) return mp[{i, {table, rem}}] = (1 + f(i + 1, table, rem - 1));
            else return mp[{i, {table, rem}}] = f(i + 1, table, rem);
        }
        else if(t[i] == 'A') {
            return mp[{i, {table, rem}}] = 1 + max((rem > 0 ? f(i + 1, table, rem - 1) : 0ll), (table > 0 ? f(i + 1, table - 1, rem + s - 1) : 0ll));
        }
    };
    cout << f(0, table, rem) << endl;
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