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
    vector<ll> a(n); inarr(a, n);

    vector<ll> cnt(1001, 0);
    for(auto x : a) cnt[x]++;

    ll val = 0;
    ll mx = *max_element(all(cnt));
    for(ll i = 1; i <= 1000; i++) if(cnt[i] == mx) val = i;

    ll diff = max(2 * mx - n - 2, 0ll);
    cout << accumulate(all(a), 0ll) - diff * val << endl;
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