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
    ll x = 0, y = 0, z = 0, w = 0, p = 0;
    for(auto ch : s) {
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') x++;
        else if (ch == 'Y') y++;
        else if(ch == 'N') z++;
        else if(ch == 'G') w++;
        else p++;
    }

    ll base = min(x, p / 2);
    ll extra = 0;
    x -= base; p -= base * 2;
    for (ll vowels = x; vowels <= x + y; vowels++) {
        for (ll bigc = 0; bigc <= min(z, w); bigc++) {
            ll c = p + z + w - 2 * bigc + (y - (vowels - x));
            // try mapping as many bigc as possible with vowels
            ll t = min(bigc / 2, vowels);
            ll curr = t * 5;
            ll rem_bigc = bigc - 2 * t;
            ll rem_vowels = vowels - t;
            ll c4 = min(rem_bigc, c);
            ll t2 = min(c4, rem_vowels);
            curr += t2 * 4;
            c -= t2;
            rem_bigc -= t2;
            rem_vowels -= t2;
            extra = max(extra, curr + min(rem_vowels, c / 2) * 3);
        }
    }
    
    cout << base * 3 + extra << endl;
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