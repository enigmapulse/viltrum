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

    vector<ll> mex(n, 0), nextmex(n, 0); vector<vector<ll>> a(n);
    map<ll, ll> freq; ll k = 0;
    ll pos = 0, neg = 0;

    for (ll i = 0; i < n; i++) {
        ll m; cin >> m; k += m;
        vector<ll> b(m); map<ll, ll> mp;
        for (ll j = 0; j < m; j++) {
            cin >> b[j];
            mp[b[j]]++; freq[b[j]]++;
        }
        
        ll mx = 0;
        for (ll j = 0; j <= m; j++) {
            if(mp[j] != 0) mx = j + 1;
            else break;
        }

        ll nxtmx = mx + 1;
        for (ll j = mx + 1; j <= m; j++) {
            if(mp[j] != 0) nxtmx = j + 1;
            else break;
        }
        
        for (ll j = 0; j <= mx; j++) {
            if(mp[j] == 1) {
                neg += (mx - j) * (n - 1);
            }
        }
        
        mex[i] = mx; a[i] = b; nextmex[i] = nxtmx;
    }
    
    for (ll i = 0; i < n; i++) {
        for(auto el : a[i]) freq[el]--;
        pos += freq[mex[i]] * (nextmex[i] - mex[i]);
        for(auto el : a[i]) freq[el]++;            
    }

    ll sm = accumulate(all(mex), 0LL);
    cout << (k * (n - 1) * sm) + pos - neg << endl;
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