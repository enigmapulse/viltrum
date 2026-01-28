#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    string s, t; cin >> s >> t;

    multiset<ll> st;
    for(auto ch : t) st.insert(ch);
    bool chk = true;
    for (ll i = 1; i < s.size(); i++) {
        if('A' <= s[i] && s[i] <= 'Z') {
            auto it = st.find(s[i - 1]);
            chk &= (it != st.end());
        }
    }
    if(chk) cout << "Yes" << endl;
    else cout << "No" << endl;
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