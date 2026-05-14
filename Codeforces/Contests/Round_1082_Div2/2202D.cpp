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

    if(k < n || k >= 2 * n) {
        cout << "NO" << endl;
        return;
    }
    
    vector<ll> ans; ans.reserve(2 * n);
    
    // ans for the 2n - 1 case
    auto base = [&] (ll n) {
        if (n == 1) return vector<ll>{1, 1};
        vector<ll> rev = {1, 2}; rev.reserve(2 * n);
        ll f = 1, s = 2;
        while(s != n) {
            s++;
            rev.push_back(s);
            rev.push_back(f);
            f++;
        }
        rev.push_back(f);
        rev.push_back(s);
        reverse(all(rev));
        return rev;
    };

    // build for the general case
    ll cn = n, ck = k;
    while(true) {
        if(ck == 2 * cn - 1) {
            for(auto x : base(cn)) ans.push_back(x);
            break;
        }
        else {
            ans.push_back(cn);
            ans.push_back(cn);
            cn--; ck--;
        }
    }

    cout << "YES" << endl;
    reverse(all(ans));
    for(auto x : ans) cout << x << " ";
    cout << endl;
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