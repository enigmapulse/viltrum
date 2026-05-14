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
    vector<ll> tot(10, 0); for(auto ch : s) tot[ch - '0']++;

    ll sm = 0;
    for (ll i = 0; i < 10; i++) {
        sm += tot[i] * i;
    }

    function<ll(ll, vector<ll>&)> sod = [&] (ll num, vector<ll>& take) {
        if(num < 10) {
            take[num]++;
            return num;
        }
        else {
            ll x = 0;
            while(num > 0) {
                x += num % 10;
                take[num % 10]++;
                num = num / 10;
            }
            return x + sod(x, take);
        }
    };

    ll ans = 0;
    for (ll x = 0; x <= 9 * (s.size()); x++) {
        vector<ll> f(10, 0);
        ll curr = sod(x, f);

        bool chk = true; ll rem = 0;
        for (ll i = 0; i < 10; i++) {
            if(f[i] > tot[i]) chk = false;
            rem += i * (tot[i] - f[i]);
        }
        if(chk && rem == x) {ans = x; break;}
    }

    string t;
    while(ans > 10) {
        t += to_string(ans);
        ll temp = 0;
        while(ans > 0) {
            
        }
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