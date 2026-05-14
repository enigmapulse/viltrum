#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e15;

using namespace std;

const ll MAXN = 500005;
const ll K = 20;
ll st[MAXN][K];
ll logs[MAXN];

void build(ll n, const vector<ll> &a) {
    logs[1] = 0;
    for (ll i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
    for (ll i = 0; i < n; i++) st[i][0] = a[i];
    for (ll j = 1; j < K; j++) {
        for (ll i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll query(ll L, ll R) {
    ll j = logs[R - L + 1];
    return max(st[L][j], st[R - (1 << j) + 1][j]);
}

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> idxs(n + 1);
    for(ll i = 0; i < n; i++) idxs[a[i]] = i;

    build(n, a);
    
    function<ll(ll, ll)> recur = [&] (ll l, ll r) {
        if(r - l < 2) return 0LL;
        ll mx = query(l, r);
        ll idx = idxs[mx];
        ll choice1 = idx - l + recur(idx + 1, r);
        ll choice2 = r - idx + recur(l, idx - 1);
        return min(choice1, choice2);
    };

    cout << recur(0, n - 1) << endl;
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