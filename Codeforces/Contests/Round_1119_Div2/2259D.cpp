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

    ll cnt0 = 0;
    for(auto x : a) {
        cnt0 += (x == 0);
    }

    if(cnt0 == 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    if(cnt0 == 0) {
        for (ll i = 0; i < n; i++) {
            cout << "A";
        }
        cout << endl;
        return;
    }
    string ans = "";
    for(auto x : a) {
        if(x == 0) ans += 'A';
        else ans += 'C';
    }
    for (ll i = 0; i < n; i++) {
        if(ans[i] == 'A') {ans[i] = 'B'; break;}
    }
    cout << ans << endl;
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