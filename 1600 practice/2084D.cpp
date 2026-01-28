#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll block_len = n/(m + 1);
    
    vector<ll> ans(n, 0);
    ll block_start = 0;
    while(block_len && block_start < n) {
        for (ll i = 0; i < block_len && i + block_start < n; i++) ans[i + block_start] = i;
        block_start += max(k, block_len);
    }

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