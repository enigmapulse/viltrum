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
    vector<string> v(n); inarr(v, n);

    string ans;
    for(auto str : v) {
        ans += str; ans += " ";
    }

    ll ops; cin >> ops;
    string s; ll toggle = 0;
    for (ll i = 0; i < ops; i++) {
        string t; cin >> t;
        if(t == "CapsLock") toggle ^= 32;
        else if (t == "Backspace") {
            if(!s.empty()) s.pop_back();
        }
        else if(t == "Space") s += " ";
        else {
            char c = t[0];
            c ^= toggle;
            s += c;
        }
    }
    s += " ";
    
    if (s == ans) cout << "Correct";
    else cout << "Incorrect";
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