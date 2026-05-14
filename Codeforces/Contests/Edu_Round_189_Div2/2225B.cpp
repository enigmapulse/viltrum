#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    string s; cin >> s;
    ll n = s.size();

    {
        ll l1 = 0, r1 = n - 1;
        for (ll i = 0; i < n; i++) {
            if(i % 2 != s[i] - 'a') {l1 = i; break;}
        }
        for (ll i = n - 1; i >= 0; i--) {
            if(i % 2 != s[i] - 'a') {r1 = i; break;}
        }

        bool chk1 = true;
        for (ll i = l1; i <= r1; i++) {
            if(i % 2 != s[l1 + r1 - i] - 'a') {chk1 = false; break;}
        }

        bool chk2 = true;
        for (ll i = l1; i <= r1; i++) {
            if(i % 2 != ('a' + 'b' - s[l1 + r1 - i]) - 'a') {chk2 = false; break;}
        }
        
        if(chk1 || chk2) {
            cout << "YES" << endl;
            return;
        }
    }

    {
        ll l1 = 0, r1 = n - 1;
        for (ll i = 0; i < n; i++) {
            if( ((i % 2) ^ 1) != (s[i] - 'a') ) {l1 = i; break;}
        }
        for (ll i = n - 1; i >= 0; i--) {
            if( ((i % 2) ^ 1) != (s[i] - 'a') ) {r1 = i; break;}
        }

        bool chk1 = true;
        for (ll i = l1; i <= r1; i++) {
            if(((i % 2) ^ 1) != s[l1 + r1 - i] - 'a') {chk1 = false; break;}
        }

        bool chk2 = true;
        for (ll i = l1; i <= r1; i++) {
            if(((i % 2) ^ 1) != ('a' + 'b' - s[l1 + r1 - i]) - 'a') {chk2 = false; break;}
        }
        
        if(chk1 || chk2) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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