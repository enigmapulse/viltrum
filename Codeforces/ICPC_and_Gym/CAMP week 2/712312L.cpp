#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, e; cin >> n >> e;

    stack<ll> st;
    vector<ll> a;
    
    vector<ll> q;
    for (ll i = 0; i < e; i++) {
        string t; cin >> t;
        string str;
        if(t == "IN") {
            cin >> str;
            if(str == "?") q.push_back(-1);
            else q.push_back(stoll(str));
        }
        else {
            q.push_back(0);
        }
    }
    
    set<ll> s;
    for (ll i = 1; i <= n; i++) {
        s.insert(i);
    }
    for(auto x : q) if(x >= 1) s.erase(x);

    for (ll i = 0; i < e; i++) {
        ll qe = q[i];
        if(qe != 0) {
            if(qe == -1) st.push(-1);
            else st.push(qe);
        }
        else {
            if(st.empty()) {
                cout << "invalid" << endl;
                return;
            }
            auto val = st.top();
            st.pop();
            if(val == -1) {
                a.push_back(*s.begin());
                s.erase(s.begin());
            } else {
                a.push_back(val);
            }
        }
    }

    for(auto ch : a) cout << ch <<endl;
    
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