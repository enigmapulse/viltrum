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

    map<ll, vector<ll>> mp;
    for (ll i = 0; i < s.size(); ++i) mp[s[i]].push_back(i);
    stack<ll> idx; idx.push(-1); ll curr = 0;
    stack<ll> ans;

    ll q; cin >> q;
    while(q--) {
        string op; cin >> op;
        if(op == "pop") {
            idx.pop(); ll curr = idx.top();
            ans.pop();
            if(ans.empty() || ans.top()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            char c; cin >> c;
            if(!ans.empty() && ans.top() == 0) {
                cout << "NO" << endl;
                ans.push(0);idx.push(idx.top());
                continue;
            }

            ll curr = idx.top();
            auto it = upper_bound(all(mp[c]), curr);
            if(it == mp[c].end()) {
                cout << "NO" << endl;
                ans.push(0);
                idx.push(curr);
            }
            else {
                cout << "YES" << endl;
                ans.push(1);
                idx.push(*it);
            }
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