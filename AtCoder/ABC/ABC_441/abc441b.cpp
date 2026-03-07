#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m; cin >> n >> m;
    string s; cin >> s;
    string t; cin >> t;

    ll q; cin >> q;
    while(q--) {
        string u; cin >> u;
        bool chk1 = true;
        bool chk2 = true;
        for(auto ch : u) {
            bool v = false;
            for(auto c : s) {
                v |= (c == ch);
            }
            chk1 = chk1 & v;
        }
        for(auto ch : u) {
            bool v = false;
            for(auto c : t) {
                v |= (c == ch);
            }
            chk2 = chk2 & v;
        }

        if(chk1 && !chk2) {
            cout << "Takahashi" << endl;
        }
        else if(chk2 && !chk1) {
            cout << "Aoki" << endl;
        }
        else cout << "Unknown" << endl;
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