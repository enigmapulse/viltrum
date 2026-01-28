#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    vector<pair<ll, ll>> blocks;
    ll idx = 0;
    while (idx < n) {
        if(s[idx] == '1') {
            ll end = idx;
            while (end < n && s[end] == '1') ++end;
            if(s[end] == '0') end--;
            if(end == n) end--;
            blocks.push_back({idx, end});
            idx = end + 1;
        }
        else idx++;
    }
    
    ll r = blocks[k - 1].second;
    ll l = blocks[k - 2].second + 1;

    for (ll i = 0; i < l; i++)
    {
        cout <<s[i];
    }
    for (ll i = r; i >= l; i--)
    {
        cout << s[i];
    }
    for (ll i = r + 1; i < n; i++)
    {
        cout << s[i];
    }
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