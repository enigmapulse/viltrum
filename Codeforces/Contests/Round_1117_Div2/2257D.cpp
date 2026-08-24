#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
#define F first
#define S second

using namespace std;

bool multipleTests = true;

void solve() {
    ll S, t; cin >> S >> t;

    vector<pll> div;
    for (ll i = 1; i * i <= S; i++) {
        ll q = S / i;
        if(q * i != S) continue;
        div.push_back({i, q});
        if(i != q) div.push_back({q, i});
    }
    sort(all(div));
    div.push_back({0, 0});

    vector<pll> diff;
    for (ll i = 0; i < div.size() - 1; i++) {
        ll dif = div[i].S - div[i + 1].S;
        if(dif) diff.push_back({div[i].F, dif});
    }
    reverse(all(diff));

    vector<ll> pre_diff(diff.size(), 0ll), cnt(diff.size(), 0ll);
    for (ll i = 0; i < diff.size(); i++) {
        pre_diff[i] = diff[i].F * diff[i].S;
        cnt[i] = diff[i].S;
        if(i != 0) {
            pre_diff[i] += pre_diff[i - 1];
            cnt[i] += cnt[i - 1];
        }
    }
    
    while(t--) {
        ll x, y; cin >> x >> y;

        // idx till which just lower than l
        ll lo = 0, hi = cnt.size() - 1;
        int L = -1;
        while(lo <= hi) {
            ll mid = lo + (hi - lo)/2;
            if(cnt[mid] <= y) {
                lo = mid + 1;
                L = mid;
            }
            else hi = mid - 1;
        }
        
        ll sm = (L >= 0 ? pre_diff[L] : 0);
        ll rem = y - (L >= 0 ? cnt[L] : 0);
        ll last = L + 1;
        if(last != diff.size()) {
            sm += rem * diff[last].F;
        }

        // now remove those which are higher than r
        hi = min((ll)diff.size() - 1ll, last), lo = 0;
        ll M = -1;
        while(lo <= hi) {
            ll mid = lo + (hi - lo)/2;
            if(diff[mid].F >= x) {lo = mid + 1; M = mid;}
            else hi = mid - 1;
        }
        if(M != -1) {
            if(M == last) sm = x * y;
            else sm = (sm - pre_diff[M] + cnt[M] * x);
        }
        cout << sm << endl; 
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