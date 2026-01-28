#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

class range {
public:
    ll x, y;

    range(ll m = 0, ll n = 0) {
        x = m;
        y = n;
    }

    range join(const range& b) const {
        ll c = max(x, b.x);
        ll d = min(y, b.y);
        return range(c, d);
    }

    bool isVal() const {
        return x <= y;
    }

    bool operator<(const range& other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

void solve() {
    ll n; cin >> n;

    vector<range> ranges; 
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        ranges.push_back(range(x, y));
    }

    set<ll> ans; sort(all(ranges)); range curr = ranges[0];
    for (ll i = 1; i < n; i++) {
        range ncurr = curr.join(ranges[i]);
        if(ncurr.isVal()) curr = ncurr;
        else {
            ans.insert(curr.x);
            curr = ranges[i];
        }
    }
    ans.insert(curr.x);
    
    cout << ans.size() << endl;
    for(auto ver : ans) cout << ver << " ";
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