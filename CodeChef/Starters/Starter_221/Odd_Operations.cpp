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
    if(n & 1) {
        cout << 0 << endl;
        return;
    }

    ll odd = 0;
    string s = to_string(n);
    for(auto ch : s) if((ch - '0') & 1) odd++;
    if(odd) {
        cout << 1 << endl;
        return;
    }

    // all even numbers
    if(s.size() == 1) {
        cout << -1 << endl;
        return;
    }

    bool flag = false;
    for (ll i = 0; i < s.size(); i++) {
        if(s[i] > s[s.size() - 1]) flag = true;
    }
    
    if(flag) cout << 2 << endl;
    else cout << 3 << endl;
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