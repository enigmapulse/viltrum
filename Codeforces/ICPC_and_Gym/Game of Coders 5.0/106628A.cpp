#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

struct BIT {
    ll sz; vector<ll> bit;

    BIT(ll n) {
        sz = n;
        bit.assign(n + 1, 0);
    }

    void update(ll idx, ll val) {
        while (idx <= sz) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll sum(ll idx) {
        ll pref_sm = 0;
        while(idx >= 1) {
            pref_sm += bit[idx];
            idx -= idx & -idx;
        }
        return pref_sm;
    }
};

bool multipleTests = true;

void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n + 1); inarr(a, n);

    // next and previous greater element index
    vector<ll> nge(n + 1, n + 1), pge(n + 1, 0);

    stack<pll> st; 
    ll idx = 1;
    while (idx <= n) {
        while(!st.empty() && st.top().first < a[idx]) {
            nge[st.top().second] = idx;
            st.pop();
        }
        if(!st.empty()) pge[idx] = st.top().second;
        st.push({a[idx], idx});
        idx++;
    }

    // group pge for all elements with same nge
    vector<vector<ll>> L_at_R(n + 1);
    for (ll i = 1; i <= n; i++) {
        if (nge[i] <= n && pge[i] > 0) {
            L_at_R[nge[i]].push_back(pge[i]);
        }
    }
    
    // group l for all queries with same r
    vector<vector<pll>> query_at_r(n + 1);
    for (ll i = 0; i < q; i++) {
        ll l, r; cin >> l >> r;
        query_at_r[r].push_back({l, i});
    }

    // to find the left values that are >= l
    BIT left(n);

    // to store answers for each query
    vector<ll> ans(q);
    for (ll right = 1; right <= n; right++) {
        // activate all the pge with this nge
        for(auto L : L_at_R[right]) {
            left.update(L, 1);
        }

        // answer all queries ending at this value
        for(auto [l, idx] : query_at_r[right]) {
            ll tot = right - l + 1;
            ll destroyed = left.sum(n) - left.sum(l - 1);
            ans[idx] = tot - destroyed;
        }
    }
    
    for(auto val : ans) {
        cout << val << endl;
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