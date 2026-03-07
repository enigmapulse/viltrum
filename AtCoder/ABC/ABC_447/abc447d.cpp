#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s; cin >> s;

    set<ll> a, b, c;
    for(ll i = 0; i < s.size(); ++i) {
        if(s[i] == 'A') a.insert(i); 
        if(s[i] == 'B') b.insert(i); 
        if(s[i] == 'C') c.insert(i); 
    }

    ll cnt = 0;
    while(true) {
        if(a.empty() || b.empty() || c.empty()) break;
        auto it = a.begin();
        auto ut = b.lower_bound(*it);
        if(ut == b.end()) break;
        auto wt = c.lower_bound(*ut);
        if(wt == c.end()) break;
        cnt++;
        a.erase(it);
        b.erase(ut);
        c.erase(wt);
    }

    cout << cnt << endl;
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