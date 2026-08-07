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

    if(k > n - 2) {
        cout << -1 << endl;
        return;
    }

    ll runs = n - k;
    ll cnt0 = (n + 1) / 2, cnt1 = n / 2;
    for (ll i = 0; i < runs - 2; i++) {
        if(i & 1) cnt1--;
        else cnt0--;
    }
    for (ll i = 0; i < cnt0; i++)
    {
        cout << "0";
    }
    for (ll i = 0; i < cnt1; i++)
    {
        cout << "1";
    }
    for (ll i = 0; i < runs - 2; i++) {
        if(i & 1) cout << "1";
        else cout << "0";
    }
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