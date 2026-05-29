#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

ll floor_div(ll a, ll b) {
    return a >= 0 ? a / b : (a - b + 1) / b;
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    struct block {
        ll sz, sum;
    };
    vector<block> st;

    for (ll i = 0; i < n; i++) {
        ll val = a[i] - i;
        block curr = {1, val};

        while(!st.empty()) {
            block prev = st.back();
            if(prev.sum * curr.sz > curr.sum * prev.sz) {
                curr.sz += prev.sz;
                curr.sum += prev.sum;
                st.pop_back();
            } else break;
        }
        st.push_back(curr);
    }
    
    vector<ll> b; 
    for(auto [cnt, sum] : st) {
        for (ll i = 0; i < cnt; i++) {
            b.push_back(floor_div(sum + i, cnt));
        }
    }

    ll cost = 0;
    for (ll i = 0; i < n; i++) {
        cost += (n - i) * (a[i] - i - b[i]);
    }
    cout << cost << endl;
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