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
    vector<ll> cards(k); iota(all(cards), 1);
    reverse(all(cards));
    vector<ll> cnt(n, 0);
    for (ll i = 0; i < k; i++) {
        ll q = i / n, r = i % n;
        if(q % 2 == 0) cnt[r] += cards[i];
        else cnt[n - 1 - r] += cards[i];
    }
    cout << *max_element(all(cnt)) << endl;
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