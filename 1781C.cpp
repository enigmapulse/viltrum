#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n; string s; cin >> s;
    
    vector<pair<ll, char>> mp(26);
    for(char x = 'a'; x <= 'z'; ++x) mp[x - 'a'].second = x;
    for(auto ch : s) mp[ch - 'a'].first++;
    sort(all(mp), greater());

    ll ans = 1e12, chosen_freq = 0;
    for(ll i = 1; i <= n; ++i) {
        if(n % i) continue;
        ll cnt = n / i; 
        if(cnt > 26) continue; 
        
        ll idx = 0; ll sm = 0;
        while(idx < cnt) {
            sm += abs(mp[idx].first - i);
            idx++;
        }
        while(idx < 26) {
            sm += mp[idx].first;
            idx++;
        }
        if(sm < ans) {
            ans = sm;
            chosen_freq = i;
        }
    }
    cout << ans / 2 << endl;

    vector<ll> curr(26, 0);
    vector<bool> val(26, false);
    ll distinct_count = n / chosen_freq;
    for (ll i = 0; i < distinct_count; ++i) {
        val[mp[i].second - 'a'] = true;
    }

    vector<ll> idx;
    for (ll i = 0; i < n; ++i) {
        char c = s[i];
        if (val[c - 'a'] && curr[c - 'a'] < chosen_freq) curr[c - 'a']++;
        else idx.push_back(i);
    }

    ll ptr = 0;
    for (ll i = 0; i < distinct_count; ++i) {
        char chr = mp[i].second;
        while (curr[chr - 'a'] < chosen_freq) {
            s[idx[ptr++]] = chr;
            curr[chr - 'a']++;
        }
    }

    cout << s << endl;
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