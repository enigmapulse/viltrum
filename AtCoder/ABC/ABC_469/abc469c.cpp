#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    
    vector<ll> cnt0(n, 0);
    vector<ll> cnt1(n, 0);
    for (ll i = 0; i < n; i++) {
        cnt0[i] = (s[i] == 'o');
        cnt1[i] = (s[i] == 'x');
        if(i == 0) continue;
        cnt0[i] += cnt0[i - 1];
        cnt1[i] += cnt1[i - 1];
    }
    
    for (ll i = 0; i < n; i++) {
        ll hits = cnt0[i];
        auto it = lower_bound(all(cnt1), cnt1[i] + cnt0[i]);
        cout << min(it - cnt1.begin() + 1ll, n) << endl;
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