#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s, t; cin >> s >> t;
    s += 'z'; t += 'z';

    string a, b;
    vector<ll> ns, nt;
    ll curr = 0;
    for(auto ch : s) {
        if(ch != 'A') {
            ns.push_back(curr);
            curr = 0;
            a += ch;
        }
        else curr++;
    }

    curr = 0;
    for(auto ch : t) {
        if(ch != 'A') {
            nt.push_back(curr);
            curr = 0;
            b += ch;
        }
        else curr++;
    }

    if(a != b) cout << -1 << endl;
    else {
        ll sm = 0;
        for(ll i = 0; i < ns.size(); ++i) {
            sm += abs(ns[i] - nt[i]);
        }
        cout << sm << endl;
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