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
    string s; cin >> s;

    if (is_sorted(all(s))) {
        cout << "Bob\n";
        return;
    }

    cout << "Alice\n";

    ll zeros = count(all(s), '0');
    vector<ll> moves;
    for (ll i = 0; i < n; i++) {
        if (i < zeros) {
            if (s[i] == '1') moves.push_back(i + 1);
        } else {
            if (s[i] == '0') moves.push_back(i + 1);
        }
    }

    cout << moves.size() << endl;
    for (ll i = 0; i < moves.size(); i++) {
        cout << moves[i] << (i == moves.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}