#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    deque<ll> ans; ans.push_back(1);
    bool flip = true;
    for (ll i = 1; i < n; i++) {
        if(flip) ans.push_back(i + 1);
        else ans.push_front(i + 1);
        if(s[i] == 'o') flip ^= 1;
    }
    
    if(!flip) reverse(all(ans));
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