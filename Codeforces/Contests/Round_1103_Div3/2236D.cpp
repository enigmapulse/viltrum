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
    vector<ll> a(n); inarr(a, n);
    vector<ll> st(n + 1, 0);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) mp[a[i]]++;
    ll win = 0, lose = 0;
    for (ll i = n; i >= 0; i--) {
        if(i + k + 1 < n + 1) {
            if(st[i + k + 1] == 0) lose--;
            else win--;
        }
        if(!mp.contains(i)) {
            st[i] = 0;
            lose++;
            continue;
        }
        else {
            if(mp[i] & 1) {
                if(win == 0) {st[i] = 1; win++;}
                else {st[i] = 0; lose++;} 
            }
            else {st[i] = 0; lose++;}
        }
    }
    
    for (ll i = 0; i < n; i++) {
        if(st[a[i]] == 0) {
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