#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 2e18;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    map<ll, ll> mp;
    for(auto u : a) mp[u]++;

    auto solve = [&] (ll sm, ll prd) {
        // x + y = sm
        // x * y = prd
        // x * (sm - x) = prd
        // is it guaranteed that we would always find a valid x? no 
        // so binary search on x since the function is not monotonic
        // we will do BS from -1e9 to the middle of the function
        // which is sm / 2 if we find a valid pair we return if not return -1

        ll lo = -2e9; ll hi = sm/2;
        while(lo < hi) {
            ll mid = lo + (hi - lo)/2;
            if(mid * (sm - mid) >= prd) hi = mid;
            else lo = mid + 1;
        }

        if(lo * (sm - lo) == prd) return lo;
        else return INF;
    };

    ll q; cin >> q;
    while(q--) {
        ll x, y; cin >> x >> y;
        // each x and y give us the possible value of the pair a and b
        // mp[a] * mp[b] this would be the count
        if(solve(x, y) == INF) cout << 0 << " ";
        else {
            ll l = solve(x, y), r = x - l;
            if(l != r) cout << mp[l] * mp[r] << " ";
            else cout << (mp[l] * (mp[l] - 1)) / 2 << " ";
        }
    }
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