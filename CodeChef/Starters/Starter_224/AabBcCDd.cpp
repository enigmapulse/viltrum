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
    string s; cin >> s;
    
    map<char, ll> mp;
    for(auto ch : s) mp[tolower(ch)]++;

    vector<ll> v;
    for(auto [ch, cnt] : mp) {
        v.push_back(cnt);
    }
    sort(all(v));

    // for(auto x : v) cerr << x << " ";
    // cerr << endl;

    if(v.size() == 1) {
        cout << v[0] << endl;
    }
    else cout << v[v.size() - 1] + v[v.size() - 2] << endl;
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